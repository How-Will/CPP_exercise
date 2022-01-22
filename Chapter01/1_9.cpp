/*
    编写程序，使用 while 循环将 50 到 100 的整数相加。
*/

#include<iostream>
using namespace std;

int main(){
    int i = 50, sum = 0;    //sum, use to calculate the result of adding numbers
    while(i < 101){
        sum += i;
        ++i;
    }

    cout << "Sum of 50 to 100 inclusive is " << sum << endl;
    return 0;
}