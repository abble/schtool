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
                   return QVariant(QColor(210,45,65,120));
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
    QSqlTableModel *assetr;

    QSqlTableModel *shotp;
    QSqlTableModel *shotb;
    QSqlTableModel *shota;
    QSqlTableModel *shotl;


    void swtDatabase(QString datab);
    void getFlds(QString asrsh);
    void getnasentrs();
    void getnshentrs();
    void swtProject(QString prj);
    void swtEpisd(QString epsd);
    void swtassshot(QString but);
    void swtBpat();
    void epipop();
    void setPreviewPan();
    void setCurSt();
    void loadAllTabs();
    void refreshData();



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

private:
    Ui::assign_wiz *ui;
};



#endif // assign_wiz_H
