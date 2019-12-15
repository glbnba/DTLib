#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace DTLib
{
#define THROW_EXCEPTION(e,m) (throw e(m, __FILE__,__LINE__))

class Exception : public Object
{
protected:
    char* m_location;
    char* m_message;
    void init(const char* message, const char* file, int line);
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);

    Exception(const Exception& e);
    Exception& operator= (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0; //纯虚析构函数，纯虚函数需要提供实现吗？纯虚函数是不需要提供实现的，等待子类去实现。但是这个地方是个例外，C++规定只要自定义了析构函数，不管
                              //这个析构函数是不是纯虚函数，一定要提供实现。为什么？在析构一个对象的时候，最后肯定会调用到父类的析构函数，
};

class ArithmetricException:public Exception
{
public:
    ArithmetricException():Exception(0) {}   //我认为这个实现没有必要
    ArithmetricException(const char* message):Exception(message) {}
    ArithmetricException(const char* file, int line):Exception(file, line) {}
    ArithmetricException(const char* message, const char* file, int line):Exception(message,file,line) {}

    ArithmetricException(const ArithmetricException& e):Exception(e) {}
    ArithmetricException& operator = (const ArithmetricException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

class NullPointerException:public Exception
{
public:
    NullPointerException():Exception(0) {}   //我认为这个实现没有必要
    NullPointerException(const char* message):Exception(message) {}
    NullPointerException(const char* file, int line):Exception(file, line) {}
    NullPointerException(const char* message, const char* file, int line):Exception(message,file,line) {}

    NullPointerException(const NullPointerException& e):Exception(e) {}
    NullPointerException& operator = (const NullPointerException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

class IndexOutOfBoundsException:public Exception
{
public:
    IndexOutOfBoundsException():Exception(0) {}   //我认为这个实现没有必要
    IndexOutOfBoundsException(const char* message):Exception(message) {}
    IndexOutOfBoundsException(const char* file, int line):Exception(file, line) {}
    IndexOutOfBoundsException(const char* message, const char* file, int line):Exception(message,file,line) {}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e) {}
    IndexOutOfBoundsException& operator = (const IndexOutOfBoundsException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

class NoEnoughMemoryException:public Exception
{
public:
    NoEnoughMemoryException():Exception(0) {}   //我认为这个实现没有必要
    NoEnoughMemoryException(const char* message):Exception(message) {}
    NoEnoughMemoryException(const char* file, int line):Exception(file, line) {}
    NoEnoughMemoryException(const char* message, const char* file, int line):Exception(message,file,line) {}

    NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e) {}
    NoEnoughMemoryException& operator = (const NoEnoughMemoryException& e)
    {
        Exception::operator =(e);

        return *this;
    }

};

class InvalidParameterException:public Exception
{
public:
    InvalidParameterException():Exception(0) {}   //我认为这个实现没有必要
    InvalidParameterException(const char* message):Exception(message) {}
    InvalidParameterException(const char* file, int line):Exception(file, line) {}
    InvalidParameterException(const char* message, const char* file, int line):Exception(message,file,line) {}

    InvalidParameterException(const InvalidParameterException& e):Exception(e) {}
    InvalidParameterException& operator = (const InvalidParameterException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

class InvalidOperationException:public Exception
{
public:
    InvalidOperationException():Exception(0) {}   //我认为这个实现没有必要
    InvalidOperationException(const char* message):Exception(message) {}
    InvalidOperationException(const char* file, int line):Exception(file, line) {}
    InvalidOperationException(const char* message, const char* file, int line):Exception(message,file,line) {}

    InvalidOperationException(const InvalidOperationException& e):Exception(e) {}
    InvalidOperationException& operator = (const InvalidOperationException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};
}

#endif // EXCEPTION_H
