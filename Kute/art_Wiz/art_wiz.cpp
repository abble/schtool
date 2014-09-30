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

void art_Wiz::swtBpat()
{
    basepath = "S:/intelture/Pipeline/Sched/datab/";
    baseppath = "S:/intelture/Pipeline";
    //basepath = "/Users/sekhar/Github/dbfiles/";
    //baseppath = "/Users/sekhar/Github/Project/";
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

    modgen = new MySubClassedSqlTableModel(this);
    modgen->setTable("asset_mod");
    modgen->setEditStrategy(QSqlTableModel::OnRowChange);
    modgen->select();
    modgen->setHeaderData(0,Qt::Horizontal,tr("Asset Type"));
    modgen->setHeaderData(1,Qt::Horizontal,tr("Asset Name"));
    modgen->setHeaderData(2,Qt::Horizontal,tr("Artist"));
    modgen->setHeaderData(6,Qt::Horizontal,tr("End Date"));
    modgen->setHeaderData(7,Qt::Horizontal,tr("Status"));
    modgen->sort(0,Qt::AscendingOrder);


    ComboBoxDelegate *dmodelrs = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(2,dmodelrs);

    ComboBoxDelegate *statdelg = new ComboBoxDelegate(ui->tabv);
    ui->tabv->setItemDelegateForColumn(7,statdelg);

    coldel *delg = new coldel(ui->tabv);
    ui->tabv->setItemDelegateForColumn(0,delg);
    ui->tabv->setItemDelegateForColumn(1,delg);
    ui->tabv->setItemDelegateForColumn(2,delg);
    ui->tabv->setItemDelegateForColumn(3,delg);
    ui->tabv->setItemDelegateForColumn(4,delg);
    ui->tabv->setItemDelegateForColumn(5,delg);
    ui->tabv->setItemDelegateForColumn(6,delg);
    ui->tabv->setItemDelegateForColumn(7,delg);

    statdelg->Items.clear();
    statdelg->Items.push_back("Assigned");
    statdelg->Items.push_back("Approved");
    statdelg->Items.push_back("Rework");
    statdelg->Items.push_back("Delay");

    QSqlQuery st;
    st.exec("Select name from user where dept = 'Model'");

    while(st.next())
    {
        dmodelrs->Items.push_back(st.value(0).toString().toStdString());
    }

    ui->tabv->setModel(modgen);
    ui->tabv->hideColumn(2);
    ui->tabv->hideColumn(3);
    ui->tabv->hideColumn(4);

    ui->tabv->show();

    mapper = new QDataWidgetMapper;
    mapper->setModel(modgen);
    mapper->addMapping(ui->lcCom, 3);
    mapper->addMapping(ui->dcCom, 4);


}


void art_Wiz::swtDatabase(QString datab)
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


void art_Wiz::epipop()
{
    QString pth;
    QDir fld;
    pth = baseppath + "/" + proj + "/" + "03_Production";
    fld.setPath(pth);
    epilist = fld.entryList(epilist,QDir::AllDirs|QDir::NoDotAndDotDot);
    ui->epcombo->addItems(epilist);
}

void art_Wiz::epiprp(QString tst)
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

void art_Wiz::on_tabv_clicked(const QModelIndex &index)
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

    if (QUrl(ppath).isValid())
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

void art_Wiz::on_statfilcombo_currentIndexChanged(const QString &arg1)
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

void art_Wiz::on_videobut_clicked()
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
