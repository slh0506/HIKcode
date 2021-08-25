/****************************************************************************
** Meta object code from reading C++ file 'AlarmDevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AlarmDevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AlarmDevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAlarmDevice_t {
    QByteArrayData data[9];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAlarmDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAlarmDevice_t qt_meta_stringdata_CAlarmDevice = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CAlarmDevice"
QT_MOC_LITERAL(1, 13, 23), // "onClickedSetupAlarmChan"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "onClickedCloseAlarmChan"
QT_MOC_LITERAL(4, 62, 20), // "onClickedStartListen"
QT_MOC_LITERAL(5, 83, 19), // "onClickedStopListen"
QT_MOC_LITERAL(6, 103, 30), // "onDoubleClickedAlarmDeviceInfo"
QT_MOC_LITERAL(7, 134, 5), // "index"
QT_MOC_LITERAL(8, 140, 13) // "onClickedExit"

    },
    "CAlarmDevice\0onClickedSetupAlarmChan\0"
    "\0onClickedCloseAlarmChan\0onClickedStartListen\0"
    "onClickedStopListen\0onDoubleClickedAlarmDeviceInfo\0"
    "index\0onClickedExit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAlarmDevice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x28 /* Private | MethodCloned */,
       8,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CAlarmDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAlarmDevice *_t = static_cast<CAlarmDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClickedSetupAlarmChan(); break;
        case 1: _t->onClickedCloseAlarmChan(); break;
        case 2: _t->onClickedStartListen(); break;
        case 3: _t->onClickedStopListen(); break;
        case 4: _t->onDoubleClickedAlarmDeviceInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->onDoubleClickedAlarmDeviceInfo(); break;
        case 6: _t->onClickedExit(); break;
        default: ;
        }
    }
}

const QMetaObject CAlarmDevice::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CAlarmDevice.data,
      qt_meta_data_CAlarmDevice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CAlarmDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAlarmDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAlarmDevice.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CAlarmDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
