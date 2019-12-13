#include <iostream>
#include "Exception.h"

using namespace std;
using namespace DTLib;


int main()
{
    try
    {
        throw Exception("test", __FILE__,__LINE__);  //将析构函数定义成了纯虚函数，是不能定义对象的，为了测试，先将纯虚去掉。
    }
    catch(const Exception& e)
    {
        cout << " catch(const Exception& e)" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}
