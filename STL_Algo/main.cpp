#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // 동적 배열을 생성 후 임의의 영문자를 추가
    vector<char> vec;
    vec.push_back('e');
    vec.push_back('b');
    vec.push_back('a');
    vec.push_back('d');
    vec.push_back('c');

    //sort() 함수를 사용해서 정렬한다.
    sort(vec.begin(), vec.end());

    //정렬 후 상태를 출력한다.
    cout<<"vector 정렬 후\n";
    vector<char>::iterator it;
    for(it=vec.begin(); it!=vec.end(); ++it)
        std::cout<<*it;
    return 0;
}
