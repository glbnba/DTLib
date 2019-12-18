#include <iostream>
#include "StaticArray.h"

using namespace std;
using namespace DTLib;



int main()
{
    StaticArray<int ,5> sl;

    for(int i=0; i<sl.length(); i++)
    {
        sl[i] = i * i;
    }

    for(int i=0; i<sl.length(); i++)
    {
        cout << sl[i] << endl;
    }

    return 0;

}
