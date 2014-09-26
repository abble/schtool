#include "datedelegate.h"
#include "datedelegate.h"


#include <QWidget>
#include <QModelIndex>
#include <QApplication>
#include <QString>
#include <QDateEdit>
#include <iostream>
#include <QPushButton>

datedelegate::datedelegate(QObject *parent) :
    QItemDelegate(parent)
{
  Items.push_back("Test0");
}


QWidget *datedelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
  QPushButton* editor = new QPushButton(parent);
  editor->setText("Submit");
  return editor;
}


void datedelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QPushButton *dateBox = static_cast<QPushButton*>(editor);
  //dateBox->setDate(QDate::currentDate());
}

void datedelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QPushButton *dateBox = static_cast<QPushButton*>(editor);
  if (clickd == 1)
  {
  model->setData(index, dateBox->text(), Qt::EditRole);
  }
}

void datedelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}



