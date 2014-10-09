#include "apr_wiz.h"
#include "ui_apr_wiz.h"
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
#include "datedelegate.h"

apr_Wiz::apr_Wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apr_Wiz)
{

    ui->setupUi(this);
    ui->proceslab->hide();
    ui->proscombo->hide();
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->tabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    swtBpat();
    swtProject("Jinnrise");
    wuser = qgetenv("USERNAME");
   // wuser = "sharil";
    epiprp(wuser);
    ui->userlab->setText("User: " + wuser.toUpper() + "  ");
    currow = 10000;


    ui->statfilcombo->addItem("All");
    ui->statfilcombo->addItem("Assigned");
    ui->statfilcombo->addItem("Submit");
    ui->statfilcombo->addItem("Approved");
    ui->statfilcombo->addItem("Rework");
    ui->statfilcombo->addItem("Delay");
    ui->enddtlab->setText("");
    curstatfil = "";
    curartfil = "";
}

apr_Wiz::~apr_Wiz()
{
    delete ui;
}

void apr_Wiz::setCurSt()
{
   curstate = " " + proj + " /" + " " + episd + " " + "/" + " " + "Assets" + " " + "/" + " " + "Model";
   ui->curstate->setText(curstate);
}

void apr_Wiz::swtProject(QString prj)
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

    loadAllTabs();
    setCurSt();
    ui->datelab->setText(QDate::currentDate().toString());
    QString qtpth = baseppath + "/" + proj + "/projimage.png";
    ui->prolab->setPixmap(QPixmap(qtpth));
    ui->prolab->setPixmap(QPixmap(qtpth));
    ui->progressBar->setValue(0);
}

void apr_Wiz::swtBpat()
{
     basepath = "S:/intelture/Pipeline/Sched/datab/Test/";
    //  baseppath = "S:/intelture/Pipeline";
     baseppath = "S:/intelture/Pipeline";
    //basepath = "/Users/sekhar/Github/dbfiles/";
    //baseppath = "/Users/sekhar/Github/Project/";
}

void apr_Wiz::swtEpisd(QString epsd)
{
   QString pth;
   episd = epsd;
   pth = basepath + proj + "/";
   curdatab = pth + episd + "sced.db";

   swtDatabase(curdatab);
}

void apr_Wiz::loadAllTabs()
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
    modgen->setHeaderData(1,Qt::Horizontal,tr("Artist Name"));
    modgen->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    modgen->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    modgen->setHeaderData(7,Qt::Horizontal,tr("Status"));
    modgen->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dmodelrs = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(2,dmodelrs);

    datedelegate *dated = new datedelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(6,dated);

    ComboBoxDelegate *statdelg = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(7,statdelg);

    coldel *delg = new coldel(ui->tabv);
    ui->tabv->setItemDelegateForColumn(0,delg);
    ui->tabv->setItemDelegateForColumn(1,delg);
    ui->tabv->setItemDelegateForColumn(2,delg);
    ui->tabv->setItemDelegateForColumn(3,delg);

    ui->tabv->setItemDelegateForColumn(7,delg);

    statdelg->Items.clear();
    ui->artfilcombo->clear();
    ui->artfilcombo->addItem("All");

    QSqlQuery st;
    QString qr;
    qr = "Select artist from puser where dept ";
    qr = qr + "=" + "\'" + curdep + "\'" + " and " + "proj"+ " = " + "\'" + proj + "\'";

    st.exec(qr);
    mdrs.clear();
    while(st.next())
    {
        dmodelrs->Items.push_back(st.value(0).toString().toStdString());
        mdrs.append(st.value(0).toString());
    }
    ui->artfilcombo->addItems(mdrs);

    ui->tabv->setModel(modgen);
    ui->tabv->hideColumn(3);
    ui->tabv->hideColumn(4);
    ui->tabv->hideColumn(5);
   // ui->tabv->hideColumn(6);
    //ui->tabv->hideColumn(8);
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

        ComboBoxDelegate *dmodelrs = new ComboBoxDelegate(ui->tabv);
        ui->tabv->setItemDelegateForColumn(2,dmodelrs);

        datedelegate *dated = new datedelegate(ui->tabv);
        ui->tabv->setItemDelegateForColumn(6,dated);

        ComboBoxDelegate *statdelg = new ComboBoxDelegate(ui->tabv);
        ui->tabv->setItemDelegateForColumn(7,statdelg);

        coldel *delg = new coldel(ui->tabv);
        ui->tabv->setItemDelegateForColumn(0,delg);
        ui->tabv->setItemDelegateForColumn(1,delg);
        ui->tabv->setItemDelegateForColumn(2,delg);
        ui->tabv->setItemDelegateForColumn(3,delg);

        ui->tabv->setItemDelegateForColumn(7,delg);

        statdelg->Items.clear();
        ui->artfilcombo->clear();
        ui->artfilcombo->addItem("All");

        QSqlQuery st;
        QString qr;
        qr = "Select artist from puser where dept ";
        qr = qr + "=" + "\'" + curdep + "\'" + " and " + "proj"+ " = " + "\'" + proj + "\'";

        st.exec(qr);
        mdrs.clear();
        while(st.next())
        {
            dmodelrs->Items.push_back(st.value(0).toString().toStdString());
            mdrs.append(st.value(0).toString());
        }
        ui->artfilcombo->addItems(mdrs);

        ui->tabv->setModel(modgen);
        ui->tabv->hideColumn(3);
        ui->tabv->hideColumn(4);
        ui->tabv->hideColumn(5);
       // ui->tabv->hideColumn(6);
        //ui->tabv->hideColumn(8);
        ui->tabv->show();


        mapper = new QDataWidgetMapper;
        mapper->setModel(modgen);
        mapper->addMapping(ui->lcCom, 3);
        mapper->addMapping(ui->dcCom, 4);
        mapper->setParent(this);
    }
    ui->progressBar->setValue(100);
}

