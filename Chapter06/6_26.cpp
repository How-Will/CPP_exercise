#include<iostream>
using namespace std;

// argc: 表示数组中字符串的数量
// argv: 是一个数组，它的元素是指向C风格字符串的指针
int main(int argc, char *argv[]){
    for(size_t i = 0; i != argc; ++i){
        cout << argv[i] << endl;
    }    
    return 0;
}