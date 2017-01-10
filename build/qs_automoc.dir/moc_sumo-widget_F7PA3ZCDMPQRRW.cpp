/****************************************************************************
** Meta object code from reading C++ file 'sumo-widget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qsumo/sumo-widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sumo-widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SumoWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     358,   11,   11,   11, 0x08,
     390,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SumoWidget[] = {
    "SumoWidget\0\0on__open_close_clicked(bool)\0"
    "on__flip_clicked(bool)\0"
    "on__flipDown_clicked(bool)\0"
    "on__balance_clicked(bool)\0"
    "on__hijump_clicked(bool)\0"
    "on__longjump_clicked(bool)\0"
    "on__growingCircles_clicked(bool)\0"
    "on__slalom_clicked(bool)\0"
    "on__swing_clicked(bool)\0on__tap_clicked(bool)\0"
    "on__turn_clicked(bool)\0"
    "on__turnAndJump_clicked(bool)\0"
    "on__turnLeftRight_clicked(bool)\0"
    "on__turnToBalance_clicked(bool)\0"
    "on__watchLeftRight_clicked(bool)\0"
};

void SumoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SumoWidget *_t = static_cast<SumoWidget *>(_o);
        switch (_id) {
        case 0: _t->on__open_close_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on__flip_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on__flipDown_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on__balance_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on__hijump_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on__longjump_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on__growingCircles_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on__slalom_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on__swing_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on__tap_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on__turn_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on__turnAndJump_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on__turnLeftRight_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on__turnToBalance_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on__watchLeftRight_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SumoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SumoWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SumoWidget,
      qt_meta_data_SumoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SumoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SumoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SumoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SumoWidget))
        return static_cast<void*>(const_cast< SumoWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SumoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
