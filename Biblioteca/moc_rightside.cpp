/****************************************************************************
** Meta object code from reading C++ file 'rightside.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "QT_files/headers/rightside.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rightside.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rightside_t {
    QByteArrayData data[14];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rightside_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rightside_t qt_meta_stringdata_rightside = {
    {
QT_MOC_LITERAL(0, 0, 9), // "rightside"
QT_MOC_LITERAL(1, 10, 11), // "itemPointed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "itemName"
QT_MOC_LITERAL(4, 32, 15), // "oggettoAggiunto"
QT_MOC_LITERAL(5, 48, 4), // "tipo"
QT_MOC_LITERAL(6, 53, 4), // "dati"
QT_MOC_LITERAL(7, 58, 17), // "preferitoCambiato"
QT_MOC_LITERAL(8, 76, 10), // "updateInfo"
QT_MOC_LITERAL(9, 87, 11), // "biblioteca*"
QT_MOC_LITERAL(10, 99, 12), // "selectedItem"
QT_MOC_LITERAL(11, 112, 17), // "svuotaDescrizione"
QT_MOC_LITERAL(12, 130, 10), // "modificare"
QT_MOC_LITERAL(13, 141, 10) // "aggiungere"

    },
    "rightside\0itemPointed\0\0itemName\0"
    "oggettoAggiunto\0tipo\0dati\0preferitoCambiato\0"
    "updateInfo\0biblioteca*\0selectedItem\0"
    "svuotaDescrizione\0modificare\0aggiungere"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rightside[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       7,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,
      12,    0,   64,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

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
        case 0: _t->itemPointed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->oggettoAggiunto((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2]))); break;
        case 2: _t->preferitoCambiato((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->updateInfo((*reinterpret_cast< biblioteca*(*)>(_a[1]))); break;
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

QT_INIT_METAOBJECT const QMetaObject rightside::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_rightside.data,
    qt_meta_data_rightside,
    qt_static_metacall,
    nullptr,
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
