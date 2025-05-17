#include <iostream>

using namespace std;

class FruitSeller {
private:
    int numOfApples;
    int myMoney;
public:
    void InitMembers(int money) {
        myMoney=money;
        numOfApples=0; // 사과 구매 이전
    }
    void BuyApples(FruitSeller &seller, int money) {
        numOfApples+=seller.SaleApples(money);
        myMoney-=money;
    }
    void ShowBuyResult() {
        cout<<"현재 잔액: "<<myMoney<<endl;
        cout<<"사과 개수: "<<numOfApples<<endl;
    }

    // 일반적인 변수 선언 방식의 객체 생성
    // FruitSeller seller;
    // FruitBuyer;

    // 동적 할당 방식의 객체 생성
    // FruitSeller* objPtr1=new FruitSeller;
    // FruitBuyer* objPtr2=new FruitBuyer;
};
int main(void) {
    FruitSeller seller;
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000); // 아저씨 사과 2000원어치 주세요.

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult(); // 아저씨 오늘 얼마나 파셨어요 라는 질문의 대답
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult(); // 사과 심부름 하고 나머지 잔돈이 얼마야 라는 질문의 대답
    return 0;
}

/*
FruitBuyer 객체가 FruitSeller 객체의 SaleApples 함수를 호출하고 있다. 그리고
객체지향에서는 이것을 '두 객체가 대화하는 것'으로 해석한다.
따라서 이러한 형태의 함수 호출을 가리켜 '메시지 전달'이라고 한다.
 */
