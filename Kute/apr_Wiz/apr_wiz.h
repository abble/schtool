#ifndef APR_WIZ_H
#define APR_WIZ_H

#include <QWidget>
#include <QSqlTableModel>
#include <QNetworkRequest>

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
class apr_Wiz;
}

class apr_Wiz : public QWidget
{
    Q_OBJECT

public:
    explicit apr_Wiz(QWidget *parent = 0);
    ~apr_Wiz();

    MySubClassedSqlTableModel *modgen;


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



    QSqlDatabase mydb;
    QString basepath;
    QString baseppath;
    QString curdatab;
    QString episd;
    QString proj;
    QStringList epilist;
    QString entry;
    QString curstate;


private slots:
    void on_tabv_clicked(const QModelIndex &index);

private:
    Ui::apr_Wiz *ui;
};

#endif // APR_WIZ_H
