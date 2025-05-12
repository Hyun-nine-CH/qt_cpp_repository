#include <iostream>

using namespace std;

class IntSample {
public:
    void ShowScore();
    void setScore(const int s);
    int getScore();

private:
    int Score;
};

void IntSample::ShowScore() {
    cout<<"점수: "<<Score<<endl;
}

void IntSample::setScore(const int s) {
    Score=s;
}

int IntSample::getScore() {
    return Score;
}

int main() {
    IntSample Obj;

    Obj.setScore(100);
    cout<<"점수: "<<Obj.getScore()<<endl;
    return 0;
}
