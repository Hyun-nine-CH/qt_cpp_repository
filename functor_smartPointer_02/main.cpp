#include <iostream>

using namespace std;

class SortRule {
public:
    virtual bool operator()(int num1, int num2) const =0;
};

class AscendingSort : public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if(num1>num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if(num1<num2)
            return true;
        else
            return false;
    }
};

void SortData(const SortRule& functor) {
    for(int i=0; i<(idx-1); i++) {
        for(int j=0; j<(idx-1)-i; j++) {
            if(functor(arr[j], arr[j+1])) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

