#ifndef STATICLIST_H
#define STATICLIST_H

#include "seqlist.h"

namespace DTLib
{
template <typename T, int N>
class StaticList: public SeqList<T>
{
protected:
    T m_space[N]; //顺序存储空间，N为模板参数
public:
    StaticList() //指定父类成员的具体值
    {
        this->m_array = m_space;  //将父类的m_array这个指针指向子类的m_space这个数组
        this->m_length = 0;
    }
    int capacity() const
    {
        return N;
    }
};
}
#endif // STATICLIST_H

