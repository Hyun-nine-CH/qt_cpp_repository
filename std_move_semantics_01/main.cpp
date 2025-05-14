#include <iostream>

using namespace std;

class Integer {
public:
    int *val;
    Integer()=defalut;
    Integer(int val) {
        this->val=new int(val);
    }
    ~Integer() {
        delete val;
    }
};

Integer Add(const Integer& a, const Integer &b) {
    Integer tmp;
    tmp.val=new int(a.val + b.val);
    return tmp; // (없어진 포인터 tmp)
}

int main() {
    Integer i1(1), i2(3);
    i1.val=Add(i1,i2).val; // (포인터의 포인터로 들어가니까 주소)
    std::cout<<i1.val;
}

/*
Integer(Integer &&obj) {
    val=obj.val;
    obj.val=nullptr; // move()랑 동일함
}

class Integer {
public:
    int* val;
    Integer()=defalut;
    Integer(int val) {
        this->val=new int(val);
    }
    Integer(Integer &&obj) {
        this->val=obj.val;
        obj.val=nullptr;
    }
};

int main() {
    Integer i1(1);
    auto i2 = std::move(i1); // i1은 NULL임
    std::cout<<*i1.val; // *i1.val 이렇게 쓰면 안됨
}
*/
