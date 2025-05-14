#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

#define HOUR_SEC 3600
#define MIN_SEC 60
using namespace std;

class Time {
private:
    uint hour, min, sec, t_sec;
public:
    Time();
    Time(uint hour, uint min, uint sec) {

    }
    uint CalSecond();
    uint getHour();
    uint getMin();
    uint getSec();
    void setHour(uint hour);
    void setMin(uint hour);
    void setSec(uint hour);
    string showTime();
    bool operator>=(Time timeObj);
    bool operator<=(Time timeObj);

};
#endif // TIME_H

bool Time::operator<=(Time timeObj) {
    this->CalSecond();
    timeObj.CalSecond();

    if(this->t_sec<=timeObj.t_sec)
        return true;
    else
        return false;
}

bool Time::operator>=(Time timeObj) {
    this->CalSecond();
    timeObj.CalSecond();

    if(this->t_sec>=timeObj.t_sec)
        return true;
    else
        return false;
}
