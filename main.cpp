#include <iostream>
#include <String>
#include "LinkList.h"

using namespace std;
using namespace DTLib;




int main()
{
    LinkList<int> list;

    for(int i=0; i<5; i++)
    {
        list.insert(0,i);
    }

    /*将游标移动到第0个节点所在的位置list.move(0)
    list.end()判断当前游标是否已达到末尾；
    list.next()移动游标
    意义就是先将指针指向第0个数据元素，打印第0个数据元素的值；
    然后移动一次，移动一次后再来获取数据元素的值...时间复杂度就是O(n)
    */
    for(list.move(0); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }

    //可以只遍历下标为偶数的数据元素
    for(list.move(0,2); !list.end(); list.next())
    {
        cout << list.current() << endl;
    }




    return 0;

}
