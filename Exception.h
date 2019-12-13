#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace DTLib
{
#define THROW_EXCEPTION(e,m) (throw e(m, __FILE__,__LINE__))

class Exception
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

}

#endif // EXCEPTION_H
