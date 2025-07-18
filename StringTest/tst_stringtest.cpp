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

StringTest::StringTest() {}

StringTest::~StringTest() {}

void StringTest::test_case1() {
    QString str="test";
    QVERIFY2(true, "Failure");
    QCOMPARE(str.toUpper(),QString("TEXT"));
}

QTEST_APPLESS_MAIN(StringTest)

#include "tst_stringtest.moc"
