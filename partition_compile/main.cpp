#include "IntSample.h"
#include "ModifyScore.h"

int main() {
    IntSample Obj;
    ModiSC MObj;

    Obj.setScore(100);
    MObj.setScore(101);

    cout<<"점수: "<<Obj.getScore()<<endl;
    cout<<"변경된 점수: "<<MObj.getScore()<<endl;
    MObj.ShowScore();

    return 0;
}
