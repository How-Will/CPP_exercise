#include<iostream>
using namespace std;

unsigned fact(unsigned val){
    unsigned res = 1;
    while(val > 0){
        res *= val;
        val -= 1;
    }
    return res;
}

int main(){
    cout << fact(5) <<endl;
    return 0;
}