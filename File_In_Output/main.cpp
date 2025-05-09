/*
#include <iostream>

using namespace std;

int main() {
    cout<<"즐거운 프로그래밍!!!"<<endl;
    return 0;
}

*/

/*
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main() {
//    ofstream output;
//    output.open("test.txt");

    ofstream output("test.txt");

    // UTF-8 인코딩을 위한 locale 설정
    output.imbue(std::locale("en_US.UTF-8"));

    output<<"즐거운 프로그래밍!!!"<<endl;
    output.close();
    return 0;
}
*/

// 한국어 text file 인코딩 문제 생겨서 내용 확인 불가능, 파일 생성이 됨

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
