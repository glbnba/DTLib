#ifndef LIST_H
#define LIST_H

#include "Object.h"

namespace DTLib
{
template <typename T>
class List : public Object
{
protected:
    List(const List&);
    List& operator= (const List&);  //此处仅仅声明就可以了，不需要定义
public:
    List() {}  //既然上面提供了构造函数，编译器就不会给我们提供默认的构造函数了，因此我们需要定义一个，否则编译有问题。
    virtual bool insert(const T& e) = 0; //往线性表的尾部插入一个元素，因此将i省略掉。
    virtual bool insert(int i, const T& e) = 0;
    virtual bool remove(int i) = 0;
    virtual bool set(int i, const T& e) = 0;
    virtual bool get(int i, T& e) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;
};

}

#endif // LIST_H
