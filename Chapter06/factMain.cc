#include<iostream>
#include "Chapter6.h"
using namespace std;

int main(){
    cout << Abs(-6) << endl;

    unsigned v;
    cout << "Please input a number: ";
    cin >> v;
    cout << v << "! is " << fact(v) << endl;
    return 0;
}