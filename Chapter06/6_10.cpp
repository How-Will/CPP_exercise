#include<iostream>
using namespace std;

void swap(int* v1, int* v2){
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int main(){
    int a = 1, b = 2;
    cout << "before : a = "<< a << ", b = "<< b <<endl;
    swap(&a, &b);
    cout << "after : a = "<< a << ", b = "<< b <<endl;
    return 1;
}
