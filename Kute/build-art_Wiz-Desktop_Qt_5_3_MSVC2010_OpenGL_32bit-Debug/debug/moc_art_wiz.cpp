/****************************************************************************
** Meta object code from reading C++ file 'art_wiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../art_Wiz/art_wiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'art_wiz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MySubClassedSqlTableModel_t {
    QByteArrayData data[1];
    char stringdata[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySubClassedSqlTableModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySubClassedSqlTableModel_t qt_meta_stringdata_MySubClassedSqlTableModel = {
    {
QT_MOC_LITERAL(0, 0, 25)
    },
    "MySubClassedSqlTableModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySubClassedSqlTableModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MySubClassedSqlTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MySubClassedSqlTableModel::staticMetaObject = {
    { &QSqlTableModel::staticMetaObject, qt_meta_stringdata_MySubClassedSqlTableModel.data,
      qt_meta_data_MySubClassedSqlTableModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *MySubClassedSqlTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySubClassedSqlTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MySubClassedSqlTableModel.stringdata))
        return static_cast<void*>(const_cast< MySubClassedSqlTableModel*>(this));
    return QSqlTableModel::qt_metacast(_clname);
}

int MySubClassedSqlTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_art_Wiz_t {
    QByteArrayData data[9];
    char stringdata[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_art_Wiz_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_art_Wiz_t qt_meta_stringdata_art_Wiz = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 15),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 5),
QT_MOC_LITERAL(4, 31, 17),
QT_MOC_LITERAL(5, 49, 19),
QT_MOC_LITERAL(6, 69, 34),
QT_MOC_LITERAL(7, 104, 4),
QT_MOC_LITERAL(8, 109, 30)
    },
    "art_Wiz\0on_tabv_clicked\0\0index\0"
    "on_subbut_clicked\0on_videobut_clicked\0"
    "on_statfilcombo_currentTextChanged\0"
    "arg1\0on_procombo_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_art_Wiz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void art_Wiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        art_Wiz *_t = static_cast<art_Wiz *>(_o);
        switch (_id) {
        case 0: _t->on_tabv_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_subbut_clicked(); break;
        case 2: _t->on_videobut_clicked(); break;
        case 3: _t->on_statfilcombo_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_procombo_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject art_Wiz::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_art_Wiz.data,
      qt_meta_data_art_Wiz,  qt_static_metacall, 0, 0}
};


const QMetaObject *art_Wiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *art_Wiz::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_art_Wiz.stringdata))
        return static_cast<void*>(const_cast< art_Wiz*>(this));
    return QWidget::qt_metacast(_clname);
}

int art_Wiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
