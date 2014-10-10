#include "art_wiz.h"
#include "ui_art_wiz.h"
#include "QDebug"
#include "QSql"
#include "QSqlQuery"
#include "QSqlDatabase"
#include "QDataWidgetMapper"
#include "QDesktopServices"
#include "QDir"
#include "QSet"
#include "QSqlError"
#include "QPixmap"
#include "QDate"
#include "comboboxdelegate.h"
#include "coldel.h"


art_Wiz::art_Wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::art_Wiz)
{
    ui->setupUi(this);
    ui->proceslab->hide();
    ui->proscombo->hide();
    ui->subbut->hide();
    visset();
    swtBpat();
    swtProject("Jinnrise");
    curstatfil = "";
    curartfil = "";
    statc = 0;
    wuser = qgetenv("USERNAME");

    fil = "artist = ";
    fil = fil + "\'" + wuser + "\'";

    ui->usernam->setText("User :"+wuser+"  ");
    epiprp(wuser);
    currow = 10000;
}


void art_Wiz::visset()
{
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->tabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->statfilcombo->addItem("All");
    ui->statfilcombo->addItem("Assigned");
    ui->statfilcombo->addItem("Submit");
    ui->statfilcombo->addItem("Approved");
    ui->statfilcombo->addItem("Rework");
    ui->statfilcombo->addItem("Delay");

}

art_Wiz::~art_Wiz()
{
  delete ui;
}

void art_Wiz::setCurSt()
{
   curstate = " " + proj + "/" + " " + episd + " " + "/" + " " + "Assets" + " " + "/" + " " + "Model";
   ui->curstate->setText(curstate);
}

void art_Wiz::swtProject(QString prj)
{
    proj = prj;
    swtEpisd("EP01");
    epipop();

    QString pt = "select proj,dept from puser where artist = ";
    pt= pt + '\"' + wuser + '\"';
    QSqlQuery qry(pt);
    qry.last();
    while (qry.previous())
    {
    curdep = qry.value("dept").toString();
    }

    if (curdep == "anim")
    {
        ui->proceslab->show();
        ui->proscombo->show();
    }
    else
    {
        ui->proceslab->hide();
        ui->proscombo->hide();
    }

    loadAllTabs();
    setCurSt();
    ui->datelab->setText(QDate::currentDate().toString());
    QString qtpth = basepath + proj + "/projimage.png";
    ui->prolab->setPixmap(QPixmap(qtpth));
    ui->prolab->setPixmap(QPixmap(qtpth));
    ui->progressBar->setValue(0);
}

void art_Wiz::swtBpat()
{
    basepath = "S:/intelture/Pipeline/Sched/datab/Test/";
    //baseppath = "S:/intelture/Pipeline";
    baseppath = "S:/intelture/Pipeline";
    //basepath = "/Users/sekhar/Github/dbfiles/";
    //baseppath = "/Users/sekhar/Github/Project/";/
}

void art_Wiz::swtEpisd(QString epsd)
{
   QString pth;
   episd = epsd;
   pth = basepath + proj + "/";
   curdatab = pth + episd + "sced.db";

   swtDatabase(curdatab);
}

