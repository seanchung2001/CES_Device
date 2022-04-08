/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CES_Device/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "power_on"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 19), // "displayBatteryLevel"
QT_MOC_LITERAL(4, 41, 18), // "batteryDisplay_off"
QT_MOC_LITERAL(5, 60, 16), // "lowBattery_blink"
QT_MOC_LITERAL(6, 77, 9), // "power_off"
QT_MOC_LITERAL(7, 87, 15), // "blink_modeLight"
QT_MOC_LITERAL(8, 103, 17), // "displayConnection"
QT_MOC_LITERAL(9, 121, 12), // "clearDisplay"
QT_MOC_LITERAL(10, 134, 15), // "checkConnection"
QT_MOC_LITERAL(11, 150, 11), // "getDuration"
QT_MOC_LITERAL(12, 162, 11), // "setDuration"
QT_MOC_LITERAL(13, 174, 10), // "setSession"
QT_MOC_LITERAL(14, 185, 12), // "startTherapy"
QT_MOC_LITERAL(15, 198, 10), // "endTherapy"
QT_MOC_LITERAL(16, 209, 12), // "incIntensity"
QT_MOC_LITERAL(17, 222, 12), // "decIntensity"
QT_MOC_LITERAL(18, 235, 13), // "displaySoftOn"
QT_MOC_LITERAL(19, 249, 14), // "displaySoftOff"
QT_MOC_LITERAL(20, 264, 13), // "recordSession"
QT_MOC_LITERAL(21, 278, 12) // "viewDatabase"

    },
    "MainWindow\0power_on\0\0displayBatteryLevel\0"
    "batteryDisplay_off\0lowBattery_blink\0"
    "power_off\0blink_modeLight\0displayConnection\0"
    "clearDisplay\0checkConnection\0getDuration\0"
    "setDuration\0setSession\0startTherapy\0"
    "endTherapy\0incIntensity\0decIntensity\0"
    "displaySoftOn\0displaySoftOff\0recordSession\0"
    "viewDatabase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    1,  120,    2, 0x08 /* Private */,
       9,    0,  123,    2, 0x08 /* Private */,
      10,    0,  124,    2, 0x08 /* Private */,
      11,    0,  125,    2, 0x08 /* Private */,
      12,    0,  126,    2, 0x08 /* Private */,
      13,    0,  127,    2, 0x08 /* Private */,
      14,    0,  128,    2, 0x08 /* Private */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    0,  130,    2, 0x08 /* Private */,
      17,    0,  131,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    0,  134,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->power_on(); break;
        case 1: _t->displayBatteryLevel(); break;
        case 2: _t->batteryDisplay_off(); break;
        case 3: _t->lowBattery_blink(); break;
        case 4: _t->power_off(); break;
        case 5: _t->blink_modeLight(); break;
        case 6: _t->displayConnection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->clearDisplay(); break;
        case 8: _t->checkConnection(); break;
        case 9: { int _r = _t->getDuration();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setDuration(); break;
        case 11: _t->setSession(); break;
        case 12: _t->startTherapy(); break;
        case 13: _t->endTherapy(); break;
        case 14: _t->incIntensity(); break;
        case 15: _t->decIntensity(); break;
        case 16: _t->displaySoftOn(); break;
        case 17: _t->displaySoftOff(); break;
        case 18: _t->recordSession(); break;
        case 19: _t->viewDatabase(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
