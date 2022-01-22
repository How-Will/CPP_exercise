#ifndef SCREEN_H
#define SCREEN_H

#include<iostream>
#include<string>
using namespace std;

class Screen{
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht * wd, ' '){
        
    }
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){

    }
    char get() const{
        return contents[cursor];
    }   //隐式内联
    inline char get(pos r, pos c) const;  //显式内联，获取光标位置的字符
    Screen &move(pos r, pos c); //移动光标
private:
    pos cursor = 0; //光标位置
    pos height = 0, width = 0; //screen大小
    string contents; //screen内容
};

inline char Screen::get(pos r, pos c) const{
    pos row = r * width;
    return contents[row + c];
}

Screen& Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;    
}

#endif