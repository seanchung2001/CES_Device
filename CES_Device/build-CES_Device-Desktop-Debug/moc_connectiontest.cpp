/****************************************************************************
** Meta object code from reading C++ file 'connectiontest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CES_Device/connectiontest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectiontest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_connectionTest_t {
    QByteArrayData data[5];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_connectionTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_connectionTest_t qt_meta_stringdata_connectionTest = {
    {
QT_MOC_LITERAL(0, 0, 14), // "connectionTest"
QT_MOC_LITERAL(1, 15, 15), // "blink_modeLight"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "displayConnection"
QT_MOC_LITERAL(4, 50, 12) // "clearDisplay"

    },
    "connectionTest\0blink_modeLight\0\0"
    "displayConnection\0clearDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_connectionTest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       4,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void connectionTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<connectionTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->blink_modeLight(); break;
        case 1: _t->displayConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clearDisplay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (connectionTest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectionTest::blink_modeLight)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (connectionTest::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectionTest::displayConnection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (connectionTest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectionTest::clearDisplay)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject connectionTest::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_connectionTest.data,
    qt_meta_data_connectionTest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *connectionTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *connectionTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_connectionTest.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int connectionTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void connectionTest::blink_modeLight()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void connectionTest::displayConnection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void connectionTest::clearDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
