#include <iostream>

using namespace std;

const Point operator++(int) {
    const Point retobj(xpos, ypos);
    xpos+=1;
    ypos+=1;
    return retobj;
}
const Point operator--(Point &ref, int) {
    const Point retobj(ref);
    ref.xpos-=1;
    ref.ypos-=1;
    return retobj;
}
int main(void) {
    Point pos(3,5);
    (pos++)++;
    (pos--)--;
} // 보통 op++인 경우 이항연산자, ++op인 경우 단항연산자
