#ifndef WIDGET_H
#define WIDGET_H

#include <QVBoxLayout>
#include <QGridLayout>

#include <QWidget>
#include <QVector>

#include <QLabel>
#include <QPushButton>
//#include <QButtonGroup>

class QLabel;
class QPushButton;
//class QButtonGroup;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *m_label;
//    QButtonGroup*buttonGroup; // QButtonGroup을 위한 멤버 객체 생성
    QVector<QPushButton*> m_buttons; // Qt의 컨테이너 클래스를 사용
    QString m_num1, m_op; // 두번째 값은 QLabel 객체에 표시되어 있다.
    bool m_isFirst; // 버튼을 처음 눌렀을 때
    const qint32 WIDTH = 4;

public slots:
    void setNum();
    void setOp();
//    void click(int id);
};
#endif // WIDGET_H
