#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_isFirst(true) {
    m_label=new QLabel("0", this); // 레이블 객체 생성
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // 계산기 오른쪽 정렬
//    m_label->setGeometry(10,5,230,40); // 위치와 크기를 설정

    m_label->setFrameShape(QFrame::Box);
    m_label->setMaximumHeight(30);

    const char ButtonChar[16][2]={
        "7","8","9","/", // QPushButton 생성자의 첫번째 인자로 문자열만 사용이 가능하다.
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };

    const char *methods[16]={
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), nullptr, nullptr, SLOT(setOp())       // 슬롯들을 위한 배열 생성
    };

    QGridLayout*gridLayout=new QGridLayout();

//    buttonGroup=new QButtonGroup(this);
//    connect(buttonGroup,SIGNAL(buttonClicked(int)),SLOT(click(int)));

    for(int y=0; y<WIDTH; ++y) { //4 x 4의 2차원으로 배치
        for(int x=0; x< WIDTH; ++x) {

//            buttonGroup->addButton(new QPushButton(ButtonChar[x+y*WIDTH],this),x+y*WIDTH);
            // 1차원을 2차원으로, 인자는 y(x+y*WIDTH/WIDTH), x(x+y*WIDTH%WIDTH) 순으로 변환
//            gridLayout->addWidget(buttonGroup->button(x+y*WIDTH),x+y*WIDTH/WIDTH,x+y*WIDTH%WIDTH);

            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH],this)); // 2차원 공간을 1차원 공간으로 변환하는 식이 등쟝!
            // QGridLayout으로 배치
            gridLayout->addWidget(m_buttons.at(x+(y*WIDTH)),(x+(y*WIDTH))/WIDTH,(x+(y*WIDTH))%WIDTH);
            //m_buttons.at(x+y*WIDTH)->setGeometry(5+60*x,50+60*y,60,60);

            const char* method = methods[x+y*WIDTH];
            if (method)
                connect(m_buttons.at(x+y*WIDTH), SIGNAL(clicked()), method);
            // 아래의 방식보다는 바로 위가 안전하다. 인자가 없는 상황에서 그냥 컴파일러가 될 수 있기 때문에 그렇다.

//            if(x+y*WIDTH!=13 && x+y*WIDTH!=14) connect(m_buttons.at(x+y*WIDTH),SIGNAL(clicked()),methods[x+y*WIDTH]);

        }
    }
/*
    // 숫자를 위한 버튼들의 시그널/슬롯 연결
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
*/
    // Clear 버튼을 위한 시그널/슬롯 연결: 람다 함수로 연결
    // connect(m_buttons.at(13),&QPushButton::clicked,this,[=](){m_label->setText("0");});
    if (m_buttons.size() > 13) {
        connect(m_buttons.at(13), &QPushButton::clicked, this, [=]() {
            m_label->setText("0");
        });
    }
/*
    connect(buttonGroup->button(13), &QPushButton::clicked, this, [=]() {
        m_label->setText("0");
    });
*/
    // 연산자를 위한 버튼들을 위한 시그널/슬롯 연결
    connect(m_buttons.at(3), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(7), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(11), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(15), SIGNAL(clicked()),SLOT(setOp()));

    // 계산을 위한 코드: 람다 함수
    connect(m_buttons.at(14),&QPushButton::clicked,this,[this](){
    //connect(buttonGroup->button(14), &QPushButton::clicked, this, [=]() {
        qreal result=0;
        m_isFirst=true;     // 숫자 버튼을 처음 누를 때 처리

        switch(m_op.at(0).toLatin1()) {     // 속도 향상을 위한 스위치 도입, 문자열의 첫 글자를 ASCII 코드로 변경
        case '+':result=m_num1.toDouble()+m_label->text().toDouble(); break;
        case '-':result=m_num1.toDouble()-m_label->text().toDouble(); break;
        case 'x':result=m_num1.toDouble()*m_label->text().toDouble(); break;
        case '/':
            if(m_label->text().toDouble()) {
                result=m_num1.toDouble()/m_label->text().toDouble();

        /*
        if(m_op=="+")
            result=m_num1.toDouble()+m_label->text().toDouble();    // QString을 double로 전환
        else if(m_op=="-")
            result=m_num1.toDouble()-m_label->text().toDouble();
        else if(m_op=="x")
            result=m_num1.toDouble()*m_label->text().toDouble();
        else if(m_op=="/")
            if(m_label->text().toDouble()) {
                result=m_num1.toDouble()/m_label->text().toDouble();
        */


            } else {      // 부모가 0 : 에러 처리 -> QMessageBox 사용 추천
                m_label->setText("Error:Cannot Divide by Zero");
                return;
            }
        }
        m_label->setText(QString::number(result));      // 숫자를 QString으로 변경
    });