void art_Wiz::loadAllTabs()
{

    // asset mod


    if (curdep.toStdString() == "model")
    {
        tb = "asset_mod";
        compnt = "Mod";
    }
    else if (curdep.toStdString() == "rig")
    {
        tb = "asset_rig";
        compnt = "Rig";
    }
    else if (curdep.toStdString() == "anim")
    {
        if (ui->proscombo->currentText().toStdString() == "Previs")
        {
         tb = "shot_prev";
         compnt = "Previs";
        }
        else if (ui->proscombo->currentText().toStdString() == "Blocking")
        {
            tb = "shot_blk";
            compnt = "Blocking";
        }
        else
        {
            tb = "shot_anim";
            compnt = "Animation";
        }

    }
    else if (curdep.toStdString() == "light")
    {
        tb = "shot_light";
        compnt = "Lighting";
    }


    ui->progressBar->setValue(0);
    modgen = new MySubClassedSqlTableModel(this);



    if (curdep == "model" || curdep == "rig" )
    {

    modgen->setTable(tb);
    modgen->setEditStrategy(QSqlTableModel::OnFieldChange);
    modgen->select();
    modgen->setHeaderData(0,Qt::Horizontal,tr("Asset Type"));
    modgen->setHeaderData(1,Qt::Horizontal,tr("Asset Name"));
    modgen->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    modgen->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    modgen->setHeaderData(7,Qt::Horizontal,tr("Status"));
    modgen->sort(0,Qt::AscendingOrder);


    coldel *delg = new coldel(ui->tabv);
    ui->tabv->setItemDelegateForColumn(0,delg);
    ui->tabv->setItemDelegateForColumn(1,delg);
    ui->tabv->setItemDelegateForColumn(2,delg);
    ui->tabv->setItemDelegateForColumn(3,delg);
    ui->tabv->setItemDelegateForColumn(4,delg);
    ui->tabv->setItemDelegateForColumn(5,delg);
    ui->tabv->setItemDelegateForColumn(6,delg);
    ui->tabv->setItemDelegateForColumn(7,delg);

    QSqlQuery st;
   // st.exec("Select name from user where dept = 'Model'");

    fil = "artist = ";
    fil = fil + "\'" + wuser + "\'";
    modgen->setFilter(fil);

    ui->tabv->setModel(modgen);
    ui->tabv->hideColumn(2);
    ui->tabv->hideColumn(3);
    ui->tabv->hideColumn(4);

    ui->tabv->show();

    mapper = new QDataWidgetMapper;
    mapper->setModel(modgen);
    mapper->addMapping(ui->lcCom, 3);
    mapper->addMapping(ui->dcCom, 4);
    mapper->setParent(this);
    }

    else
    {
        modgen->setTable(tb);
        modgen->setEditStrategy(QSqlTableModel::OnFieldChange);
        modgen->select();
        modgen->setHeaderData(0,Qt::Horizontal,tr("Scene"));
        modgen->setHeaderData(1,Qt::Horizontal,tr("Shot"));
        modgen->setHeaderData(2,Qt::Horizontal,tr("Artist"));
        modgen->setHeaderData(6,Qt::Horizontal,tr("End Date"));
        modgen->setHeaderData(7,Qt::Horizontal,tr("Status"));
        modgen->sort(0,Qt::AscendingOrder);


        coldel *delg = new coldel(ui->tabv);
        ui->tabv->setItemDelegateForColumn(0,delg);
        ui->tabv->setItemDelegateForColumn(1,delg);
        ui->tabv->setItemDelegateForColumn(2,delg);
        ui->tabv->setItemDelegateForColumn(3,delg);
        ui->tabv->setItemDelegateForColumn(4,delg);
        ui->tabv->setItemDelegateForColumn(5,delg);
        ui->tabv->setItemDelegateForColumn(6,delg);
        ui->tabv->setItemDelegateForColumn(7,delg);

        QSqlQuery st;
       // st.exec("Select name from user where dept = 'Model'");

        fil = "artist = ";
        fil = fil + "\'" + wuser + "\'";
        modgen->setFilter(fil);

        modgen->setFilter(fil);
        ui->tabv->setModel(modgen);
        ui->tabv->hideColumn(2);
        ui->tabv->hideColumn(3);
        ui->tabv->hideColumn(4);

        ui->tabv->show();

        mapper = new QDataWidgetMapper;
        mapper->setModel(modgen);
        mapper->addMapping(ui->lcCom, 3);
        mapper->addMapping(ui->dcCom, 4);
        mapper->setParent(this);

    }

    ui->progressBar->setValue(100);
}


