#include <iostream>

using namespace std;

#define CAR_CONST 20
#define ID_LEN 20

class Car { // Car <- 객체
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;                       // <- 멤버 변수
public:
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();                       // <- 멤버 함수
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
