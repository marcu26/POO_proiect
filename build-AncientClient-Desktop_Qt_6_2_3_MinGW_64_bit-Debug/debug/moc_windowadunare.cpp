/****************************************************************************
** Meta object code from reading C++ file 'windowadunare.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AncientClient/windowadunare.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowadunare.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_windowAdunare_t {
    const uint offsetsAndSize[28];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_windowAdunare_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_windowAdunare_t qt_meta_stringdata_windowAdunare = {
    {
QT_MOC_LITERAL(0, 13), // "windowAdunare"
QT_MOC_LITERAL(14, 17), // "on_LogInB_clicked"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 15), // "on_Shop_clicked"
QT_MOC_LITERAL(49, 20), // "on_ScSoldati_clicked"
QT_MOC_LITERAL(70, 16), // "on_ScCav_clicked"
QT_MOC_LITERAL(87, 19), // "on_ScMedici_clicked"
QT_MOC_LITERAL(107, 15), // "on_Duel_clicked"
QT_MOC_LITERAL(123, 25), // "on_listWidget_itemPressed"
QT_MOC_LITERAL(149, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(166, 4), // "item"
QT_MOC_LITERAL(171, 19), // "on_Provoaca_clicked"
QT_MOC_LITERAL(191, 16), // "on_Refuz_clicked"
QT_MOC_LITERAL(208, 17) // "on_Accept_clicked"

    },
    "windowAdunare\0on_LogInB_clicked\0\0"
    "on_Shop_clicked\0on_ScSoldati_clicked\0"
    "on_ScCav_clicked\0on_ScMedici_clicked\0"
    "on_Duel_clicked\0on_listWidget_itemPressed\0"
    "QListWidgetItem*\0item\0on_Provoaca_clicked\0"
    "on_Refuz_clicked\0on_Accept_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_windowAdunare[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    1,   80,    2, 0x08,    7 /* Private */,
      11,    0,   83,    2, 0x08,    9 /* Private */,
      12,    0,   84,    2, 0x08,   10 /* Private */,
      13,    0,   85,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void windowAdunare::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<windowAdunare *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_LogInB_clicked(); break;
        case 1: _t->on_Shop_clicked(); break;
        case 2: _t->on_ScSoldati_clicked(); break;
        case 3: _t->on_ScCav_clicked(); break;
        case 4: _t->on_ScMedici_clicked(); break;
        case 5: _t->on_Duel_clicked(); break;
        case 6: _t->on_listWidget_itemPressed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 7: _t->on_Provoaca_clicked(); break;
        case 8: _t->on_Refuz_clicked(); break;
        case 9: _t->on_Accept_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject windowAdunare::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_windowAdunare.offsetsAndSize,
    qt_meta_data_windowAdunare,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_windowAdunare_t
, QtPrivate::TypeAndForceComplete<windowAdunare, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *windowAdunare::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *windowAdunare::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_windowAdunare.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int windowAdunare::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
