#include <iostream>
#include "SmartPointer.h"

using namespace std;
using namespace DTLib;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }


};

int main()
{

    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> nsp;

    nsp = sp;
    cout << sp.isNull() << endl;
    cout << nsp.isNull() << endl;

    cout << "sp = " << sp.get() << endl;
    cout << "nsp = " << nsp.get() << endl;


    return 0;
}
