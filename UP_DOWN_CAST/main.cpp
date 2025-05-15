#include <iostream>

using namespace std;

class Point {
public:
    Point(int x = 0, int y = 0) : m_x(x), m_y(y) { }
    void Print() const {
        cout << "(x, y) : " << m_x << ", " << m_y << endl;
    }
    int GetX() { return m_x; }
    int GetY() { return m_y; }
private:
    int m_x, m_y;
};

class Shape {
public:
    Shape() { }
    Shape(Point s, Point e) : m_start(s), m_end(e) { }
    void SetStartPoint(Point s) { m_start = s; }
    void SetEndPoint(Point e) { m_end = e; }
    void Draw() {
        m_start.Print();
        m_end.Print();
    }
    virtual ~Shape() = default;
protected:
    Point m_start, m_end;
};

class Rectangle : public Shape {
public:
    Rectangle() = default;
    Rectangle(Point s, Point e) : Shape(s, e) { }
    int GetWidth() {
        return m_end.GetX() - m_start.GetX();
    }

    int GetHeight() {
        return m_end.GetY() - m_start.GetY();
    }

    void Draw() {
        cout << "(w, h) : " << GetWidth() << ", " << GetHeight() << endl;
    }
};

class Ellipse : public Shape {
public:
    Ellipse() = default;
    Ellipse(Point s, Point e) : Shape(s, e) { }
    bool IsCircle() {
        return true;
    }

    int GetWidth() {
        return m_end.GetX() - m_start.GetX();
    }

    int GetHeight() {
        return m_end.GetY() - m_start.GetY();
    }

    void Draw() {
        cout << "(w, h) : " << GetWidth() << ", " << GetHeight() << endl;
    }
};

void DisplayShapeObject(Shape &object)
{
    object.Draw( );
    Shape *s = &object;
    Ellipse *s1 = dynamic_cast<Ellipse*>(s); 			// 다운 캐스팅
    Rectangle *s2 = dynamic_cast<Rectangle*>(s); 		// 다운 캐스팅
    if (s1 != NULL)  {
        s1->Draw( );
        cout << "원의 수평 지름 : " << s1->GetWidth( ) << endl;
        cout << "원의 수직 지름 : " << s1->GetHeight( ) << endl;
    }
    if (s2 != NULL) {
        s2->Draw( );
        cout << "사각형의 밑변 : " << s2->GetWidth( ) << endl;
        cout << "사각형의 높이 : " << s2->GetHeight( ) << endl;
    }
}

int main(void)
{
    Shape *pShape1 = new Rectangle;    	// 업 캐스트이므로 OK
    // Rectangle *pRect1 = pShape1;    	// 다운 캐스트이므로 컴파일 에러임
    Rectangle *pRect2 = (Rectangle*) pShape1;    	// 강제 형 변환에 의한 OK

    Point p1(9, 15), p2(120, 150), p3(5, 6), p4(100, 120);
    Ellipse s1(p1, p2);
    Rectangle s2(p3, p4);

    DisplayShapeObject(s1);
    cout << "****************************" << endl;
    DisplayShapeObject(s2);
    //  Shape *pShape2 = new Shape;
    //  Rectangle *pRect3 = (Rectangle*) pShape2;    	// 강제 형 변환  실행 에러

    return 0;
}

