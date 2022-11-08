/****************************************************************************
** Meta object code from reading C++ file 'chatserverform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../chatserverform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatserverform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatServerForm_t {
    const uint offsetsAndSize[36];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ChatServerForm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ChatServerForm_t qt_meta_stringdata_ChatServerForm = {
    {
QT_MOC_LITERAL(0, 14), // "ChatServerForm"
QT_MOC_LITERAL(15, 8), // "sendFlag"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 16), // "acceptConnection"
QT_MOC_LITERAL(42, 10), // "readClient"
QT_MOC_LITERAL(53, 13), // "clientConnect"
QT_MOC_LITERAL(67, 11), // "receiveData"
QT_MOC_LITERAL(79, 12), // "removeClient"
QT_MOC_LITERAL(92, 9), // "addClient"
QT_MOC_LITERAL(102, 16), // "removeClientList"
QT_MOC_LITERAL(119, 1), // "i"
QT_MOC_LITERAL(121, 16), // "modifyClientList"
QT_MOC_LITERAL(138, 12), // "inviteClient"
QT_MOC_LITERAL(151, 7), // "kickOut"
QT_MOC_LITERAL(159, 46), // "on_clientTreeWidget_customCon..."
QT_MOC_LITERAL(206, 3), // "pos"
QT_MOC_LITERAL(210, 16), // "clientNameSended"
QT_MOC_LITERAL(227, 26) // "on_clearPushButton_clicked"

    },
    "ChatServerForm\0sendFlag\0\0acceptConnection\0"
    "readClient\0clientConnect\0receiveData\0"
    "removeClient\0addClient\0removeClientList\0"
    "i\0modifyClientList\0inviteClient\0kickOut\0"
    "on_clientTreeWidget_customContextMenuRequested\0"
    "pos\0clientNameSended\0on_clearPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatServerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  101,    2, 0x08,    3 /* Private */,
       4,    0,  102,    2, 0x08,    4 /* Private */,
       5,    0,  103,    2, 0x08,    5 /* Private */,
       6,    0,  104,    2, 0x08,    6 /* Private */,
       7,    0,  105,    2, 0x08,    7 /* Private */,
       8,    2,  106,    2, 0x08,    8 /* Private */,
       9,    1,  111,    2, 0x08,   11 /* Private */,
      11,    3,  114,    2, 0x08,   13 /* Private */,
      12,    0,  121,    2, 0x08,   17 /* Private */,
      13,    0,  122,    2, 0x08,   18 /* Private */,
      14,    1,  123,    2, 0x08,   19 /* Private */,
      16,    1,  126,    2, 0x08,   21 /* Private */,
      17,    0,  129,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void ChatServerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatServerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendFlag((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->acceptConnection(); break;
        case 2: _t->readClient(); break;
        case 3: _t->clientConnect(); break;
        case 4: _t->receiveData(); break;
        case 5: _t->removeClient(); break;
        case 6: _t->addClient((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->removeClientList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->modifyClientList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 9: _t->inviteClient(); break;
        case 10: _t->kickOut(); break;
        case 11: _t->on_clientTreeWidget_customContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 12: _t->clientNameSended((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->on_clearPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatServerForm::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatServerForm::sendFlag)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChatServerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChatServerForm.offsetsAndSize,
    qt_meta_data_ChatServerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ChatServerForm_t
, QtPrivate::TypeAndForceComplete<ChatServerForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ChatServerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatServerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatServerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatServerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ChatServerForm::sendFlag(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
