#include "apr_wiz.h"
#include "ui_apr_wiz.h"
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

apr_Wiz::apr_Wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apr_Wiz)
{

    ui->setupUi(this);

    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->tabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    swtBpat();
    swtProject("Jinnr");
    wuser = qgetenv("USERNAME");
    epiprp(wuser);
    currow = 10000;


    ui->statfilcombo->addItem("All");
    ui->statfilcombo->addItem("Assigned");
    ui->statfilcombo->addItem("Submit");
    ui->statfilcombo->addItem("Approved");
    ui->statfilcombo->addItem("Rework");
    ui->statfilcombo->addItem("Delay");
    curstatfil = "";
    curartfil = "";
}

apr_Wiz::~apr_Wiz()
{
    delete ui;
}

void apr_Wiz::setCurSt()
{
   curstate = " " + proj + "/" + " " + episd + " " + "/" + " " + "Assets" + " " + "/" + " " + "Model";
   ui->curstate->setText(curstate);
}

void apr_Wiz::swtProject(QString prj)
{
    proj = "Jinnr";
    swtEpisd("EP01");
    epipop();
    loadAllTabs();
    setCurSt();
    ui->datelab->setText(QDate::currentDate().toString());
    QString qtpth = baseppath + "/" + proj + "/projimage.png";
    ui->prolab->setPixmap(QPixmap(qtpth));
    ui->prolab->setPixmap(QPixmap(qtpth));
}

void apr_Wiz::swtBpat()
{
    basepath = "S:/intelture/Pipeline/Sched/datab/";
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

    modgen = new MySubClassedSqlTableModel(this);
    modgen->setTable("asset_mod");
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
    st.exec("Select artist from user where dept = 'model'");
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


}


void apr_Wiz::swtDatabase(QString datab)
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


void apr_Wiz::epipop()
{
    QString pth;
    QDir fld;
    pth = baseppath + "/" + proj + "/" + "03_Production";
    fld.setPath(pth);
    epilist = fld.entryList(epilist,QDir::AllDirs|QDir::NoDotAndDotDot);
    ui->epcombo->addItems(epilist);
}

void apr_Wiz::epiprp(QString tst)
{
    QString pt = "select proj from puser where artist = ";
    pt= pt + '\"' + tst + '\"';
    QSqlQuery qry(pt);
    qry.last();
    ui->procombo->addItem(qry.value("proj").toString());
    while (qry.previous())
    {
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

    QString as = "select pvwloc from asset_mas where name = ";
    as = as + "\'" + index.sibling(currow,1).data().toString() + "\'";
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

  //  ui->detLayout->setStyleSheet("background-color: rgb(50, 155, 255);");

    if (QUrl(ppath).isValid())
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
       if ( modgen->data(modgen->index(currow,7)).toString() != "Submit" )
       modgen->setData(modgen->index(currow,7),"Rework");
    }
}


void apr_Wiz::on_artfilcombo_currentIndexChanged(const QString &arg1)
{
    if (arg1.toStdString() == "All")
    {
        curartfil = "";
    }
    else
    {
        curartfil = arg1;
    }

    if (curartfil != "")
    {
    modgen->setFilter(QString("status like '%%1%' AND artist like '%%2%' ").arg(curstatfil).arg(curartfil));
    }
    else if (curartfil == "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curstatfil));
    }
    else if (curstatfil == "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curartfil));
    }
}

void apr_Wiz::on_statfilcombo_currentIndexChanged(const QString &arg1)
{
    if (arg1.toStdString() == "All")
    {
        curstatfil = "";
    }
    else
    {
        curstatfil = arg1;
    }

    if (curartfil != "")
    {
    modgen->setFilter(QString("status like '%%1%' AND artist like '%%2%' ").arg(curstatfil).arg(curartfil));
    }
    else if (curartfil == "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curstatfil));
    }
    else if (curstatfil == "")
    {
    modgen->setFilter(QString("status like '%%1%'").arg(curartfil));
    }
}
