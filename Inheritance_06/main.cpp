#include <iostream>
#include "ConTest.h"

using namespace std;

int main() {
    CON1 *p_TEST = new CON1; // 인자가 존재하지 않는다.
    delete p_TEST;
    return 0;
}

/*
#ifndef _CONTEST_H_
#define _CONTEST_H_

#include <iostream>

using namespace std;

class CON1
{
public :
  CON1(const int c);
  //CON1( );
  ~CON1( );
protected:
  int c;
};

class CON2 : public CON1
{
public :
  CON2( );
  ~CON2( );
};

#endif
*/

/*
#include "ConTest.h"

//CON1::CON1( )
CON1::CON1(const int c) : c(c)
{
    cout << "*** CON1의생성자***" << endl;
    cout << "c=" << c << endl;
}

CON1::~CON1( )
{
    cout << "*** CON1의 소멸자***" << endl;
}

CON2::CON2( ) : CON1(200)
{
    cout << "*** CON2의 생성자***" << endl;
}

CON2::~CON2( )
{
    cout << "*** CON2의 소멸자***" << endl;
}
*/

/*
#include "ConTest.h"

int main( )
{
    CON2 *p_TEST = new CON2;

    delete p_TEST;

    return 0;
}
*/
