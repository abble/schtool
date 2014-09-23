#include "datedelegate.h"
#include "datedelegate.h"


#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QString>
#include <QDateEdit>
#include <iostream>

datedelegate::datedelegate(QObject *parent) :
    QItemDelegate(parent)
{
  Items.push_back("Test0");
}


QWidget *datedelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
  QDateEdit* editor = new QDateEdit(parent);
  editor->setCalendarPopup(true);
  editor->setDisplayFormat("dd.MM.yy");
  return editor;
}


void datedelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QDateEdit *dateBox = static_cast<QDateEdit*>(editor);
  dateBox->setDate(QDate::currentDate());
}

void datedelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QDateEdit *dateBox = static_cast<QDateEdit*>(editor);
  model->setData(index, dateBox->date(), Qt::EditRole);

}

void datedelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}

