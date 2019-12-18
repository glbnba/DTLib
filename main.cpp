#include <iostream>
#include "DynamicArray.h"

using namespace std;
using namespace DTLib;



int main()
{

    DynamicArray<int> sl(5);

    for(int i=0; i<sl.length(); i++)
    {
        sl[i] = i * i;
    }

    for(int i=0; i<sl.length(); i++)
    {
        cout << sl[i] << endl;
    }

    cout << endl;
    DynamicArray <int> s2(5);
    s2 = sl;
    for(int i=0; i<s2.length(); i++)
    {
        cout << s2[i] << endl;
    }

    cout << endl;

    s2.resize(10);
    for(int i=0; i<10; i++)
    {
        cout << s2[i] << endl;
    }
    return 0;

}
