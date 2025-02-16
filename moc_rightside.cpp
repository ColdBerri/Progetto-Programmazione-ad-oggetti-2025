/****************************************************************************
** Meta object code from reading C++ file 'rightside.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "QT_files/headers/rightside.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rightside.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rightside_t {
    const uint offsetsAndSize[28];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_rightside_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_rightside_t qt_meta_stringdata_rightside = {
    {
QT_MOC_LITERAL(0, 9), // "rightside"
QT_MOC_LITERAL(10, 11), // "itemPointed"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 8), // "itemName"
QT_MOC_LITERAL(32, 15), // "oggettoAggiunto"
QT_MOC_LITERAL(48, 4), // "tipo"
QT_MOC_LITERAL(53, 4), // "dati"
QT_MOC_LITERAL(58, 17), // "preferitoCambiato"
QT_MOC_LITERAL(76, 10), // "updateInfo"
QT_MOC_LITERAL(87, 11), // "biblioteca*"
QT_MOC_LITERAL(99, 12), // "selectedItem"
QT_MOC_LITERAL(112, 17), // "svuotaDescrizione"
QT_MOC_LITERAL(130, 10), // "modificare"
QT_MOC_LITERAL(141, 10) // "aggiungere"

    },
    "rightside\0itemPointed\0\0itemName\0"
    "oggettoAggiunto\0tipo\0dati\0preferitoCambiato\0"
    "updateInfo\0biblioteca*\0selectedItem\0"
    "svuotaDescrizione\0modificare\0aggiungere"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rightside[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    2,   59,    2, 0x06,    3 /* Public */,
       7,    1,   64,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   67,    2, 0x0a,    8 /* Public */,
      11,    0,   70,    2, 0x0a,   10 /* Public */,
      12,    0,   71,    2, 0x0a,   11 /* Public */,
      13,    0,   72,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,    5,    6,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rightside::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rightside *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemPointed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->oggettoAggiunto((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 2: _t->preferitoCambiato((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->updateInfo((*reinterpret_cast< std::add_pointer_t<biblioteca*>>(_a[1]))); break;
        case 4: _t->svuotaDescrizione(); break;
        case 5: _t->modificare(); break;
        case 6: _t->aggiungere(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (rightside::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rightside::itemPointed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rightside::*)(const QString & , const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rightside::oggettoAggiunto)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (rightside::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rightside::preferitoCambiato)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject rightside::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_rightside.offsetsAndSize,
    qt_meta_data_rightside,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_rightside_t
, QtPrivate::TypeAndForceComplete<rightside, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<biblioteca *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *rightside::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rightside::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rightside.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rightside::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void rightside::itemPointed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rightside::oggettoAggiunto(const QString & _t1, const QVariantMap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rightside::preferitoCambiato(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
