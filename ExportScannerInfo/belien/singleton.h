#ifndef BELIEN_SINGLETON_H
#define BELIEN_SINGLETON_H

template < class T > class Singleton {
public:
    Singleton() {}

    static T& GetInstance() {
        static T ins;
        return ins;
    }

    Singleton(const Singleton&) = delete;            // 关闭拷贝构造

    Singleton(const Singleton&&) = delete;           // 关闭右值拷贝构造

    Singleton& operator=(const Singleton&) = delete; // 关闭赋值运算重载函数

    virtual ~Singleton() {}
};

#endif