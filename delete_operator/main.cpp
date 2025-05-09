//*
#include <iostream>

using namespace std;

int main()
{
    int *p = NULL;
    p = new int(0);
    if(p == NULL) {
        cout<<"동적 메모리 할당 실패\n";
        return 1;
    }
    cout<<"정수를 입력하세요:";
    cin>>*p;
    cout<<"입력된 정수는 "<<p[0]<<"\n";
    delete p;
    p = NULL;
    return 0;
}
/*/

/*
#include <iostream>

using namespace std;

int void() {
    int num;
    cin>>num;
    int *data = new int[num];
    for(int i=0; i<num; i++)
        cin>>data[i];
    delete [] data;
    //delete data;
    return 0;
}
*/
