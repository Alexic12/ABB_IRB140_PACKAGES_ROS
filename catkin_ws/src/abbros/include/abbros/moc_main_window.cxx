/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_abbros__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      53,   47,   19,   19, 0x0a,
      91,   85,   19,   19, 0x0a,
     141,   19,  137,   19, 0x0a,
     152,   19,   19,   19, 0x0a,
     172,   19,   19,   19, 0x0a,
     183,  177,   19,   19, 0x0a,
     224,  177,   19,   19, 0x0a,
     265,  177,   19,   19, 0x0a,
     306,  177,   19,   19, 0x0a,
     347,  177,   19,   19, 0x0a,
     386,   19,   19,   19, 0x0a,
     419,   19,   19,   19, 0x0a,
     450,   19,   19,   19, 0x0a,
     481,   19,   19,   19, 0x0a,
     508,   19,   19,   19, 0x0a,
     535,   19,   19,   19, 0x0a,
     559,   19,   19,   19, 0x0a,
     586,   19,   19,   19, 0x0a,
     613,   19,   19,   19, 0x0a,
     646,   19,   19,   19, 0x0a,
     673,   19,   19,   19, 0x0a,
     699,   19,   19,   19, 0x0a,
     724,   19,   19,   19, 0x0a,
     748,   19,   19,   19, 0x0a,
     773,  177,   19,   19, 0x0a,
     814,  177,   19,   19, 0x0a,
     855,  177,   19,   19, 0x0a,
     896,  177,   19,   19, 0x0a,
     937,   19,   19,   19, 0x0a,
     963,  177,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_abbros__MainWindow[] = {
    "abbros::MainWindow\0\0on_actionAbout_triggered()\0"
    "check\0on_button_connect_clicked(bool)\0"
    "state\0on_checkbox_use_environment_stateChanged(int)\0"
    "int\0getvalue()\0updateLoggingView()\0"
    "go()\0value\0on_verticalSliderPitch_valueChanged(int)\0"
    "on_horizontalSliderYaw_valueChanged(int)\0"
    "on_horizontalSliderTh1_valueChanged(int)\0"
    "on_horizontalSliderTh2_valueChanged(int)\0"
    "on_horizontalSliderZ_valueChanged(int)\0"
    "on_commandLinkButtonGo_clicked()\0"
    "on_radioButtonSimple_clicked()\0"
    "on_radioButtonTarget_clicked()\0"
    "on_pushButton_21_clicked()\0"
    "on_pushButton_22_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_21_pressed()\0"
    "on_pushButton_16_clicked()\0"
    "on_radioButtonSimple_2_clicked()\0"
    "on_pushButton_18_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_startbutton_clicked()\0"
    "on_stopbutton_clicked()\0"
    "on_pausebutton_clicked()\0"
    "on_horizontalSliderTh3_valueChanged(int)\0"
    "on_horizontalSliderTh4_valueChanged(int)\0"
    "on_horizontalSliderTh5_valueChanged(int)\0"
    "on_horizontalSliderTh6_valueChanged(int)\0"
    "on_pushButton_4_clicked()\0"
    "on_velocityslider_valueChanged(int)\0"
};

void abbros::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = _t->getvalue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->updateLoggingView(); break;
        case 5: _t->go(); break;
        case 6: _t->on_verticalSliderPitch_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSliderYaw_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSliderTh1_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSliderTh2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_horizontalSliderZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_commandLinkButtonGo_clicked(); break;
        case 12: _t->on_radioButtonSimple_clicked(); break;
        case 13: _t->on_radioButtonTarget_clicked(); break;
        case 14: _t->on_pushButton_21_clicked(); break;
        case 15: _t->on_pushButton_22_clicked(); break;
        case 16: _t->on_pushButton_clicked(); break;
        case 17: _t->on_pushButton_21_pressed(); break;
        case 18: _t->on_pushButton_16_clicked(); break;
        case 19: _t->on_radioButtonSimple_2_clicked(); break;
        case 20: _t->on_pushButton_18_clicked(); break;
        case 21: _t->on_pushButton_5_clicked(); break;
        case 22: _t->on_startbutton_clicked(); break;
        case 23: _t->on_stopbutton_clicked(); break;
        case 24: _t->on_pausebutton_clicked(); break;
        case 25: _t->on_horizontalSliderTh3_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_horizontalSliderTh4_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_horizontalSliderTh5_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_horizontalSliderTh6_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_pushButton_4_clicked(); break;
        case 30: _t->on_velocityslider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData abbros::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject abbros::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_abbros__MainWindow,
      qt_meta_data_abbros__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &abbros::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *abbros::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *abbros::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_abbros__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int abbros::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
