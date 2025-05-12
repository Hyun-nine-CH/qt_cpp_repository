#include "IntSample.h"

void IntSample::ShowScore() {
    cout<<"점수: "<<Score<<endl;
}

void IntSample::setScore(const int s) {
    Score=s;
}

int IntSample::getScore() {
    return Score;
}
