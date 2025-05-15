#ifndef STR_H
#define STR_H

#define MAX 50
#include <iostream>
#include <string>
using namespace std;

class StringCharArray : public string {
public:
    void toCharArray(char* str);
};

#else
#endif // STR_H
