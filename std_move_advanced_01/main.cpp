#include <iostream>

using namespace std;

class MyArray {
private:
    int num;
public:
    MyArray(int n) {
        cout<<"생성자 호출"<<endl;
        num=n;
    }
    MyArray(const MyArray& copy) {
        cout<<"복사 생성자 호출"<<endl;
        num=copy.num;
    }
    MyArray(MyArray&& move) {
        cout<<"이동 생성자 호출"<<endl;
        num=move.num;
        move.num=0;
    }
    MyArray operator=(MyArray&& move) {
        cout<<"이동 대입 연산자 호출"<<endl;
        swap(num, move.num);
        return *this;
    }
    int getNum() {
        return num;
    }
};

MyArray CreateMyArray() {
    return MyArray(100);
}

int main() {
    MyArray ar1(10); // 1
    MyArray ar2(ar1); // 1 // 객체가 다르니까 ar2가 바뀐다고 ar1이 바뀌지 않는다.
//    cout<<"ar1.getNum: "<<ar1.getNum()<<endl;
//    cout<<"ar2.getNum: "<<ar2.getNum()<<endl;

    ar2=CreateMyArray(); // 3
//    cout<<"ar1.getNum: "<<ar1.getNum()<<endl;
//    cout<<"ar2.getNum: "<<ar2.getNum()<<endl;

    MyArray ar3(std::move(ar1)); // 1
//    cout<<"ar1.getNum: "<<ar1.getNum()<<endl;
//    cout<<"ar3.getNum: "<<ar3.getNum()<<endl;

    return 0;
}
