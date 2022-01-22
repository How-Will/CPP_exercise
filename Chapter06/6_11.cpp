#include<iostream>
using namespace std;

void reset(int& val){
    val = 0;
}

int main(){
    int n = 4;
    cout <<"before: n = " << n << endl;
    reset(n);
    cout <<"after: n = " << n <<endl;
    return 0;
}