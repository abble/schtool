/****************************************************************************
** Meta object code from reading C++ file 'assign_wiz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assign_Wiz/assign_wiz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assign_wiz.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_assign_wiz_t {
    QByteArrayData data[12];
    char stringdata[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_assign_wiz_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_assign_wiz_t qt_meta_stringdata_assign_wiz = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 16),
QT_MOC_LITERAL(4, 46, 27),
QT_MOC_LITERAL(5, 74, 5),
QT_MOC_LITERAL(6, 80, 27),
QT_MOC_LITERAL(7, 108, 30),
QT_MOC_LITERAL(8, 139, 4),
QT_MOC_LITERAL(9, 144, 18),
QT_MOC_LITERAL(10, 163, 18),
QT_MOC_LITERAL(11, 182, 19)
    },
    "assign_wiz\0on_asbut_clicked\0\0"
    "on_shbut_clicked\0on_astabwidg_currentChanged\0"
    "index\0on_shtabwidg_currentChanged\0"
    "on_epcombo_currentIndexChanged\0arg1\0"
    "on_modtabv_clicked\0on_rigtabv_clicked\0"
    "on_prevtabv_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_assign_wiz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    1,   59,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       9,    1,   65,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::QModelIndex,    5,

       0        // eod
};

void assign_wiz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        assign_wiz *_t = static_cast<assign_wiz *>(_o);
        switch (_id) {
        case 0: _t->on_asbut_clicked(); break;
        case 1: _t->on_shbut_clicked(); break;
        case 2: _t->on_astabwidg_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_shtabwidg_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_epcombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_modtabv_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_rigtabv_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_prevtabv_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject assign_wiz::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_assign_wiz.data,
      qt_meta_data_assign_wiz,  qt_static_metacall, 0, 0}
};


const QMetaObject *assign_wiz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *assign_wiz::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_assign_wiz.stringdata))
        return static_cast<void*>(const_cast< assign_wiz*>(this));
    return QWidget::qt_metacast(_clname);
}

int assign_wiz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE