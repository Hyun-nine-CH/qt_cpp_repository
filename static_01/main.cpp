#include <iostream>

using namespace std;

/*
class Point {
protected:
    int m_x, m_y;
public:
    static int s_xScreen, s_yScreen;
};

int Point::s_xScreen=0;
int Point::s_yScreen=0;

int main() {
    Point::s_xScreen=1024;
    Point::s_yScreen=768;
}
*/

/*
class SoSimple {
private:
    static int simObjCnt;
public:
    SoSimple() {
        simObjCnt++;
        cout<<simObjCnt<<"번째 SoSimple 객체"<<endl;
    }
};
int SoSimple::simObjCnt=0;
*/

/*
class SoSimple {
public:
    static int simObjCnt;
public:
    SoSimple() {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt=0;

int main(void) {
    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl;
    SoSimple sim1;
    SoSimple sim2;
    cout<<SoSimple::simObjCnt<<"번째 SoSimple 객체"<<endl;
    cout<<sim1.simObjCnt<<"번째 SoSimple 객체"<<endl;
    cout<<sim2.simObjCnt<<"번째 SoSimple 객체"<<endl;
    return 0;
}
*/
