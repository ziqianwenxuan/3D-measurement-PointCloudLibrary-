/****************************************************************************
** Meta object code from reading C++ file 'registation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../registation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Registation_t {
    QByteArrayData data[24];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Registation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Registation_t qt_meta_stringdata_Registation = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Registation"
QT_MOC_LITERAL(1, 12, 12), // "loadTemplate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "loadScene"
QT_MOC_LITERAL(4, 36, 10), // "loadScene2"
QT_MOC_LITERAL(5, 47, 10), // "loadScene3"
QT_MOC_LITERAL(6, 58, 10), // "loadScene4"
QT_MOC_LITERAL(7, 69, 15), // "computeTemplate"
QT_MOC_LITERAL(8, 85, 12), // "computeScene"
QT_MOC_LITERAL(9, 98, 3), // "SAC"
QT_MOC_LITERAL(10, 102, 8), // "DSC_ICP1"
QT_MOC_LITERAL(11, 111, 8), // "DSC_ICP2"
QT_MOC_LITERAL(12, 120, 3), // "ICP"
QT_MOC_LITERAL(13, 124, 8), // "PCS_ICP1"
QT_MOC_LITERAL(14, 133, 8), // "PCS_ICP2"
QT_MOC_LITERAL(15, 142, 8), // "SAC_ICP1"
QT_MOC_LITERAL(16, 151, 8), // "SAC_ICP2"
QT_MOC_LITERAL(17, 160, 8), // "NDT_ICP1"
QT_MOC_LITERAL(18, 169, 8), // "NDT_ICP2"
QT_MOC_LITERAL(19, 178, 12), // "matrix2angle"
QT_MOC_LITERAL(20, 191, 16), // "Eigen::Matrix4f&"
QT_MOC_LITERAL(21, 208, 12), // "result_trans"
QT_MOC_LITERAL(22, 221, 16), // "Eigen::Vector3f&"
QT_MOC_LITERAL(23, 238, 12) // "result_angle"

    },
    "Registation\0loadTemplate\0\0loadScene\0"
    "loadScene2\0loadScene3\0loadScene4\0"
    "computeTemplate\0computeScene\0SAC\0"
    "DSC_ICP1\0DSC_ICP2\0ICP\0PCS_ICP1\0PCS_ICP2\0"
    "SAC_ICP1\0SAC_ICP2\0NDT_ICP1\0NDT_ICP2\0"
    "matrix2angle\0Eigen::Matrix4f&\0"
    "result_trans\0Eigen::Vector3f&\0"
    "result_angle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Registation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    0,  120,    2, 0x0a /* Public */,
      19,    2,  121,    2, 0x0a /* Public */,

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
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22,   21,   23,

       0        // eod
};

void Registation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Registation *_t = static_cast<Registation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadTemplate(); break;
        case 1: _t->loadScene(); break;
        case 2: _t->loadScene2(); break;
        case 3: _t->loadScene3(); break;
        case 4: _t->loadScene4(); break;
        case 5: _t->computeTemplate(); break;
        case 6: _t->computeScene(); break;
        case 7: _t->SAC(); break;
        case 8: _t->DSC_ICP1(); break;
        case 9: _t->DSC_ICP2(); break;
        case 10: _t->ICP(); break;
        case 11: _t->PCS_ICP1(); break;
        case 12: _t->PCS_ICP2(); break;
        case 13: _t->SAC_ICP1(); break;
        case 14: _t->SAC_ICP2(); break;
        case 15: _t->NDT_ICP1(); break;
        case 16: _t->NDT_ICP2(); break;
        case 17: _t->matrix2angle((*reinterpret_cast< Eigen::Matrix4f(*)>(_a[1])),(*reinterpret_cast< Eigen::Vector3f(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject Registation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Registation.data,
      qt_meta_data_Registation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Registation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Registation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Registation.stringdata0))
        return static_cast<void*>(const_cast< Registation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Registation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
