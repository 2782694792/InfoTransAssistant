#ifndef BELIEN_SINGLETON_H
#define BELIEN_SINGLETON_H

template < class T > class Singleton {
public:
    Singleton() {}

    static T& GetInstance() {
        static T ins;
        return ins;
    }

    Singleton(const Singleton&) = delete;            // �رտ�������

    Singleton(const Singleton&&) = delete;           // �ر���ֵ��������

    Singleton& operator=(const Singleton&) = delete; // �رո�ֵ�������غ���

    virtual ~Singleton() {}
};

#endif