/*
    编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
*/

#include<iostream>

int main(){
    std::cout << "Enter two numbers:" << std::endl;
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    std::cout << "Numbers between " << num1 << " and " << num2 << " are"
                << std::endl;

    if(num1 > num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }               

    while(num1 <= num2){
        std::cout << num1 << std::endl;
        ++num1;
    }

    return 0;
}