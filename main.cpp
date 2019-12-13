#include <iostream>
#include "Exception.h"

using namespace std;
using namespace DTLib;


int main()
{
    try
    {
        THROW_EXCEPTION(InvalidParameterException,"test");
    }

    catch(const InvalidParameterException& e)
    {
        cout << " catch(const NoEnoughMemoryException& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }

    catch(const Exception& e)
    {
        cout << " catch(const Exception& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
