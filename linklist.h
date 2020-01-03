#ifndef LINKLIST
#define LINKLIST

#include "List.h"
#include "Object.h"
#include "Exception.h"

namespace DTLib
{
template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
    };

   // mutable Node m_header;//加上mutable就允许在const成员函数中取m_header的地址了
    /*这个类型的定义仅仅是为了头结点，非常巧妙。*/
    mutable struct : public Object
    {
        char reserved[sizeof(T)];
        Node* next;
    }m_header;
    int m_length;
    int m_step;
    Node* m_current;

    Node* position(int i) const
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);
        for(int p=0; p<i; p++)
        {
            ret = ret->next;
        }

        return ret;
    }

    virtual Node* create()
    {
        return  new Node();
    }

    virtual void destory(Node* pn)
    {
        delete pn;
    }


public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
        m_step = 1;
        m_current = NULL;
    }
    bool insert(const T& e) //往线性表的尾部插入一个元素，因此将i省略掉。
    {
        return insert(m_length,e);
    }
    bool insert(int i, const T& e)
    {
        bool ret = ((0 <=i) && (i <= m_length) );
        if(ret)
        {
            Node* node = create();

            if(node != NULL)
            {
                Node* current = position(i);
                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException,"no memory to insert new element...");
            }
        }

    }
    bool remove(int i)
    {
        bool ret = ((0<=i) && (i<m_length));

        if(ret)
        {
           Node* current = position(i);

            Node* toDel = current->next;
            toDel->next = current->next;
            destory(toDel);

            m_length--;
        }

        return ret;
    }
    bool set(int i, const T& e)
    {
        bool ret = ((0<=i) && (i<m_length));

        if(ret)
        {
            Node* current= position(i);

            current->next->value = e;
        }

        return ret;
    }

    T get(int i) const
    {
        T ret;

        if(get(i,ret))
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"invalid parameter i get element...");
        }

        return ret;
    }

    bool get(int i, T& e) const
    {
        bool ret = ((0<=i) && (i<m_length));

        if(ret)
        {
            Node* current = position(i);

            e = current->next->value;
        }

        return ret;
    }

    int find(const T& e)const
    {
        int ret = -1;
        int i=0;
        Node* node = m_header.next;
        while(node)
        {
            if(node->value == e)
            {
                ret = i;
                break;
            }
            else
            {
                node = node->next;
                i++;
            }
        }

        return ret;
    }

    bool move(int i, int step=1)
    {
        bool ret = (0 <= i) && (i < m_length) && (step > 0);
        if(ret)
        {
            m_current = position(i)->next;
            m_step = step;
        }

        return ret;
    }

    bool end() //用来判断当前的遍历是否结束
    {
       return (m_current == NULL);
    }

    T current() //返回当前游标所指向的节点数据元素的值
    {
        if(!end())
        {
            return m_current->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No value at current position...");
        }

    }

    bool next() //用于移动游标
    {
        int i = 0;

        while((i < m_step) && ( !end() ))
        {
            m_current = m_current->next;
            i++;
        }

        return (i == m_step);
    }

    int length() const
    {
        return m_length;
    }
    void clear()
    {
        while(m_header.next)
        {
            Node* toDel = m_header.next;
            m_header.next = toDel->next;
            destory(toDel);
        }

        m_length = 0;
    }

    ~LinkList()
    {
        clear();
    }
};

}

#endif // LINKLIST

