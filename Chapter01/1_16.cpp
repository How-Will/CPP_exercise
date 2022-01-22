#include<iostream>
using namespace std;

int main(){
    int num = 0;
    int sum = 0;
    cout << "Please enter a group of numbers(q to quit): ";
    while(cin >> num){
        sum += num;
    }
    cout << "Sum is: " << sum <<endl;

    return 0;
}