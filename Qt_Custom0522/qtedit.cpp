#include "qtedit.h"

QtEdit::QtEdit(QWidget *parent)
    : QMainWindow(parent)
{
    textedit=new QTextEdit(this);
}

QtEdit::~QtEdit() {}

void QtEdit::alignText() {
    QAction *action=qobject_cast<QAction*>(sender());
    // if(action->text()=="&Left")보다 contain()함수를 추천
    if(action->text().contains("Left", Qt::CaseInsensitive))
        textedit->setAlignment(Qt::AlignLeft);
        // textedit 객체의 클래스 멤버 선언 필요
    else if(action->text().contains("Center", Qt::CaseInsensitive))
        textedit->setAlignment(Qt::AlignCenter);
}
