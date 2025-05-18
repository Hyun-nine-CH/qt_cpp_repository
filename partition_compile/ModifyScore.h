#ifndef MODIFYSCORE_H
#define MODIFYSCORE_H

#include <iostream>
using namespace std;

class ModiSC {
public:
    void ShowScore();
    void setScore(const int s);
    int getScore();

private:
    int Score;
};

#endif // MODIFYSCORE_H
