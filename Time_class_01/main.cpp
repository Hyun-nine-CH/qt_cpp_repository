#include "Time.h"

int main() {
    Time t1(7,30,20);
    cout<<t1.showTime()<<endl;
    cout<<"시간-초단위:"<<t1.CalSecond()<<endl;

    Time t2(4,50,23);
    if(t1>=t2) {
        cout<<t1.showTime()<<"이 "<<t2.showTime()<<"보다 크거나 같다!!";
        cout<<endl;
    }else {
        cout<<t2.showTime()<<"이 "<<t1.showTime()<<"보다 크거나 같다!!";
        cout<<endl;
    }
    if(t1<=t2) {
        cout<<t2.showTime()<<"이 "<<t1.showTime()<<"보다 크거나 같다!!";
        cout<<endl;
    }else {
        cout<<t1.showTime()<<"이 "<<t2.showTime()<<"보다 크거나 같다!!";
        cout<<endl;
    }
    return 0;
}
