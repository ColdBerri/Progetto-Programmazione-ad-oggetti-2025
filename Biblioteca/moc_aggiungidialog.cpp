/****************************************************************************
** Meta object code from reading C++ file 'aggiungidialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.16)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "QT_files/headers/aggiungidialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aggiungidialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.16. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AggiungiDialog_t {
    QByteArrayData data[16];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AggiungiDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AggiungiDialog_t qt_meta_stringdata_AggiungiDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AggiungiDialog"
QT_MOC_LITERAL(1, 15, 12), // "datiInseriti"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "tipo"
QT_MOC_LITERAL(4, 34, 4), // "dati"
QT_MOC_LITERAL(5, 39, 15), // "abilitaConferma"
QT_MOC_LITERAL(6, 55, 14), // "confermaScelta"
QT_MOC_LITERAL(7, 70, 10), // "salvaNuovo"
QT_MOC_LITERAL(8, 81, 17), // "aggiungiAListaEsp"
QT_MOC_LITERAL(9, 99, 15), // "togliDaListaEsp"
QT_MOC_LITERAL(10, 115, 17), // "aggiungiAListaMat"
QT_MOC_LITERAL(11, 133, 15), // "togliDaListaMat"
QT_MOC_LITERAL(12, 149, 10), // "mostraArte"
QT_MOC_LITERAL(13, 160, 14), // "mostraGioielli"
QT_MOC_LITERAL(14, 175, 13), // "mostraOrologi"
QT_MOC_LITERAL(15, 189, 11) // "pulisciForm"

    },
    "AggiungiDialog\0datiInseriti\0\0tipo\0"
    "dati\0abilitaConferma\0confermaScelta\0"
    "salvaNuovo\0aggiungiAListaEsp\0"
    "togliDaListaEsp\0aggiungiAListaMat\0"
    "togliDaListaMat\0mostraArte\0mostraGioielli\0"
    "mostraOrologi\0pulisciForm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AggiungiDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   79,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AggiungiDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AggiungiDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->datiInseriti((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2]))); break;
        case 1: _t->abilitaConferma(); break;
        case 2: _t->confermaScelta(); break;
        case 3: _t->salvaNuovo(); break;
        case 4: _t->aggiungiAListaEsp(); break;
        case 5: _t->togliDaListaEsp(); break;
        case 6: _t->aggiungiAListaMat(); break;
        case 7: _t->togliDaListaMat(); break;
        case 8: _t->mostraArte(); break;
        case 9: _t->mostraGioielli(); break;
        case 10: _t->mostraOrologi(); break;
        case 11: _t->pulisciForm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AggiungiDialog::*)(const QString & , const QVariantMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AggiungiDialog::datiInseriti)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AggiungiDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AggiungiDialog.data,
    qt_meta_data_AggiungiDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AggiungiDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AggiungiDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AggiungiDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AggiungiDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void AggiungiDialog::datiInseriti(const QString & _t1, const QVariantMap & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
