#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace DTLib
{
void Exception::init(const char *message, const char *file, int line)
{
    //m_message = message; //直接进行这样的赋值，这样写可以吗？肯定不行，因为参数的message这个指针它指向的字符串有可能在栈上，有可能在堆空间中，还有可能在全局数据区。
                         //这样的话，没有办法控制message所指向的外部字符串的生命周期，所以说这样的写法是不安全的。可以拷贝一份字符串出来。
    m_message = strdup(message);  //将字符串复制到了堆空间。

    if(file != NULL)
    {
        char sl[16] = {0};
        itoa(line,sl,10);   //itoa在linux下是无法使用的，需要使用sprintf

        //m_location = malloc(strlen(file) + strlen(sl) + 2);  //malloc函数返回的是void*,将void*直接赋值给char*是不可以的。因此需要进行强制类型转换。使用static_cast
        m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));
        if(m_location != NULL)
        {
            m_location = strcpy(m_location,file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        }
        #if 0
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException,"void Exception::init");
        }
        /*如果m_location不为空，那么进行正常操作，如果为空，那么抛出内存不足的异常。这样解决，看似非常的完美，但是存在这样的问题：
        Exception这个类还没有创建，就将NoEnoughMemoryException这个子类扔出去了。这个地方可以根据抛出的异常，跟踪一下代码，就会发现出现死循环这种现象。
        通俗一点就是，老爸都没有，就将儿子扔出去了，从逻辑上是讲不通的。因此不能这样处理m_location为空的情况。
        最好的做法就是else这个分支就不要了*/
        #endif
    }
    else
    {
        m_location = NULL;
    }
}

Exception::Exception(const char* message)
{
    init(message,NULL,0);
}
Exception::Exception(const char* file, int line)
{
    init(NULL,file,line);
}
Exception::Exception(const char* message, const char* file, int line)
{
    init(message,file,line);
}

Exception::Exception(const Exception& e)
{
    m_location = strdup(e.m_location);
    m_message = strdup(e.m_message);
}
Exception& Exception::operator= (const Exception& e)
{
    if(this != &e)
    {
        free(m_location);
        free(m_message);
        m_location = strdup(e.m_location);
        m_message = strdup(e.m_message);
    }

    return *this;
}

const char* Exception::message() const
{
    return m_message;
}

const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_location);
    free(m_message);
}
}

