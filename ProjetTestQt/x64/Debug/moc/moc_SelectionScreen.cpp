/****************************************************************************
** Meta object code from reading C++ file 'SelectionScreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../SelectionScreen.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectionScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSelectionScreenENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSelectionScreenENDCLASS = QtMocHelpers::stringData(
    "SelectionScreen",
    "normalGameRequested",
    "",
    "changePawnsRequested",
    "changeBishopsRequested",
    "normalGameClicked",
    "changePawnsClicked",
    "changeBishopsClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSelectionScreenENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[16];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[23];
    char stringdata5[18];
    char stringdata6[19];
    char stringdata7[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSelectionScreenENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSelectionScreenENDCLASS_t qt_meta_stringdata_CLASSSelectionScreenENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "SelectionScreen"
        QT_MOC_LITERAL(16, 19),  // "normalGameRequested"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 20),  // "changePawnsRequested"
        QT_MOC_LITERAL(58, 22),  // "changeBishopsRequested"
        QT_MOC_LITERAL(81, 17),  // "normalGameClicked"
        QT_MOC_LITERAL(99, 18),  // "changePawnsClicked"
        QT_MOC_LITERAL(118, 20)   // "changeBishopsClicked"
    },
    "SelectionScreen",
    "normalGameRequested",
    "",
    "changePawnsRequested",
    "changeBishopsRequested",
    "normalGameClicked",
    "changePawnsClicked",
    "changeBishopsClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSelectionScreenENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SelectionScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSelectionScreenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSelectionScreenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSelectionScreenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SelectionScreen, std::true_type>,
        // method 'normalGameRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePawnsRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeBishopsRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'normalGameClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePawnsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeBishopsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SelectionScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SelectionScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->normalGameRequested(); break;
        case 1: _t->changePawnsRequested(); break;
        case 2: _t->changeBishopsRequested(); break;
        case 3: _t->normalGameClicked(); break;
        case 4: _t->changePawnsClicked(); break;
        case 5: _t->changeBishopsClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectionScreen::*)();
            if (_t _q_method = &SelectionScreen::normalGameRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SelectionScreen::*)();
            if (_t _q_method = &SelectionScreen::changePawnsRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SelectionScreen::*)();
            if (_t _q_method = &SelectionScreen::changeBishopsRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *SelectionScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectionScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSelectionScreenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SelectionScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SelectionScreen::normalGameRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SelectionScreen::changePawnsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SelectionScreen::changeBishopsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
