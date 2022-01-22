#include<iostream>
using namespace std;

void fact(){
    unsigned val = 0;
    cout << "Please enter a number: ";
    cin >> val;
    unsigned res = 1;
    for(auto i = val; i > 1; --i){
        res *= i;
    }
    cout << val << "! is " << res << endl;
}

int main(){
    fact();
    return 0;
}