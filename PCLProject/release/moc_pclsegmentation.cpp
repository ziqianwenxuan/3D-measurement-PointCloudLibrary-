/****************************************************************************
** Meta object code from reading C++ file 'pclsegmentation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../pclsegmentation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclsegmentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PCLSegmentation_t {
    QByteArrayData data[21];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PCLSegmentation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PCLSegmentation_t qt_meta_stringdata_PCLSegmentation = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PCLSegmentation"
QT_MOC_LITERAL(1, 16, 9), // "loadScene"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "loadScene2"
QT_MOC_LITERAL(4, 38, 10), // "loadScene3"
QT_MOC_LITERAL(5, 49, 10), // "loadScene4"
QT_MOC_LITERAL(6, 60, 10), // "loadScene5"
QT_MOC_LITERAL(7, 71, 10), // "loadScene6"
QT_MOC_LITERAL(8, 82, 10), // "loadScene7"
QT_MOC_LITERAL(9, 93, 10), // "loadScene8"
QT_MOC_LITERAL(10, 104, 13), // "PlanSegmetion"
QT_MOC_LITERAL(11, 118, 11), // "PassThrough"
QT_MOC_LITERAL(12, 130, 14), // "ComputerNormal"
QT_MOC_LITERAL(13, 145, 13), // "SegmetionPlan"
QT_MOC_LITERAL(14, 159, 17), // "SegmetionCylinder"
QT_MOC_LITERAL(15, 177, 22), // "RegionGrowingSegmetion"
QT_MOC_LITERAL(16, 200, 18), // "MinCutSegmentation"
QT_MOC_LITERAL(17, 219, 15), // "DONSegmentation"
QT_MOC_LITERAL(18, 235, 20), // "SupervoxelClustering"
QT_MOC_LITERAL(19, 256, 30), // "ProgressiveMorphologicalFilter"
QT_MOC_LITERAL(20, 287, 30) // "ConditionalEuclideanClustering"

    },
    "PCLSegmentation\0loadScene\0\0loadScene2\0"
    "loadScene3\0loadScene4\0loadScene5\0"
    "loadScene6\0loadScene7\0loadScene8\0"
    "PlanSegmetion\0PassThrough\0ComputerNormal\0"
    "SegmetionPlan\0SegmetionCylinder\0"
    "RegionGrowingSegmetion\0MinCutSegmentation\0"
    "DONSegmentation\0SupervoxelClustering\0"
    "ProgressiveMorphologicalFilter\0"
    "ConditionalEuclideanClustering"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PCLSegmentation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x0a /* Public */,
       3,    0,  110,    2, 0x0a /* Public */,
       4,    0,  111,    2, 0x0a /* Public */,
       5,    0,  112,    2, 0x0a /* Public */,
       6,    0,  113,    2, 0x0a /* Public */,
       7,    0,  114,    2, 0x0a /* Public */,
       8,    0,  115,    2, 0x0a /* Public */,
       9,    0,  116,    2, 0x0a /* Public */,
      10,    0,  117,    2, 0x0a /* Public */,
      11,    0,  118,    2, 0x0a /* Public */,
      12,    0,  119,    2, 0x0a /* Public */,
      13,    0,  120,    2, 0x0a /* Public */,
      14,    0,  121,    2, 0x0a /* Public */,
      15,    0,  122,    2, 0x0a /* Public */,
      16,    0,  123,    2, 0x0a /* Public */,
      17,    0,  124,    2, 0x0a /* Public */,
      18,    0,  125,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PCLSegmentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PCLSegmentation *_t = static_cast<PCLSegmentation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadScene(); break;
        case 1: _t->loadScene2(); break;
        case 2: _t->loadScene3(); break;
        case 3: _t->loadScene4(); break;
        case 4: _t->loadScene5(); break;
        case 5: _t->loadScene6(); break;
        case 6: _t->loadScene7(); break;
        case 7: _t->loadScene8(); break;
        case 8: _t->PlanSegmetion(); break;
        case 9: _t->PassThrough(); break;
        case 10: _t->ComputerNormal(); break;
        case 11: _t->SegmetionPlan(); break;
        case 12: _t->SegmetionCylinder(); break;
        case 13: _t->RegionGrowingSegmetion(); break;
        case 14: _t->MinCutSegmentation(); break;
        case 15: _t->DONSegmentation(); break;
        case 16: _t->SupervoxelClustering(); break;
        case 17: _t->ProgressiveMorphologicalFilter(); break;
        case 18: _t->ConditionalEuclideanClustering(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PCLSegmentation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLSegmentation.data,
      qt_meta_data_PCLSegmentation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PCLSegmentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PCLSegmentation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PCLSegmentation.stringdata0))
        return static_cast<void*>(const_cast< PCLSegmentation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLSegmentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
