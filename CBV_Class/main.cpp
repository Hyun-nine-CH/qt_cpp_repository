#include <iostream>
using namespace std;

class Restaurant {
public:
    int Steak;
};

class Chulsoo {
public:
    int Eat(int);
};

int Chulsoo::Eat(int SteakNum) {
    SteakNum = 10000;
    cout<<"철수는 먹는다"<<endl;
    return SteakNum;
}

int main()
{
    Chulsoo chulsoo;
    Restaurant restaurant;

    restaurant.Steak = 20000;
    cout<<"철수는 "<<chulsoo.Eat(restaurant.Steak)<<"원 짜리 스테이크를 먹었다고 거짓말을 했다."<<endl;
    cout<<"레스토랑은 철수가 "<<restaurant.Steak<<"원 짜리 스테이크를 먹었다고 알고 있다."<<endl;

    return 0;
}
