#include <iostream>
template<class T>
class Singleton
{
public:
    //返回引用避免外人delete该实例
    static T & GetInstance() {
        if (!_singleton) {
            _singleton = new T();
        }
        return *_singleton;
    }
protected:
    //默认构造函数设置为保护类型，为了让继承，也为了不让其他人构造
    Singleton() {

    }
    ~Singleton() {

    }
private:
    //防止被修改
    Singleton(const Singleton &sl) {

    }
    Singleton & operator = (const Singleton &sl) {

    }
protected:
    static T* _singleton;
};

template<class T>
T* Singleton<T>::_singleton = NULL;


class MyMessage : public Singleton<MyMessage>
{
public:
    void printHello() {
        std::cout << "hello" << std::endl;
    }
    void printGoodBye() {
        std::cout << "GoodBye" << std::endl;
    }
};

int main()
{
    MyMessage::GetInstance().printHello();
    MyMessage::GetInstance().printGoodBye();
    return 0;
}
