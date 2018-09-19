//
// Created by xiaowei on 2018/9/19.
//
/* 在模板模式（Template Pattern）中，一个抽象类公开定义了执行它的方法的方式/模板。
 * 它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式进行。这种类型的设计模式属于行为型模式
 *
 * 意图：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。
 *      模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
 * */
#include <iostream>

class game
{
public:
    game() {

    }
    virtual ~game() {

    }
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;
    virtual void play()
    {
        initialize();
        startPlay();
        endPlay();
    }
};

class Cricket:public game
{
public:
    Cricket() {
        std::cout << "Cricket() " << std::endl;
    }
    virtual ~ Cricket() {
        std::cout << "~Cricket " << std::endl;
    }
    virtual void  initialize() {
        std::cout << "Cricket initialize" << std::endl;
    }
    virtual void startPlay() {
        std::cout << "Cricket startPlay" << std::endl;
    }
    virtual void endPlay() {
        std::cout << "Cricket endPlay" << std::endl;
    }
};

class Football:public game
{
public:
    Football() {
        std::cout << "Football() " << std::endl;
    }
    virtual ~Football() {
        std::cout << "~Football " << std::endl;
    }
    virtual void  initialize() {
        std::cout << "Football initialize" << std::endl;
    }
    virtual void startPlay() {
        std::cout << "Football startPlay" << std::endl;
    }
    virtual void endPlay() {
        std::cout << "Football endPlay" << std::endl;
    }
};

int main() {
    game * mygame = new Football();
    mygame->play();
    delete mygame;
    mygame = new Cricket();
    mygame->play();
    delete mygame;
}
