#include <QCoreApplication>
#include <QtTest>
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
z
// add necessary includes here

class GuiTest : public QObject
{
    Q_OBJECT

public:
    GuiTest(QWidget *parent=nullptr);
    ~GuiTest();

    QLineEdit* lineEdit;

private slots:
    void test_case1();
};

GuiTest::GuiTest(QWidget *parent): QWidget(parent){
    lineEdit=new QLineEdit(this);
}

void GuiTest::test_case1() {
    QTest::keyClicks(lineEdit, "hi KDE");
    QCOMPARE(lineEdit->text(), "hi KDE");
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(GuiTest)

#include "tst_guitest.moc"
