#include "ModifyScore.h"

void ModiSC::ShowScore() {
    cout<<"점수: "<<Score<<endl;
}

void ModiSC::setScore(const int s) {
    Score=s;
}

int ModiSC::getScore() {
    return Score;
}
