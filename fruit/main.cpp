#include <iostream>

using namespace std;

class FruitSeller {
private:
    int APPLE_PRICE; // 만약 과일의 값이 유동적이지 않을 때에는 const int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:
    int SaleApples(int money) { // 그러나 상수는 선언과 동시에 초기화 되어야 하기 때문에 클래스를 정의하는 과정에서 불가능하다.
        int num=money/APPLE_PRICE;
        numOfApples-=num;
        myMoney+=money;
        return num;
    }
};
