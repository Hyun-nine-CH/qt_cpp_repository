#include <iostream>

using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

//class Chulsoo {
struct Chulsoo {
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;

    Chulsoo(const char* n, const char* s, const char* j, const char* c, int a) {
        strncpy(name, n, NAME_LEN);
        strncpy(sex, s, SEX_LEN);
        strncpy(job, j, JOB_LEN);
        strncpy(character, c, CHARACTER_LEN);
        age = a;
    } // 구조체에 생성자를 추가하였다. C++의 경우

    void introduce() {}
    void eat(const char* food) {}
    void sleep() {}
    void drive(const char* destination) {}
};

int main(void) {
    Chulsoo chulsoo={"철수", "남성", "작가", "diligent", 32};

    chulsoo.drive("레스토랑");
    chulsoo.eat("스테이크");
    return 0;
}
