/****************************************************************************
** Meta object code from reading C++ file 'feature.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../feature.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'feature.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Feature_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Feature_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Feature_t qt_meta_stringdata_Feature = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Feature"
QT_MOC_LITERAL(1, 8, 9), // "loadScene"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "loadScene2"
QT_MOC_LITERAL(4, 30, 10), // "loadScene3"
QT_MOC_LITERAL(5, 41, 10), // "loadScene4"
QT_MOC_LITERAL(6, 52, 10), // "loadScene5"
QT_MOC_LITERAL(7, 63, 13), // "ISSKeypoint3D"
QT_MOC_LITERAL(8, 77, 12), // "SIFTKeypoint"
QT_MOC_LITERAL(9, 90, 12), // "SHOTKeypoint"
QT_MOC_LITERAL(10, 103, 16), // "Harris3DKeypoint"
QT_MOC_LITERAL(11, 120, 12) // "NARFKeypoint"

    },
    "Feature\0loadScene\0\0loadScene2\0loadScene3\0"
    "loadScene4\0loadScene5\0ISSKeypoint3D\0"
    "SIFTKeypoint\0SHOTKeypoint\0Harris3DKeypoint\0"
    "NARFKeypoint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Feature[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

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

       0        // eod
};

void Feature::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Feature *_t = static_cast<Feature *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadScene(); break;
        case 1: _t->loadScene2(); break;
        case 2: _t->loadScene3(); break;
        case 3: _t->loadScene4(); break;
        case 4: _t->loadScene5(); break;
        case 5: _t->ISSKeypoint3D(); break;
        case 6: _t->SIFTKeypoint(); break;
        case 7: _t->SHOTKeypoint(); break;
        case 8: _t->Harris3DKeypoint(); break;
        case 9: _t->NARFKeypoint(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Feature::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Feature.data,
      qt_meta_data_Feature,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Feature::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Feature::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Feature.stringdata0))
        return static_cast<void*>(const_cast< Feature*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Feature::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
