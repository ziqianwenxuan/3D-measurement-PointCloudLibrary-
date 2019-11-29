/****************************************************************************
** Meta object code from reading C++ file 'filter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PCLProject/filter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Filter_t {
    QByteArrayData data[16];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Filter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Filter_t qt_meta_stringdata_Filter = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Filter"
QT_MOC_LITERAL(1, 7, 9), // "loadScene"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "loadScene2"
QT_MOC_LITERAL(4, 29, 10), // "loadScene3"
QT_MOC_LITERAL(5, 40, 10), // "loadScene4"
QT_MOC_LITERAL(6, 51, 10), // "loadScene6"
QT_MOC_LITERAL(7, 62, 10), // "loadScene7"
QT_MOC_LITERAL(8, 73, 10), // "loadScene8"
QT_MOC_LITERAL(9, 84, 11), // "PassThrough"
QT_MOC_LITERAL(10, 96, 9), // "VoxelGrid"
QT_MOC_LITERAL(11, 106, 25), // "StatisticalOutlierRemoval"
QT_MOC_LITERAL(12, 132, 14), // "ExtractIndices"
QT_MOC_LITERAL(13, 147, 18), // "ConditionalRemoval"
QT_MOC_LITERAL(14, 166, 20), // "RadiusOutlierRemoval"
QT_MOC_LITERAL(15, 187, 8) // "CropHull"

    },
    "Filter\0loadScene\0\0loadScene2\0loadScene3\0"
    "loadScene4\0loadScene6\0loadScene7\0"
    "loadScene8\0PassThrough\0VoxelGrid\0"
    "StatisticalOutlierRemoval\0ExtractIndices\0"
    "ConditionalRemoval\0RadiusOutlierRemoval\0"
    "CropHull"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Filter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Filter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Filter *_t = static_cast<Filter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadScene(); break;
        case 1: _t->loadScene2(); break;
        case 2: _t->loadScene3(); break;
        case 3: _t->loadScene4(); break;
        case 4: _t->loadScene6(); break;
        case 5: _t->loadScene7(); break;
        case 6: _t->loadScene8(); break;
        case 7: _t->PassThrough(); break;
        case 8: _t->VoxelGrid(); break;
        case 9: _t->StatisticalOutlierRemoval(); break;
        case 10: _t->ExtractIndices(); break;
        case 11: _t->ConditionalRemoval(); break;
        case 12: _t->RadiusOutlierRemoval(); break;
        case 13: _t->CropHull(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Filter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Filter.data,
      qt_meta_data_Filter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Filter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Filter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Filter.stringdata0))
        return static_cast<void*>(const_cast< Filter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Filter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
