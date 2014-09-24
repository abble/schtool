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
    this->setStyleSheet("background-color: rgb(0, 53, 118);");
    ui->tabv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabv->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    swtBpat();
    swtProject("Jinnr");
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
    modgen->setHeaderData(1,Qt::Horizontal,tr("Name"));
    modgen->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    modgen->setHeaderData(5,Qt::Horizontal,tr("Start Date"));
    modgen->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    modgen->setHeaderData(7,Qt::Horizontal,tr("Status"));
    modgen->sort(0,Qt::AscendingOrder);

    ComboBoxDelegate *dmodelrs = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(2,dmodelrs);

    datedelegate *dated = new datedelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(5,dated);
    ui->tabv->setItemDelegateForColumn(6,dated);

    ComboBoxDelegate *statdelg = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(7,statdelg);

    coldel *delg = new coldel(ui->tabv);
    ui->tabv->setItemDelegateForColumn(0,delg);
    ui->tabv->setItemDelegateForColumn(1,delg);


    statdelg->Items.clear();
    statdelg->Items.push_back("Assigned");
    statdelg->Items.push_back("Approved");
    statdelg->Items.push_back("Delay");

    QSqlQuery st;
    st.exec("Select name from user where dept = 'Model'");

    while(st.next())
    {
        dmodelrs->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->tabv->setModel(modgen);
    ui->tabv->hideColumn(3);
    ui->tabv->hideColumn(4);
    ui->tabv->hideColumn(5);
    ui->tabv->hideColumn(6);
    ui->tabv->show();


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

void apr_Wiz::on_tabv_clicked(const QModelIndex &index)
{
    int row = index.row();

    QString as = "select pvwloc from asset_mas where name = ";
    as = as + "\'" + index.sibling(row,1).data().toString() + "\'";
    QSqlQuery preloc(curdatab);
    preloc.exec(as);
    preloc.first();
    QString ppath = preloc.value(0).toString();

    QString defpath = "S:/intelture/Pipeline/noPreview.png";

    if (QUrl(ppath).isValid())
    {
        ui->prevlab->setPixmap(QPixmap(ppath));
    }
    else
    {
        ui->prevlab->setPixmap(QPixmap(defpath));
    }
}
