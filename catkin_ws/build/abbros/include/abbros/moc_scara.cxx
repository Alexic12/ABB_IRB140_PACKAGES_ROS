/****************************************************************************
** Meta object code from reading C++ file 'scara.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/abbros/include/abbros/scara.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scara.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Scara[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    7,    6,    6, 0x0a,
      31,    6,    6,    6, 0x0a,
      45,    6,    6,    6, 0x0a,
      62,    6,   55,    6, 0x0a,
      71,    6,   55,    6, 0x0a,
      80,    6,   55,    6, 0x0a,
      89,    6,   55,    6, 0x0a,
      98,    6,   55,    6, 0x0a,
     107,    6,   55,    6, 0x0a,
     116,    6,   55,    6, 0x0a,
     123,    6,   55,    6, 0x0a,
     130,    6,   55,    6, 0x0a,
     137,    6,   55,    6, 0x0a,
     145,    6,   55,    6, 0x0a,
     153,    6,   55,    6, 0x0a,
     161,    6,   55,    6, 0x0a,
     169,    6,   55,    6, 0x0a,
     177,    6,   55,    6, 0x0a,
     187,  185,   55,    6, 0x0a,
     204,  185,   55,    6, 0x0a,
     221,  218,   55,    6, 0x0a,
     238,  235,   55,    6, 0x0a,
     256,  252,   55,    6, 0x0a,
     275,  270,   55,    6, 0x0a,
     293,  289,   55,    6, 0x0a,
     311,  307,    6,    6, 0x0a,
     330,  326,    6,    6, 0x0a,
     349,  345,    6,    6, 0x0a,
     368,  364,    6,    6, 0x0a,
     387,  383,    6,    6, 0x0a,
     406,  402,    6,    6, 0x0a,
     423,  421,    6,    6, 0x0a,
     436,    6,    6,    6, 0x0a,
     456,  451,    6,    6, 0x0a,
     487,  478,    6,    6, 0x0a,
     519,    6,    6,    6, 0x08,
     527,    6,    6,    6, 0x08,
     546,  537,    6,    6, 0x08,
     585,  575,    6,    6, 0x08,
     640,  631,  626,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Scara[] = {
    "Scara\0\0dt,sl\0go(double,double)\0"
    "displayPath()\0display()\0double\0getTh1()\0"
    "getTh2()\0getTh3()\0getTh4()\0getTh5()\0"
    "getTh6()\0getX()\0getY()\0getZ()\0getl1()\0"
    "getl2()\0getl3()\0getl4()\0getl5()\0getl6()\0"
    "i\0settoold(double)\0setl1(double)\0iu\0"
    "setl2(double)\0ia\0setl3(double)\0iau\0"
    "setl4(double)\0iaua\0setl5(double)\0ier\0"
    "setl6(double)\0th1\0setTh1(double)\0th2\0"
    "setTh2(double)\0th3\0setTh3(double)\0th4\0"
    "setTh4(double)\0th5\0setTh5(double)\0th6\0"
    "setTh6(double)\0z\0setZ(double)\0"
    "setpathpoint()\0mode\0setMode(SteeringMode)\0"
    "tx,ty,tz\0setTarget(double,double,double)\0"
    "kinPr()\0kinOdwr()\0px,py,pz\0"
    "invkin(double,double,double)\0posi,posf\0"
    "gentray(QVector<double>,QVector<double>)\0"
    "bool\0vx,vy,vz\0calcSpeed(double,double,double)\0"
};

void Scara::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Scara *_t = static_cast<Scara *>(_o);
        switch (_id) {
        case 0: _t->go((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->displayPath(); break;
        case 2: _t->display(); break;
        case 3: { double _r = _t->getTh1();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->getTh2();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: { double _r = _t->getTh3();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->getTh4();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { double _r = _t->getTh5();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 8: { double _r = _t->getTh6();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: { double _r = _t->getX();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 10: { double _r = _t->getY();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 11: { double _r = _t->getZ();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 12: { double _r = _t->getl1();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 13: { double _r = _t->getl2();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 14: { double _r = _t->getl3();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 15: { double _r = _t->getl4();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 16: { double _r = _t->getl5();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 17: { double _r = _t->getl6();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 18: { double _r = _t->settoold((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 19: { double _r = _t->setl1((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 20: { double _r = _t->setl2((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 21: { double _r = _t->setl3((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 22: { double _r = _t->setl4((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 23: { double _r = _t->setl5((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 24: { double _r = _t->setl6((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 25: _t->setTh1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->setTh2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->setTh3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->setTh4((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->setTh5((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->setTh6((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->setZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->setpathpoint(); break;
        case 33: _t->setMode((*reinterpret_cast< SteeringMode(*)>(_a[1]))); break;
        case 34: _t->setTarget((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 35: _t->kinPr(); break;
        case 36: _t->kinOdwr(); break;
        case 37: _t->invkin((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 38: _t->gentray((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 39: { bool _r = _t->calcSpeed((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Scara::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Scara::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Scara,
      qt_meta_data_Scara, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Scara::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Scara::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Scara::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Scara))
        return static_cast<void*>(const_cast< Scara*>(this));
    return QObject::qt_metacast(_clname);
}

int Scara::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
