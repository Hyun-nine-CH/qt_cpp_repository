#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_isFirst(true) {
    m_label=new QLabel("0", this);
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    m_label->setFrameShape(QFrame::Box);
    m_label->setMaximumHeight(30);
//    m_label->setGeometry(10,5,230,40);

    const char ButtonChar[16][2]={
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };

    QGridLayout*gridLayout=new QGridLayout();
    buttonGroup=new QButtonGroup(this);
    connect(buttonGroup, SIGNAL(idClicked(int)),SLOT(click(int)));
    for(int y=0; y<WIDTH; ++y) {
        for(int x=0; x<WIDTH; ++x) {
            int n = x+y*WIDTH;
            buttonGroup->addButton(new QPushButton(ButtonChar[n],this),n);
            gridLayout->addWidget(buttonGroup->button(n),n/WIDTH,n%WIDTH);
            //m_buttons.append(new QPushButton(ButtonChar[n],this));
            //gridLayout->addWidget(m_buttons.at(n),n/WIDTH,n%WIDTH);
            //if(n!=13&&n!=14)
            //    connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
        }
    }
/*
    for(int y=0; y<WIDTH; ++y) {
        for(int x=0; x< WIDTH; ++x) {
            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH],this));
            m_buttons.at(x+y*WIDTH)->setGeometry(5+60*x,50+60*y,60,60);
        }
    }
*/
    connect(m_buttons.at(0), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(1), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(2), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(4), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(5), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(6), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(8), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(9), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(10), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(12), SIGNAL(clicked()),SLOT(setNum()));

    connect(m_buttons.at(13),&QPushButton::clicked,this,[=](){m_label->setText("0");});

    connect(m_buttons.at(3), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(7), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(11), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(15), SIGNAL(clicked()),SLOT(setNum()));

    connect(m_buttons.at(14),&QPushButton::clicked,this,[this](){
        qreal result=0;
        m_isFirst=true;
        if(m_op=="+")
            result=m_num1.toDouble()+m_label->text().toDouble();
        else if(m_op=="-")
            result=m_num1.toDouble()-m_label->text().toDouble();
        else if(m_op=="x")
            result=m_num1.toDouble()*m_label->text().toDouble();
        else if(m_op=="/")
            if(m_label->text().toDouble()) {
                result=m_num1.toDouble()/m_label->text().toDouble();
            }else{
                m_label->setText("Error:Cannot Divide by Zero");
                return;
            }
        m_label->setText(QString::number(result));
    });

//    setMinimumSize(250,295);
//    setMaximumSize(250,295);
    setWindowTitle("Calculater");
    QBoxLayout*vBoxLayout=new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(6,6,6,6);
    vBoxLayout->addWidget(m_label);
    vBoxLayout->addLayout(gridLayout);
    setLayout(vBoxLayout);
}

Widget::~Widget() {
    delete m_label;
    Q_FOREACH(auto b, buttonGroup->buttons()) delete b;
    //    m_buttons.clear();
}
void Widget::click(int id) {
    QPushButton *button=(QPushButton*)((QButtonGroup*)sender())->button(id);
    QString bStr;
    if(button!=nullptr) bStr=button->text();
    switch(id) {
    case 0: case 1: case 2:
    case 4: case 5: case 6:
    case 8: case 9: case 10:
    case 12:
        if(m_label!=nullptr) {
            QString IStr=m_label->text();
            m_label->setText((IStr=="0"|m_isFirst)?bStr:IStr+bStr);
            m_isFirst=false;
        }
        break;

    case 3: case 7: case 11: case 15:
        if(m_label!=nullptr)
            m_num1=m_label->text();
        m_op=bStr;
        m_isFirst=true;
        break;
    case 13: case 14: break;
    };
}
/*
void Widget::setNum() {
    QPushButton *button=dynamic_cast<QPushButton*>(sender());
    QString bStr;
    if(m_label!=nullptr) bStr=button->text();
    if(m_label!=nullptr) {
        QString IStr=m_label->text();
        m_label->setText((IStr=="0"|m_isFirst)?bStr:IStr+bStr);
        m_isFirst=false;
    }
}
void Widget::setOp() {
    QPushButton*button=dynamic_cast<QPushButton*>(sender());
    if(button!=nullptr) m_op=button->text();
    if(m_label!=nullptr) {
        m_num1=m_label->text();
        m_isFirst=true;
    }
}
*/
// updated info.
/*
switch(m_op.at(0).toLatin1()) {
case '+':result=m_num1.toDouble()+m_label->text().toDouble(); break;
case '-':result=m_num1.toDouble()-m_label->text().toDouble(); break;
case 'x':result=m_num1.toDouble()*m_label->text().toDouble(); break;
case '/':
    if(m_label->text().toDouble()) {
        result=m_num1.toDouble()+m_label->text().toDouble();
    }
}

const char*methods[16]={
    SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
    SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
    SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
    SLOT(setNum()), SLOT(), SLOT(), SLOT(setOp())
};

for(int y=0; y<WIDTH;++y) {
    for(int x=0; x<WIDTH;++x) {
        int n=x+y*WIDTH;
        m_buttons.append(new QPushButton(ButtonChar[n],this));
        m_buttons.at(n)->setGeometry(5+60*x,50+60*y,60,60);
        if(n!=13&&n!=14) connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
    }
}
void Widget::setNum() {
    if(button!=nullptr) bStr=button->text();
    if(m_label!=nullptr) {
        QString IStr=m_label->text();
#if 1
        m_label->setText((IStr=="0"|m_isFirst)?IStr+bStr);
#else
m_label->setText(QString::number(IStr.toDouble()*10+bStr.toDouble()));
#endif
        m_isFirst=false;
    }
}
*/
