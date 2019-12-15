#include <iostream>
#include "Staticlist.h"

using namespace std;
using namespace DTLib;



int main()
{
    StaticList<int, 5> sl;

    for(int i=0; i<sl.capacity(); i++)
    {
        sl.insert(0,i);  //每次都在线性表的头部进行插入
    }

    for(int i=0; i<sl.length(); i++)
    {
        cout << sl[i] << endl;
    }

    return 0;
}
