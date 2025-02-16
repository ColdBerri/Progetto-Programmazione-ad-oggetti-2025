/****************************************************************************
** Meta object code from reading C++ file 'leftside.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "QT_files/headers/leftside.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leftside.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_leftside_t {
    const uint offsetsAndSize[36];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_leftside_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_leftside_t qt_meta_stringdata_leftside = {
    {
QT_MOC_LITERAL(0, 8), // "leftside"
QT_MOC_LITERAL(9, 12), // "itemSelected"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 11), // "biblioteca*"
QT_MOC_LITERAL(35, 12), // "selectedItem"
QT_MOC_LITERAL(48, 21), // "elementoDeselezionato"
QT_MOC_LITERAL(70, 18), // "filtraListaRicerca"
QT_MOC_LITERAL(89, 18), // "filtraPerCategoria"
QT_MOC_LITERAL(108, 9), // "categoria"
QT_MOC_LITERAL(118, 12), // "QPushButton*"
QT_MOC_LITERAL(131, 18), // "bottoneSelezionato"
QT_MOC_LITERAL(150, 10), // "salvaLista"
QT_MOC_LITERAL(161, 11), // "rimuoviItem"
QT_MOC_LITERAL(173, 8), // "itemName"
QT_MOC_LITERAL(182, 12), // "aggiornaItem"
QT_MOC_LITERAL(195, 17), // "costruisciOggetto"
QT_MOC_LITERAL(213, 4), // "tipo"
QT_MOC_LITERAL(218, 4) // "dati"

    },
    "leftside\0itemSelected\0\0biblioteca*\0"
    "selectedItem\0elementoDeselezionato\0"
    "filtraListaRicerca\0filtraPerCategoria\0"
    "categoria\0QPushButton*\0bottoneSelezionato\0"
    "salvaLista\0rimuoviItem\0itemName\0"
    "aggiornaItem\0costruisciOggetto\0tipo\0"
    "dati"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_leftside[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       5,    0,   65,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   66,    2, 0x0a,    4 /* Public */,
       7,    2,   67,    2, 0x0a,    5 /* Public */,
      11,    0,   72,    2, 0x0a,    8 /* Public */,
      12,    1,   73,    2, 0x0a,    9 /* Public */,
      14,    1,   76,    2, 0x0a,   11 /* Public */,
      15,    2,   79,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   16,   17,

       0        // eod
};

void leftside::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<leftside *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemSelected((*reinterpret_cast< std::add_pointer_t<biblioteca*>>(_a[1]))); break;
        case 1: _t->elementoDeselezionato(); break;
        case 2: _t->filtraListaRicerca(); break;
        case 3: _t->filtraPerCategoria((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[2]))); break;
        case 4: _t->salvaLista(); break;
        case 5: _t->rimuoviItem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->aggiornaItem((*reinterpret_cast< std::add_pointer_t<biblioteca*>>(_a[1]))); break;
        case 7: _t->costruisciOggetto((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (leftside::*)(biblioteca * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&leftside::itemSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (leftside::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&leftside::elementoDeselezionato)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject leftside::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_leftside.offsetsAndSize,
    qt_meta_data_leftside,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_leftside_t
, QtPrivate::TypeAndForceComplete<leftside, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<biblioteca *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<biblioteca *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>


>,
    nullptr
} };


const QMetaObject *leftside::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *leftside::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_leftside.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int leftside::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void leftside::itemSelected(biblioteca * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void leftside::elementoDeselezionato()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