void art_Wiz::swtDatabase(QString datab)
{
    if (mydb.open())
    {
        mydb.close();
    }

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


void art_Wiz::epipop()
{
    QString pth;
    QDir fld;
    pth = baseppath + "/" + proj + "/" + "03_Production";
    fld.setPath(pth);
    epilist = fld.entryList(epilist,QDir::AllDirs|QDir::NoDotAndDotDot);
    ui->epcombo->addItems(epilist.filter("EP"));
}

void art_Wiz::epiprp(QString tst)
{
    QString pt = "select proj,dept from puser where artist = ";
    pt= pt + '\"' + tst + '\"';
    QSqlQuery qry(pt);
    qry.last();
    curdep = qry.value("dept").toString();
    ui->procombo->addItem(qry.value("proj").toString());
    while (qry.previous())
    {
    ui->procombo->addItem(qry.value("proj").toString());
    }
}

void art_Wiz::on_tabv_clicked(const QModelIndex &index)
{
    currow = index.row();
    curindex = index;
    //mapper->addMapping(ui->dcCom, 4);

    mapper->setCurrentIndex(currow);

    QString selentr = index.sibling(currow,0).data().toString() + ":  " + index.sibling(currow,1).data().toString();

    ui->dcuren->setText(selentr);
    ui->lcuren->setText(selentr);

   /* QString as = "select pvwloc from asset_mas where name = ";
    as = as + "\'" + index.sibling(currow,1).data().toString() + "\'";
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString(); */
    QString ppath;

    if (curdep == "model" || curdep == "rig")
    {
        if (index.sibling(currow,0).data().toString() == "environment")
        {
        ppath = baseppath + "/" + proj + "/" + "03_Production" +"/" + episd  + "/" + "Assets"  + "/" + index.sibling(currow,0).data().toString() + "/" + index.sibling(currow,1).data().toString() + "/" + "components" + "/" + compnt + "/" + "preview.jpg";
        }
        else
        {
        ppath = baseppath + "/" + proj + "/" + "03_Production" +"/" + episd  + "/" + "Assets"  + "/" + index.sibling(currow,0).data().toString()+ "s" + "/" + index.sibling(currow,1).data().toString() + "/" + "components" + "/" + compnt + "/" + "preview.jpg";
        }
    }
    else
    {
    ppath = baseppath + "/" + proj + "/" + "03_Production" +"/" + episd  +  "/" + "Animations"  + "/" + index.sibling(currow,0).data().toString() + "/" + index.sibling(currow,1).data().toString() + "/" + "components" + "/" + compnt + "/" + "preview.jpg";
    }

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    if (index.sibling(currow,7).data().toString() != "Submit" && index.sibling(currow,7).data().toString() != "Approved")
    {
        ui->subbut->show();
    }
    else
    {
        ui->subbut->hide();
    }

    QString dtl = "Date Line : " + index.sibling(currow,6).data().toString();

  //  ui->detLayout->setStyleSheet("background-color: rgb(50, 155, 255);");

    QFile fl(ppath);

    if (fl.exists())
    {
        ui->prevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->prevlab->setPixmap(QPixmap(defpath));
    }

}

void art_Wiz::on_subbut_clicked()
{
    if (currow != 10000 && modgen->data(modgen->index(currow,2)).toString() != "Approved")
    {
    modgen->setData(modgen->index(currow,7),"Submit");
    }

}

void art_Wiz::on_videobut_clicked()
{
    QString as;
    if (curdep.toStdString() == "model" || curdep.toStdString() == "rig")
    {
        as = "select lfloc from asset_mas where type = ";
        as = as + "\'" + curindex.sibling(currow,0).data().toString() + "\'";
        as = as + " and name = " "\'" + curindex.sibling(currow,1).data().toString() + "\'";
    }
    else
    {
        as = "select lfloc from shot_mas where scene = ";
        as = as + "\'" + curindex.sibling(currow,0).data().toString() + "\'";
        as = as + " and shot = " "\'" + curindex.sibling(currow,1).data().toString() + "\'";
    }

    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();
    QUrl url(ppath);

    if (url.isValid())
    {
        QDesktopServices::openUrl(url);
    }
}

void art_Wiz::on_statfilcombo_currentTextChanged(const QString &arg1)
{
    if (arg1.toStdString() == "All")
    {
        curstatfil = "";
    }
    else
    {
        curstatfil = arg1;
    }

    if (curstatfil != "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curstatfil));
    statc = 1;
    }
    else if (statc == 1)
    {
        fil = "artist = ";
        fil = fil + "\'" + wuser + "\'";
        modgen->setFilter(fil);
    }

}

void art_Wiz::on_procombo_currentTextChanged(const QString &arg1)
{
    proj = arg1;
    ui->epcombo->clear();
    ui->statfilcombo->setCurrentIndex(0);
    swtProject(proj);
}

void art_Wiz::on_proscombo_currentTextChanged(const QString &arg1)
{
    loadAllTabs();
    ui->progressBar->setValue(0);
}
