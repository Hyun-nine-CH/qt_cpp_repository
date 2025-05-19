#include <list>

using namespace std;

int main() {
    list<Shape*>list1;
    while(true) {
        switch(choice) {
        case1:
            list1.push_back(new Rectangle);
            break;
        case2:
            list1.push_back(new Ellipse);
            break;
        }
        Shape*& pShape = list1.back();
        pShape->SetStartPoint(x,y);

        pShape->SetEndPoint(x,y);
    }
    list<Shape*>::iterator it;
    for(it = list1.begin(); it!=list1.end();++it)
        (*it)->Draw();
    for(it=list1.begin();it!=list1.end(); ++it)
        delete (*it);
    return 0;
}
