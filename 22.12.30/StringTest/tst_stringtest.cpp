#include <QtTest>

// add necessary includes here

class StringTest : public QObject
{
    Q_OBJECT

public:
    StringTest();
    ~StringTest();

private slots:
    void test_case1();

};

StringTest::StringTest()
{

}

StringTest::~StringTest()
{

}

void StringTest::test_case1()
{

}

QTEST_APPLESS_MAIN(StringTest)

#include "tst_stringtest.moc"