void apr_Wiz::swtDatabase(QString datab)
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


void apr_Wiz::epipop()
{
    QString pth;
    QDir fld;
    pth = baseppath + "/" + proj + "/" + "03_Production";
    fld.setPath(pth);

    epilist = fld.entryList(epilist,QDir::AllDirs|QDir::NoDotAndDotDot);
    ui->epcombo->addItems(epilist.filter("EP"));
}

void apr_Wiz::epiprp(QString tst)
{
    QString pt = "select proj,dept from puser where artist = ";
    pt= pt + '\"' + tst + '\"';
    QSqlQuery qry(pt);
    qry.last();
    ui->procombo->addItem(qry.value("proj").toString());
    while (qry.previous())
    {
    curdep = qry.value("dept").toString();
    ui->procombo->addItem(qry.value("proj").toString());
    }

}

void apr_Wiz::on_tabv_clicked(const QModelIndex &index)
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

    ui->enddtlab->setText("End Date : " + index.sibling(currow,6).data().toString());

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    QFile fl(ppath);

  //  ui->detLayout->setStyleSheet("background-color: rgb(50, 155, 255);");

    if (fl.exists())
    {
        ui->prevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->prevlab->setPixmap(QPixmap(defpath));
    }
}

void apr_Wiz::on_aprbut_clicked()
{

    if (currow != 10000 && modgen->data(modgen->index(currow,2)).toString() != "")
    {
       modgen->select();
       modgen->setData(modgen->index(currow,7),"Approved");
    }
}

void apr_Wiz::on_rebut_clicked()
{
    if (currow != 10000 && modgen->data(modgen->index(currow,2)).toString() != "")
    {
       modgen->select();
       if ( modgen->data(modgen->index(currow,7)).toString() == "Submit" || modgen->data(modgen->index(currow,7)).toString() == "Approved")
            modgen->setData(modgen->index(currow,7),"Rework");
    }
}


void apr_Wiz::on_vidbut_clicked()
{
    QString as = "select lfloc from asset_mas where name = ";
    as = as + "\'" + curindex.sibling(currow,1).data().toString() + "\'";
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

void apr_Wiz::on_procombo_currentTextChanged(const QString &arg1)
{
    proj = arg1;
    ui->epcombo->clear();
    ui->statfilcombo->setCurrentIndex(0);
    swtProject(proj);
}

void apr_Wiz::on_artfilcombo_currentTextChanged(const QString &arg1)
{
    if (arg1.toStdString() == "All")
    {
        curartfil = "";
    }
    else
    {
        curartfil = arg1;
    }

    if (curartfil != "" && curstatfil != "")
      {
      modgen->setFilter(QString("status like '%%1%' AND artist like '%%2%' ").arg(curstatfil).arg(curartfil));
      }
      else if (curartfil == "" && curstatfil != "")
      {
      modgen->setFilter(QString("status like '%%1%'").arg(curstatfil));
      }
      else if (curstatfil == "" && curartfil != "")
      {
      modgen->setFilter(QString("artist like '%%1%'").arg(curartfil));
      }
      else
      {
       modgen->setFilter("");
      }
}



void apr_Wiz::on_statfilcombo_currentTextChanged(const QString &arg1)
{
    if (arg1.toStdString() == "All")
    {
        curstatfil = "";
    }
    else
    {
        curstatfil = arg1;
    }

  if (curartfil != "" && curstatfil != "")
    {
    modgen->setFilter(QString("status like '%%1%' AND artist like '%%2%' ").arg(curstatfil).arg(curartfil));
    }
    else if (curartfil == "" && curstatfil != "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curstatfil));
    }
    else if (curstatfil == "" && curartfil != "")
    {
    modgen->setFilter(QString("artist like '%%1%'").arg(curartfil));
    }
    else
    {
     modgen->setFilter("");
    }
}

void apr_Wiz::on_proscombo_currentTextChanged(const QString &arg1)
{
    loadAllTabs();
    ui->progressBar->setValue(0);
}
