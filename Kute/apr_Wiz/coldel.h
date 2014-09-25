#ifndef COLDEL_H
#define COLDEL_H

#include <QItemDelegate>
#include <QWidget>

class QModelIndex;
class QWidget;
class QVariant;

class coldel : public QItemDelegate
{
    Q_OBJECT
public:
    explicit coldel(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:

};

#endif // COLDEL_H
