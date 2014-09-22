#ifndef rowCDelegate_H
#define rowCDelegate_H

#include <string>
#include <vector>

#include <QItemDelegate>

class QModelIndex;
class QWidget;
class QVariant;

class rowCDelegate : public QItemDelegate
{
Q_OBJECT
public:
  rowCDelegate(QObject *parent = 0);

  void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;

};
#endif
