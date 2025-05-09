/*
#include <iostream>

using namespace std;

int main() {
    cout<<"즐거운 프로그래밍!!!"<<endl;
    return 0;
}
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream output;
    output.open("test.txt");
    output<<"즐거운 프로그래밍!!!"<<endl;
    output.close();
    return 0;
}
