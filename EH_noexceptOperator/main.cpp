#include <iostream>

using namespace std;

void handler() {
    cout<<"in handler"<<endl;
}

void f1(void) noexcept(false) {         // throw(int)
    cout<<"About to throw 1"<<endl;
    if (1)
        throw 1;
}

void f2(void) noexcept {                // throw()
    try {
        f1();
    }
    catch(...){
        handler();
//        throw;
    }
}
int main() {
//    f1();

    try {
        f2();
    }
    catch(...) {
        cout<<"Caught exception from f2"<<endl;
    }
}

/*
#include <iostream>

using namespace std;

void handler()
{
  cout << "in handler" << endl;
}

void f1(void) noexcept(false) // throw(int)
{
  cout << "About to throw 1" << endl;
  if (1)
    throw 1;
}

void f2(void) noexcept //throw()
{
  try {
    f1();
  }
  catch(...) {
    handler();
    throw;
  }
}

int main() {
  //   f1();

  try {
    f2();
  }
  catch(int n) {
    cout << n << endl;
    cout << "Caught exception from f2" << endl;
  }
}
*/
