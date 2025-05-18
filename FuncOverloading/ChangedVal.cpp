#include "ChangedVal.h"

ChVal::ChVal(int n) : num(n) {
    cout << "a -> a'" << endl;
}

ChVal& ChVal::Subtr(int n) {
    num -= n;
    return *this;
}

ChVal& ChVal::ShowTwoNumber() {
    cout << num << endl;
    return *this;
}
