#ifndef OBJECT_H
#define OBJECT_H

namespace DTLib
{
class Object
{
public:
    void* operator new(unsigned int size) throw();  //在堆空间中创建单个对象时，就会调用这个new的重载实现了.throw表示当前这个函数不会抛出任何异常的。
    void operator delete(void* p);
    void* operator new[] (unsigned int size) throw(); //在堆空创建对象数组时
    void operator delete[](void* p);
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    virtual ~Object() = 0 ;
};

}

#endif // OBJECT_H
