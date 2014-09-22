#include "rowCDelegate.h"
#include "rowCDelegate.h"

#include <QComboBox>
#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QString>
#include <QDateEdit>
#include <iostream>

rowCDelegate::rowCDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    qDebug() << "he";
}



//---------------------------------------------------
void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
     QModelIndex sourceIndex = mapToSource( index );


    if (index.column() == status)
    {

        opt.palette.setColor(
            QPalette::Base,
            QColor(255, 255, 204));

        opt.palette.setColor(
            QPalette::Window,
            QColor(255, 255, 204));
    }

    return QItemDelegate::paint(painter, opt, index);
}
