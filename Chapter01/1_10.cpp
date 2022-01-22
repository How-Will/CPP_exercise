/*
    除了 ++ 运算符将运算对象的值增加 1 之外，还有一个递减运算符 (--) 实现将值减少 1。编写程序，
    使用递减运算符在循环中按递减顺序打印出 10 到 0 之间的整数。
*/

#include<iostream>
using namespace std;

int main(){
    int num = 10;
    while(num > 0){
        cout<< num << endl;
        --num;
    }
    return 0;
}