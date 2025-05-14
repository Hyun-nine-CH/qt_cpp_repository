#include <iostream>

using namespace std;

class Point {
protected:
    static int s_xScreen, s_yScreen;
public:
    static void SetScreenSize(int xScreen, int yScreen); // 객체 없이 호출할 수 있는 멤버 함수에서 정적 멤버는 프로그램이 시작할 때 만들어짐
};

// 정적 멤버 함수(메서드)는 정적 멤버 변수를 사용해야만 됨
// 인스턴스는 스택, 그런데 글로벌로 만들면 bss, static 변수는 bss에 할당됨

/*
객체 안에 static만 여러개가 안된다.
생성자랑 소멸자랑 관리 안하고 static 1개고 컨트롤러 여러 개를 만들 수 있다

private static 멤버 변수 <- main() { mem1, mem2, mem3, ...}
*/

void Point::SetScreenSize(int xScreen, int yScreen) {
    s_xScreen=xScreen;
    s_yScreen=yScreen;
}

int main() {
    Point::SetScreenSize(1024,768);
}

/*
void Point::SetScreenSize(int xScreen, int yScreen) {
    s_xScreen=xScreen;
    s_yScreen=yScreen;
    cout<<m_x;
    Print();
}
*/
