#include <iostream>
using namespace std;

class FruitSeller {
private:
    int applePrice;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money) {
        applePrice = price;
        numOfApples = num;
        myMoney = money;
    }

    int SaleApples(int money) {
        int num = money / applePrice;
        if (num > numOfApples) {
            num = numOfApples;
        }
        numOfApples -= num;
        myMoney += num * applePrice;
        return num;
    }

    void ShowSalesResult() const {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl;
    }

    int GetApplePrice() const {
        return applePrice;
    }
};

class FruitBuyer {
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money) {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller* seller, int money) {
        int num = seller->SaleApples(money);
        numOfApples += num;
        myMoney -= num * seller->GetApplePrice();  // 실제 산 개수만큼 차감
    }

    void ShowBuyResult() const {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl;
    }
};

int main(void) {
    // 동적 할당 방식의 객체 생성
    FruitSeller* seller = new FruitSeller;
    seller->InitMembers(1000, 20, 0);

    FruitBuyer* buyer = new FruitBuyer;
    buyer->InitMembers(5000);

    buyer->BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller->ShowSalesResult();

    cout << "과일 구매자의 현황" << endl;
    buyer->ShowBuyResult();

    // 메모리 해제
    delete seller;
    delete buyer;

    return 0;
}
