#include "datedelegate.h"
#include "datedelegate.h"

#include <QComboBox>
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
 /* for(unsigned int i = 0; i < Items.size(); ++i)
    {
    editor->addItem(Items[i].c_str());
    }*/
  editor->setCalendarPopup(true);
  editor->setDisplayFormat("dd.MM.yy");
  return editor;
}


void datedelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
  QDateEdit *comboBox = static_cast<QDateEdit*>(editor);
  //int value = index.model()->data(index, Qt::EditRole).toUInt();
  comboBox->setDate(QDate::currentDate());
}

void datedelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
  QDateEdit *comboBox = static_cast<QDateEdit*>(editor);
  model->setData(index, comboBox->date(), Qt::EditRole);

}

void datedelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
  editor->setGeometry(option.rect);
}
/*
void datedelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  QStyleOptionViewItemV4 myOption = option;

 // QString text = Items[index.row()].c_str();
 // myOption.text = text;

  QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
*/
