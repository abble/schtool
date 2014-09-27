#include "assign_wiz.h"
#include "ui_assign_wiz.h"
#include "QDebug"
#include "QSql"
#include "QSqlQuery"
#include "QSqlDatabase"
#include "QDataWidgetMapper"

#include "QDir"
#include "QSet"
#include "QSqlError"
#include "QPixmap"
#include "QDate"
#include "comboboxdelegate.h"
#include "coldel.h"
#include "datedelegate.h"

assign_wiz::assign_wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assign_wiz)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(0, 53, 118);");
    ui->modtabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->rigtabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->prevtabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->blktabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->anitabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->lighttabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->modtabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->rigtabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->prevtabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->blktabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->anitabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->lighttabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    swtBpat();
    swtProject("Jinnr");

    ui->asprevlab->setPixmap(QPixmap("S:/intelture/Pipeline/noPreview.png"));
    ui->shprevlab->setPixmap(QPixmap("S:/intelture/Pipeline/noPreview.png"));

    //   setPreviewPan();

}

void assign_wiz::setCurSt()
{
   curstate = " " + proj + "/" + " " + episd + " " + "/" + " " + asbut + " " + "/" + " " + tabbut;
   ui->curstate->setText(curstate);
}

void assign_wiz::swtProject(QString prj)
{
    proj = "Jinnr";
    swtEpisd("EP01");
    epipop();
    asbut = "Assets";
    tabbut = "Model";
    refreshData();
    loadAllTabs();
    setCurSt();
    ui->datelab->setText(QDate::currentDate().toString());
    QString qtpth = baseppath + "/" + proj + "/projimage.png";
    ui->asprolab->setPixmap(QPixmap(qtpth));
    ui->shprolab->setPixmap(QPixmap(qtpth));
}

void assign_wiz::swtEpisd(QString epsd)
{

   QString pth;
   episd = epsd;
   pth = basepath + proj + "/";
   curdatab = pth + episd + "sced.db";

   swtDatabase(curdatab);
}

assign_wiz::~assign_wiz()
{
    delete ui;
}

void assign_wiz::refreshData()
{
    getnasentrs();
    getnshentrs();
}