//    setMinimumSize(250,295);        // 윈도우의 최소 크기 설정
//    setMaximumSize(250,295);        // 윈도우의 최대 크기 설정
    setWindowTitle("Calculater");   // 윈도우의 타이틀바 설정

    // QVBoxLayout으로 QLabel과 QGridLayout을 위젯의 메인 레이아웃으로 설정
    QVBoxLayout*vBoxLayout=new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(6,6,6,6);    // 외각의 마진을 모두 0으로 설정
    vBoxLayout->addWidget(m_label);             // 위젯을 추가
    vBoxLayout->addLayout(gridLayout);          // 레이아웃을 추가
    setLayout(vBoxLayout);
}

Widget::~Widget() {     // 생성자에서 할당한 객체들의 정리 작업
    delete m_label;
//    m_buttons.clear();      // QVector 또는 QButtonGroup 클래스 안의 객체 삭제
    Q_FOREACH(auto b, m_buttons) delete b;    // QVector의 clear() 수행 시 불필요
    //Q_FOREACH(auto b, buttonGroup->buttons()) delete b;
}
/*
void Widget::click(int id) {
    QPushButton*button=(QPushButton*)((QButtonGroup*)sender())->button(id);
    QString bStr;
    if(button!=nullptr) bStr=button->text();        // 버튼의 문자열
    switch(id) {
    case 0: case 1: case 2:     // 숫자 버튼의 경우: setNum() 슬롯 코드 사용
    case 4: case 5: case 6:
    case 8: case 9: case 10:
    case 12:
        if(m_label!=nullptr) {
            QString IStr=m_label->text();       // 레이블의 문자열
            m_label->setText((IStr=="0"||m_isFirst)?bStr:IStr+bStr);
            m_isFirst=false;
        }
        break;
    case 3: case 7: case 11: case 15:       // 연산자 버튼의 경우: setOp() 슬롯 코드 사용
        if(m_label!=nullptr)
            m_num1=m_label->text();
        m_op=bStr;
        m_isFirst=true;
        break;
    case 13: case 14: break;        // C(Clear)와 = 버튼의 경우: 람다 함수로 처리
    };
}
*/

void Widget::setNum() {     // 숫자 버튼이 눌러졌을 때의 처리
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if (!button || !m_label) return;

    QString bStr = button->text();      // 버튼의 문자열
    QString IStr = m_label->text();     // 레이블의 문자열
    // 레이블의 문자가 0이면 버튼의 문자를 레이블에 그대로 설정
    // 0이 아니면 레이블의 문자열 + 버튼의 문자열을 레이블에 설정

#if 1
    m_label->setText((IStr=="0"||m_isFirst)?bStr:IStr+bStr);
#else
// 글자를 숫자로 바꿔서 계산
    m_label->setText(QString::number(IStr.toDouble()*10+bStr.toDouble()));
#endif
    m_isFirst=false; // 기존의 값 뒤에 연결해서 입력
}

void Widget::setOp() {
    QPushButton*button=dynamic_cast<QPushButton*>(sender());
    if(button!=nullptr) m_op=button->text();    // 버튼의 문자열이 연산자
    if(m_label!=nullptr) {
        m_num1=m_label->text();     // 현재 레이블의 문자열을 멤버 변수로 설정
        m_isFirst=true;             // m_label->setText("0");
    }
}

// Comments: QButtonGroup보다도 QVector가 용이하여 해당 클래스로 만들었다.
