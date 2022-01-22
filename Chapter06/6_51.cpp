#include<iostream>
using namespace std;

// version 1
void f(){
    cout << "f()" << endl;
}

// version 2
void f(int){
    cout << "f(int)" << endl;
}

// version 3
void f(int, int){
    cout << "f(int, int)" << endl;
}

// version 4
void f(double, double = 3.14){
    cout << "f(double, double = 3.14)" << endl;
}
int main(){
    //f(2.56, 42); # ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}