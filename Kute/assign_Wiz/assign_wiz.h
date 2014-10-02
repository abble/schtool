#ifndef assign_wiz_H
#define assign_wiz_H

#include <QWidget>

#include <QSqlTableModel>
#include <QNetworkRequest>
//#include <custommodels.h>

class MySubClassedSqlTableModel : public QSqlTableModel
  {
      Q_OBJECT
      public:
         MySubClassedSqlTableModel(QObject * parent = 0, QSqlDatabase db = QSqlDatabase())
         : QSqlTableModel(parent,db) {;}
         QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const
         {
            if(role==Qt::BackgroundColorRole)
            {
                const QVariant value(data(index.sibling(index.row(),7),Qt::DisplayRole));
                if (value.toString()=="Assigned")
                {
                    return QVariant(QColor(40,165,215,120));
                }
                else if (value.toString()=="Approved")
                {
                    return QVariant(QColor(64,145,35,120));
                }
                else if (value.toString()=="Delay")
                {
                    return QVariant(QColor(255,0,0,120));
                }
                else if (value.toString()=="Rework")
                {
                    return QVariant(QColor(255, 254, 199,200));
                }
                else if (value.toString()=="Submit")
                {
                    return QVariant(QColor(255, 127, 0,120));
                }

            }
            return QSqlTableModel::data(index,role);
         }
 };

namespace Ui {
class assign_wiz;
}

class assign_wiz : public QWidget
{
    Q_OBJECT

public:
    explicit assign_wiz(QWidget *parent = 0);
    ~assign_wiz();
    QSqlTableModel *asb;
    QSqlTableModel *shb;

    MySubClassedSqlTableModel *assetm;
    MySubClassedSqlTableModel *assetr;

    MySubClassedSqlTableModel *shotp;
    MySubClassedSqlTableModel *shotb;
    MySubClassedSqlTableModel *shota;
    MySubClassedSqlTableModel *shotl;


    void swtDatabase(QString datab);
    void getFlds(QString asrsh);
    void getnasentrs();
    void getnshentrs();
    void swtProject(QString prj);
    void swtEpisd(QString epsd);
    void swtassshot(QString but);
    void swtBpat();
    void epipop();

    void setCurSt();
    void loadAllTabs();
    void refreshData();
    void visset();



//variables


    QSqlDatabase mydb;
    QString basepath;
    QString baseppath;
    QString curdatab;
    QString episd;
    QString proj;
    QStringList epilist;
    QString entry;
    QString asbut;
    QString tabbut;
    QString curstate;
    QModelIndex curModel;
    QStringList mdrs,rgrs,animrs,ligrs;
    QString curartfil,curstatfil;


private slots:
    //void on_tableView_clicked(const QModelIndex &index);

    void on_asbut_clicked();

    void on_shbut_clicked();

    void on_astabwidg_currentChanged(int index);

    void on_shtabwidg_currentChanged(int index);

    void on_epcombo_currentIndexChanged(const QString &arg1);

    void on_modtabv_clicked(const QModelIndex &index);

    void on_rigtabv_clicked(const QModelIndex &index);

    void on_prevtabv_clicked(const QModelIndex &index);

    void on_statfilcombo_currentIndexChanged(const QString &arg1);

    void on_artfilcombo_currentIndexChanged(const QString &arg1);

    void on_blktabv_clicked(const QModelIndex &index);

    void on_anitabv_clicked(const QModelIndex &index);

    void on_lighttabv_clicked(const QModelIndex &index);

    void on_procombo_currentIndexChanged(const QString &arg1);

private:
    Ui::assign_wiz *ui;
};



#endif // assign_wiz_H
