#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"
#include "Exception.h"

namespace DTLib
{
template <typename T>
class DynamicArray : public Array<T>
{
protected:
    T m_length;
public:
    DynamicArray(int length)
    {
        this->m_array = new T[length];

        if(this->m_array != NULL)
        {
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "No memory to create DynamicArray object...");
        }
    }
    //拷贝构造和赋值操作
    DynamicArray(const DynamicArray<T>& obj )
    {
        this->m_array = new T[obj.m_length];

        if(this->m_array != NULL)
        {
            this->m_length = obj.m_length;

            for(int i=0; i<m_length; i++)
            {
                this->m_array[i] = obj.m_array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "No memory to create DynamicArray object...");
        }
    }
    DynamicArray<T>& operator= (const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
            T* array = new T[obj.m_length];

            if(array != NULL)
            {
                for(int i=0; i<obj.m_length; i++)
                {
                    array[i] = obj.m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = obj.m_length;

                delete[] temp;
            }

            else
            {
                THROW_EXCEPTION(IndexOutOfBoundsException, "No memory to copy DynamicArray object...");
            }
        }

        return *this;
    }

    int length() const
    {
        return m_length;
    }
    void resize(int length) //动态重置数组的长度
    {
        if(m_length != length)
        {
            T* array = new T[length];

            if(array != NULL)
            {
                int size = (length < m_length) ? length : m_length;

                for(int i=0; i<size; i++)
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = length;

                delete[] temp;
            }
            else
            {
                THROW_EXCEPTION(IndexOutOfBoundsException, "No memory to resize DynamicArray object...");
            }
        }
    }

    ~DynamicArray()
    {
        delete[] this->m_array;
    }
};

}

#endif // DYNAMICARRAY_H