void assign_wiz::loadAllTabs()
{
    // asset mod

    assetm = new MySubClassedSqlTableModel(this);
    assetm->setTable("asset_mod");
    assetm->setEditStrategy(QSqlTableModel::OnFieldChange);
    assetm->select();
    assetm->setHeaderData(0,Qt::Horizontal,tr("Asset Type"));
    assetm->setHeaderData(1,Qt::Horizontal,tr("Name"));
    assetm->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    assetm->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    assetm->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    assetm->setHeaderData(7,Qt::Horizontal,tr("Status"));
    assetm->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dmodelrs = new ComboBoxDelegate(ui->modtabv);
    ui->modtabv->setItemDelegateForColumn(2,dmodelrs);

    datedelegate *dated = new datedelegate(ui->modtabv);
    ui->modtabv->setItemDelegateForColumn(5,dated);
    ui->modtabv->setItemDelegateForColumn(6,dated);

    ComboBoxDelegate *statdelg = new ComboBoxDelegate(ui->modtabv);
    ui->modtabv->setItemDelegateForColumn(7,statdelg);

    coldel *delg = new coldel(ui->modtabv);
    ui->modtabv->setItemDelegateForColumn(0,delg);
    ui->modtabv->setItemDelegateForColumn(1,delg);


    statdelg->Items.clear();
    statdelg->Items.push_back("Assigned");
    statdelg->Items.push_back("Delay");

    QSqlQuery st;
    st.exec("Select artist from user where dept = 'model'");

    while(st.next())
    {
         dmodelrs->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->modtabv->setModel(assetm);
    ui->modtabv->hideColumn(3);
    ui->modtabv->hideColumn(4);
    ui->modtabv->show();


    // asset rig

    assetr = new MySubClassedSqlTableModel(this);
    assetr->setTable("asset_rig");
    assetr->setEditStrategy(QSqlTableModel::OnFieldChange);
    assetr->select();
    assetr->setHeaderData(0,Qt::Horizontal,tr("Asset Type"));
    assetr->setHeaderData(1,Qt::Horizontal,tr("Name"));
    assetr->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    assetr->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    assetr->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    assetr->setHeaderData(7,Qt::Horizontal,tr("Status"));
    assetr->sort(0,Qt::AscendingOrder);



    ComboBoxDelegate *drigers = new ComboBoxDelegate(ui->rigtabv);
    ui->rigtabv->setItemDelegateForColumn(2,drigers);
    ui->rigtabv->setItemDelegateForColumn(5,dated);
    ui->rigtabv->setItemDelegateForColumn(6,dated);
    ui->rigtabv->setItemDelegateForColumn(7,statdelg);
    ui->rigtabv->setItemDelegateForColumn(0,delg);
    ui->rigtabv->setItemDelegateForColumn(1,delg);

    st.exec("Select artist from user where dept = 'rig'");

    while(st.next())
    {
        drigers->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->rigtabv->setModel(assetr);
    ui->rigtabv->hideColumn(3);
    ui->rigtabv->hideColumn(4);
    ui->rigtabv->show();

    // shot prev

    shotp = new MySubClassedSqlTableModel(this);
    shotp->setTable("shot_prev");
    shotp->setEditStrategy(QSqlTableModel::OnFieldChange);
    shotp->select();
    shotp->setHeaderData(0,Qt::Horizontal,tr("Scene"));
    shotp->setHeaderData(1,Qt::Horizontal,tr("Shot"));
    shotp->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    shotp->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    shotp->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    shotp->setHeaderData(7,Qt::Horizontal,tr("Status"));
    shotp->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dprev = new ComboBoxDelegate(ui->prevtabv);
    ui->prevtabv->setItemDelegateForColumn(2,dprev);
    ui->prevtabv->setItemDelegateForColumn(5,dated);
    ui->prevtabv->setItemDelegateForColumn(6,dated);
    ui->prevtabv->setItemDelegateForColumn(7,statdelg);
    ui->prevtabv->setItemDelegateForColumn(0,delg);
    ui->prevtabv->setItemDelegateForColumn(1,delg);

    st.exec("Select artist from user where dept = 'anim'");

    while(st.next())
    {
        dprev->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->prevtabv->setModel(shotp);
    ui->prevtabv->hideColumn(3);
    ui->prevtabv->hideColumn(4);
    ui->prevtabv->show();

    // shot block

    shotb = new MySubClassedSqlTableModel(this);
    shotb->setTable("shot_blk");
    shotb->setEditStrategy(QSqlTableModel::OnFieldChange);
    shotb->select();
    shotb->setHeaderData(0,Qt::Horizontal,tr("Scene"));
    shotb->setHeaderData(1,Qt::Horizontal,tr("Shot"));
    shotb->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    shotb->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    shotb->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    shotb->setHeaderData(7,Qt::Horizontal,tr("Status"));

    shotb->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dblk = new ComboBoxDelegate(ui->blktabv);
    ui->blktabv->setItemDelegateForColumn(2,dblk);
    ui->blktabv->setItemDelegateForColumn(5,dated);
    ui->blktabv->setItemDelegateForColumn(6,dated);
    ui->blktabv->setItemDelegateForColumn(7,statdelg);
    ui->blktabv->setItemDelegateForColumn(0,delg);
    ui->blktabv->setItemDelegateForColumn(1,delg);

    st.exec("Select artist from user where dept = 'anim'");

    while(st.next())
    {
        dblk->Items.push_back(st.value(0).toString().toStdString());
    }


    ui->blktabv->setModel(shotb);
    ui->blktabv->hideColumn(3);
    ui->blktabv->hideColumn(4);
    ui->blktabv->show();

    // shot anim

    shota = new MySubClassedSqlTableModel(this);
    shota->setTable("shot_anim");
    shota->setEditStrategy(QSqlTableModel::OnFieldChange);
    shota->select();
    shota->setHeaderData(0,Qt::Horizontal,tr("Scene"));
    shota->setHeaderData(1,Qt::Horizontal,tr("Shot"));
    shota->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    shota->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    shota->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    shota->setHeaderData(7,Qt::Horizontal,tr("Status"));
    shota->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *danim = new ComboBoxDelegate(ui->anitabv);
    ui->anitabv->setItemDelegateForColumn(2,danim);
    ui->anitabv->setItemDelegateForColumn(5,dated);
    ui->anitabv->setItemDelegateForColumn(6,dated);
    ui->anitabv->setItemDelegateForColumn(7,statdelg);
    ui->anitabv->setItemDelegateForColumn(0,delg);
    ui->anitabv->setItemDelegateForColumn(1,delg);

    st.exec("Select artist from user where dept = 'anim'");

    while(st.next())
    {
        danim->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->anitabv->setModel(shota);
    ui->anitabv->hideColumn(3);
    ui->anitabv->hideColumn(4);
    ui->anitabv->show();

    // shot light

    shotl = new MySubClassedSqlTableModel(this);
    shotl->setTable("shot_light");
    shotl->setEditStrategy(QSqlTableModel::OnFieldChange);
    shotl->select();
    shotl->setHeaderData(0,Qt::Horizontal,tr("Scene"));
    shotl->setHeaderData(1,Qt::Horizontal,tr("Shot"));
    shotl->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    shotl->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    shotl->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    shotl->setHeaderData(7,Qt::Horizontal,tr("Status"));
    shotl->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dlight = new ComboBoxDelegate(ui->lighttabv);
    ui->lighttabv->setItemDelegateForColumn(2,dlight);
    ui->lighttabv->setItemDelegateForColumn(5,dated);
    ui->lighttabv->setItemDelegateForColumn(6,dated);
    ui->lighttabv->setItemDelegateForColumn(7,statdelg);
    ui->lighttabv->setItemDelegateForColumn(0,delg);
    ui->lighttabv->setItemDelegateForColumn(1,delg);

    st.exec("Select artist from user where dept = 'light'");

    while(st.next())
    {
        dlight->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->lighttabv->setModel(shotl);
    ui->lighttabv->hideColumn(3);
    ui->lighttabv->hideColumn(4);
    ui->lighttabv->show();

}

void assign_wiz::setPreviewPan()
{
    QSqlQuery query;

    if (asbut == "asset")
    {
       // QString qery = "select pvwloc from " + "asset_mas" + " Where (type,name) are ";
       // query.exec(qery);
    }
    else
    {
        // QString qery = "select pvwloc from " + asbut + "_" + "mas" + " Where (";
        // query.exec(qery);
    }

   // qDebug() << qery;

    QString pt;
    QPixmap mp(pt);
   // ui->label->setPixmap(mp);
}

void assign_wiz::epipop()
{
    QString pth;
    QDir fld;
    pth = baseppath + "/" + proj + "/" + "03_Production";
    fld.setPath(pth);
    epilist = fld.entryList(epilist,QDir::AllDirs|QDir::NoDotAndDotDot);
    ui->epcombo->addItems(epilist);
}

void assign_wiz::swtDatabase(QString datab)
{
    if (!mydb.isValid())
    {
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    }
    mydb.setDatabaseName(datab);
    if (!mydb.open())
    {
        printf("error");
    }
}


void assign_wiz::swtBpat()
{
    basepath = "S:/intelture/Pipeline/Sched/datab/";
    baseppath = "S:/intelture/Pipeline";
    //basepath = "/Users/sekhar/Github/dbfiles/";
    //baseppath = "/Users/sekhar/Github/Project/";
}

void assign_wiz::getnasentrs()
{
    QDir fld;
    QString pth;
    QStringList ftlist,flist,tlist,fnlist;

    QSqlQuery query(curdatab);
    query.exec("select * from asset_mas");

    while (query.next())
    {
       tlist << query.value(0).toString().toLower() + "_" + query.value(1).toString().toLower();
    }


    pth = baseppath + "/" + proj + "/" + "03_Production" + "/" + episd + "/" + "assets" + "/" + "characters";
    fld.setPath(pth);
    ftlist = fld.entryList(ftlist,QDir::AllDirs|QDir::NoDotAndDotDot);


    QStringListIterator iter(ftlist);

    while (iter.hasNext())
    {

        flist << "character_" + iter.next().toLower();
    }



    pth = baseppath + "/" + proj + "/" + "03_Production" + "/" + episd  + "/" + "assets" + "/" + "Environments";
    fld.setPath(pth);
    ftlist = fld.entryList(ftlist,QDir::AllDirs|QDir::NoDotAndDotDot);

    QStringListIterator iter1(ftlist);

    while (iter1.hasNext())
    {
        flist << "environment_" + iter1.next().toLower();
    }

    pth = baseppath + "/" + proj + "/" + "03_Production" + "/" + episd  + "/" + "assets" + "/" + "Props";
    fld.setPath(pth);
    ftlist = fld.entryList(ftlist,QDir::AllDirs|QDir::NoDotAndDotDot);

    QStringListIterator iter2(ftlist);

    while (iter2.hasNext())
    {
        flist << "prop_" + iter2.next().toLower();
    }


     QSet<QString> comentr = flist.toSet().intersect(tlist.toSet());
     QSet<QString> newentr = flist.toSet().subtract(comentr);
     QSet<QString> delentr = tlist.toSet().subtract(comentr);

     fnlist << newentr.toList();

     QSqlQuery iquery(curdatab);
     QString queryString;
     QStringList val;

     foreach (QString str,fnlist)
     {
         val = str.split("_");
         queryString = "INSERT INTO asset_mas (type,name) VALUES (";
         queryString = queryString + '\"' + val.at(0) + '\"' + "," + '\"' + val.at(1) + '\"' + ")";
         iquery.exec(queryString);

     }
     mydb.commit();


}
void assign_wiz::getnshentrs()
{
    QDir fld;
    QString pth,spth;
    QStringList ftlist,ftslist,flist,tlist,fnlist;

    QSqlQuery query(curdatab);
    query.exec("select * from shot_mas");

    while (query.next())
    {
       tlist << query.value(0).toString().toLower() + "_" + query.value(1).toString().toLower();
    }

    pth = baseppath + "/" + proj + "/" + "03_Production" + "/" + episd + "/" + "Animations";
    fld.setPath(pth);
    ftlist = fld.entryList(ftlist,QDir::AllDirs|QDir::NoDotAndDotDot);

    foreach (QString str,ftlist)
    {
        spth = pth + "/" + str;
        fld.setPath(spth);
        ftslist = fld.entryList(ftslist,QDir::AllDirs|QDir::NoDotAndDotDot);

        QStringListIterator iter(ftslist);

        while (iter.hasNext())
        {
           flist << str.toLower() + "_" + iter.next().toLower();
        }
    }

    QSet<QString> comentr = flist.toSet().intersect(tlist.toSet());
    QSet<QString> newentr = flist.toSet().subtract(comentr);
    QSet<QString> delentr = tlist.toSet().subtract(comentr);

    QSqlQuery iquery(curdatab);
    QString queryString;
    QStringList val;

    fnlist << newentr.toList();

    foreach (QString str,fnlist)
    {
        val = str.split("_");
        queryString = "INSERT INTO shot_mas (scene,shot) VALUES (";
        queryString = queryString + '\"' + val.at(0) + '\"' + "," + '\"' + val.at(1) + '\"' + ")";
        iquery.exec(queryString);
    }
    mydb.commit();


}



void assign_wiz::on_asbut_clicked()
{
    ui->asbut->setChecked(true);
    ui->shbut->setChecked(false);
    ui->stackedWidget->setCurrentIndex(0);
    asbut = "Assets";
    if (ui->astabwidg->currentIndex() == 0)
    {
    tabbut = "Model";
    }
    else
    {
    tabbut = "Rig";
    }
    this->setStyleSheet("background-color: rgb(0, 53, 118);");
    setCurSt();
}

void assign_wiz::on_shbut_clicked()
{
    ui->asbut->setChecked(false);
    ui->shbut->setChecked(true);
    ui->stackedWidget->setCurrentIndex(1);
    asbut = "Shots";
    if (ui->shtabwidg->currentIndex() == 0)
    {
    tabbut = "Previs";
    }
    else if (ui->shtabwidg->currentIndex() == 1)
    {
    tabbut = "Blocking";
    }
    else if (ui->shtabwidg->currentIndex() == 2)
    {
    tabbut = "Animation";
    }
    else
    {
    tabbut = "Lighting"    ;
    }
    this->setStyleSheet("background-color: rgb(0, 58, 35);");
    setCurSt();
}

void assign_wiz::on_astabwidg_currentChanged(int index)
{
    if (index == 0)
    {
        tabbut = "Model";
        setCurSt();
    }
    else
    {
        tabbut = "Rig";
        setCurSt();
    }
}

void assign_wiz::on_shtabwidg_currentChanged(int index)
{
    if (index == 0)
    {
        tabbut = "Previs";
        setCurSt();
    }
    else if (index == 1)
    {
        tabbut = "Blocking";
        setCurSt();
    }
    else if (index == 2)
    {
        tabbut = "Animation";
        setCurSt();
    }
    else if (index == 3)
    {
        tabbut = "Lighting";
        setCurSt();
    }

}

void assign_wiz::on_epcombo_currentIndexChanged(const QString &arg1)
{
    swtEpisd(arg1);
    refreshData();
    loadAllTabs();
}

void assign_wiz::on_modtabv_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString as = "select pvwloc from asset_mas where type = ";
    as = as + "\'" + index.sibling(row,0).data().toString() + "\'" + "and name = " +  "\'" + index.sibling(row,1).data().toString() + "\'";
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    if (QUrl(ppath).isValid())
    {
        ui->asprevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->asprevlab->setPixmap(QPixmap(defpath));
    }
}

void assign_wiz::on_rigtabv_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString as = "select pvwloc from asset_mas where type = ";
    as = as + "\'" + index.sibling(row,0).data().toString() + "\'" + "and name = " +  "\'" + index.sibling(row,1).data().toString() + "\'";
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    if (QUrl(ppath).isValid())
    {
        ui->asprevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->asprevlab->setPixmap(QPixmap(defpath));
    }

}

void assign_wiz::on_prevtabv_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString as = "select pvwloc from shot_mas where scene = ";
    as = as + "\'" + index.sibling(row,0).data().toString()+ "\'"  + " and shot = " + "\'" + index.sibling(row,1).data().toString() + "\'" ;
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    if (QUrl(ppath).isValid())
    {
        ui->shprevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->shprevlab->setPixmap(QPixmap(defpath));
    }
}
