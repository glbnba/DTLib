#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace DTLib
{
void* Object::operator new(unsigned int size) throw()
{
    cout << "void* Object::operator new" << size << endl;
    return malloc(size);
}
void Object::operator delete(void* p)
{
    cout << "void Object::operator delete" << p << endl;
    free(p);
}
void* Object::operator new[] (unsigned int size) throw()
{
    cout << "void* Object::operator new[]" << endl;
    return malloc(size);
}
void Object::operator delete[](void* p)
{
    cout << "void Object::operator delete[]" << endl;
    free(p);
}
Object::~Object()
{

}

}

