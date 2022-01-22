#include<iostream>
#include<string>
using namespace std;

void FindDigit(const string& target){
    string numbers = "1234567890";
    string::size_type pos = 0;
    // 每步循环查找name中的下一个数
    while((pos = target.find_first_of(numbers, pos)) != string::npos){
        cout << "found number at index: " << pos << " element is "
            << target[pos] << endl;
        pos++;  //移动到下一个字符
    }
}

void FindLetter(const string& target){
    string numbers = "1234567890";
    string::size_type pos = 0;
    // 每步循环查找name中的下一个字母
    while((pos = target.find_first_not_of(numbers, pos)) != string::npos){
        cout << "found number at index: " << pos << " element is "
            << target[pos] << endl;
        pos++;  //移动到下一个字符
    } 
}



int main(){
    FindDigit("ab2c3d7R4E6");

    cout << endl;

    FindLetter("ab2c3d7R4E6");
    
    return 0;
}