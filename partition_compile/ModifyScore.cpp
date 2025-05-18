#include "ModifyScore.h"

void ModiSC::ShowMScore() {
    cout<<"점수: "<<Score<<endl;
}

void ModiSC::setMScore(const int s) {
    Score=s;
}

int ModiSC::getMScore() {
    return Score;
}
