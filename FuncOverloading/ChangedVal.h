#ifndef CHANGEDVAL_H
#define CHANGEDVAL_H

#include <iostream>
using namespace std;

class ChVal {
private:
    int num;
public:
    ChVal(int n);
    ChVal& Subtr(int n);
    ChVal& ShowTwoNumber();

    int getVal() const {
        return num;
    }
};

#endif // CHANGEDVAL_H
