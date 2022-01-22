#include<iostream>
using namespace std;

unsigned Abs(int val){
    return val >= 0 ? val : -val;
}

int main(){
    cout << Abs(-5) <<endl;
    cout << Abs(7) <<endl;
    return 0;
}