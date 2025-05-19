#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    m.insert(make_pair("A", 10));
    m.insert(make_pair("A", 20));
    m.insert(make_pair("A", 30));
    m.insert(make_pair("A", 40));
    m.insert(make_pair("A", 50));
    m["F"] = 100;
    for(auto i = m.begin(); i!=m.end(); ++i)
        cout<<"["<<i->first<<" "<<i->second<<"]";
    cout<<endl;
    auto i=m.find("A");
    cout<<i->first<<":"<<i->second<<endl;
    m.insert(make_pair("E", 150));

    return 0;
}
