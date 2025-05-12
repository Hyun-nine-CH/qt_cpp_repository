#include <iostream>

using namespace std;

#define NAME_LEN 20
#define SEX_LEN 10
#define JOB_LEN 20
#define CHARACTER_LEN 20

class Chulsoo {
private:
    char name[NAME_LEN];
    char sex[SEX_LEN];
    char job[JOB_LEN];
    char character[CHARACTER_LEN];
    int age;
    bool marriageStatus;

public:
    void introduce();
    void eat(char* food);
    void sleep();
    void drive(char *destination);
    void write();
    void read();
};
