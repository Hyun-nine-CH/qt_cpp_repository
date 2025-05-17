#include <iostream>
using namespace std;

class FruitSeller {
private:
    int applePrice;     // 사과 한 개 가격
    int numOfApples;    // 보유 사과 개수
    int myMoney;        // 수익

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
    int GetApplePrice() const;
};

class FruitBuyer {
private:
    int myMoney;        // 보유 금액
    int numOfApples;    // 산 사과 개수

public:
    void InitMembers(int money) {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller& seller, int money) {
        int num = seller.SaleApples(money);
        numOfApples += num;
        myMoney -= num * seller.GetApplePrice(); // 실제 소비 금액만큼 차감
    }

    void ShowBuyResult() const {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl;
    }

    // 판매자의 사과 가격을 알기 위해 접근자 사용
    int GetApplePriceFrom(FruitSeller& seller) {
        return seller.GetApplePrice();
    }
};

// 접근자 함수 추가 (private 멤버 접근 불가 대비)
int FruitSeller::GetApplePrice() const {
    return applePrice;
}

int main(void) {
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);

    buyer.BuyApples(seller, 2000); // 아저씨 사과 2000원어치 주세요.

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}
