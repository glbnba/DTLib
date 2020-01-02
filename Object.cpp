#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace DTLib
{
void* Object::operator new(unsigned int size) throw()
{
    return malloc(size);
}
void Object::operator delete(void* p)
{
    free(p);
}
void* Object::operator new[] (unsigned int size) throw()
{
    return malloc(size);
}

bool Object::operator ==(const Object& obj)
{
    return (this == &obj);  //比较地址是最好的选择
}

bool Object::operator !=(const Object& obj)
{
    return (this != &obj);
}
void Object::operator delete[](void* p)
{
    free(p);
}
Object::~Object()
{

}

}

