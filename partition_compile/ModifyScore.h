#ifndef MODIFYSCORE_H
#define MODIFYSCORE_H

#include <iostream>
using namespace std;

class ModiSC {
public:
    void ShowMScore();
    void setMScore(const int s);
    int getMScore();

private:
    int Score;
};

#endif // MODIFYSCORE_H
