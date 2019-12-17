#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "Exception.h"

namespace DTLib
{
template <typename T>
class SeqList: public List<T>
{
protected:
    T* m_array;   //该指针指向具体的顺序存储空间，在子类中实现。
    int m_length; //当前线性表长度
public:
    bool insert(int i, const T& e)
    {
        bool ret =((0 <= i) && (i <= m_length));
        ret = ret && (m_length < capacity() );

        if(ret)
        {
            for(int p=m_length-1; p>=i; p--)
            {
                m_array[p+1] = m_array[p];
            }

            m_array[i] = e;
            m_length++;
        }

        return ret;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    bool remove(int i)
    {
        bool ret =((0 <= i) && (i < m_length));

        if(ret)
        {
            for(int p=i; p<m_length-1; p++)
            {
                m_array[p] = m_array[p+1];
            }

            m_length--;
        }

        return ret;
    }

    bool set(int i, const T& e)
    {
         bool ret =((0 <= i) && (i < m_length));

         if(ret)
         {
             m_array[i] = e;
         }

         return ret;
    }

    bool get(int i, T& e) const
    {
        bool ret =((0 <= i) && (i < m_length));

        if(ret)
        {
            e = m_array[i];
        }

        return ret;
    }
    int length() const
    {
        return m_length;
    }
    void clear()
    {
        m_length = 0;
    }
    //顺序存储线性表的数组访问方式
    T& operator[](int i)
    {
       if((0 <= i) && (i < m_length))
       {
           return m_array[i];
       }
       else
       {
           THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter i is invalid...");
       }

    }
    T operator[] (int i) const
    {
#if 0
        if((0 <= i) && (i < m_length))
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter i is invalid...");
        }
#endif
        //考虑代码的复用性，那么就可以直接使用上面的非const版本的重载函数。
        //此时如果调用到了T operator[] (int i) const，说明当前对象是一个const对象，可以考虑将当前对象的const属性去掉，就可以使用T& operator[](int i)的实现了
        return const_cast<SeqList<T&> >(*this)[i];
    }
    //顺序存储空间的容量
    virtual int capacity() const = 0; //代表顺序存储空间的最大容量，然而顺序存储空间的具体指定并不是在SeqList这个类中完成的。在其子类中实现
};

}

#endif // SEQLIST_H

