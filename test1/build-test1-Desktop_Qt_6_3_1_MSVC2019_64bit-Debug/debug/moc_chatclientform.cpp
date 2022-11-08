/****************************************************************************
** Meta object code from reading C++ file 'chatclientform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../chatclientform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatclientform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatClientForm_t {
    const uint offsetsAndSize[26];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ChatClientForm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ChatClientForm_t qt_meta_stringdata_ChatClientForm = {
    {
QT_MOC_LITERAL(0, 14), // "ChatClientForm"
QT_MOC_LITERAL(15, 14), // "sendClientName"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 11), // "receiveData"
QT_MOC_LITERAL(43, 8), // "sendData"
QT_MOC_LITERAL(52, 10), // "disconnect"
QT_MOC_LITERAL(63, 12), // "sendProtocol"
QT_MOC_LITERAL(76, 11), // "Chat_Status"
QT_MOC_LITERAL(88, 5), // "char*"
QT_MOC_LITERAL(94, 8), // "sendFile"
QT_MOC_LITERAL(103, 8), // "goOnSend"
QT_MOC_LITERAL(112, 10), // "flagSended"
QT_MOC_LITERAL(123, 4) // "flag"

    },
    "ChatClientForm\0sendClientName\0\0"
    "receiveData\0sendData\0disconnect\0"
    "sendProtocol\0Chat_Status\0char*\0sendFile\0"
    "goOnSend\0flagSended\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatClientForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   71,    2, 0x08,    3 /* Private */,
       4,    0,   72,    2, 0x08,    4 /* Private */,
       5,    0,   73,    2, 0x08,    5 /* Private */,
       6,    3,   74,    2, 0x08,    6 /* Private */,
       6,    2,   81,    2, 0x28,   10 /* Private | MethodCloned */,
       9,    0,   86,    2, 0x08,   13 /* Private */,
      10,    1,   87,    2, 0x08,   14 /* Private */,
      11,    1,   90,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 8, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 8,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void ChatClientForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatClientForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendClientName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->receiveData(); break;
        case 2: _t->sendData(); break;
        case 3: _t->disconnect(); break;
        case 4: _t->sendProtocol((*reinterpret_cast< std::add_pointer_t<Chat_Status>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->sendProtocol((*reinterpret_cast< std::add_pointer_t<Chat_Status>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<char*>>(_a[2]))); break;
        case 6: _t->sendFile(); break;
        case 7: _t->goOnSend((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 8: _t->flagSended((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatClientForm::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClientForm::sendClientName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChatClientForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChatClientForm.offsetsAndSize,
    qt_meta_data_ChatClientForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ChatClientForm_t
, QtPrivate::TypeAndForceComplete<ChatClientForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Chat_Status, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Chat_Status, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ChatClientForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatClientForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatClientForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatClientForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ChatClientForm::sendClientName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
