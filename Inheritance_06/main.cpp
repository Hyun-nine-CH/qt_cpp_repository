#include <iostream>
#include "ConTest.h"

using namespace std;

int main() {
    CON1 *p_TEST = new CON1; // 인자가 존재하지 않는다.
    delete p_TEST;
    return 0;
}
