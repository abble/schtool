#include "coldel.h"
#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QString>
#include <QDateEdit>
#include <iostream>
#include <qdebug.h>

coldel::coldel(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget *coldel::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    return Q_NULLPTR;
}
