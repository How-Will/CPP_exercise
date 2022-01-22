#include<iostream>
using namespace std;

unsigned counter(){
    static unsigned count = 0;
    return count++;
}

int main(){
    for(int i = 0; i < 5; i++){
        cout << counter() <<endl;
    }
    return 0;
}