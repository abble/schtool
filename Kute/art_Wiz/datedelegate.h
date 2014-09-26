#ifndef datedelegate_H
#define datedelegate_H

#include <string>
#include <vector>

#include <QItemDelegate>

class QModelIndex;
class QWidget;
class QVariant;

class datedelegate : public QItemDelegate
{
Q_OBJECT
public:
  datedelegate(QObject *parent = 0);

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
 //void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  int clickd;



private:
  std::vector<std::string> Items;

};
#endif
