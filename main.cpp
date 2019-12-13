#include <iostream>
#include "Exception.h"

using namespace std;
using namespace DTLib;


int main()
{
    try
    {
        THROW_EXCEPTION(Exception,"test");  //为了测试，还需要将纯虚特性去掉
    }
    catch(const Exception& e)
    {
        cout << " catch(const Exception& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
