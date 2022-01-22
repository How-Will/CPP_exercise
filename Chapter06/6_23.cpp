#include<iostream>
using namespace std;

void print(int val){
    cout << val <<endl;
}

void print(int* p_beg, int* p_end){
    while (p_beg != p_end)
    {
        cout << *p_beg++ << endl;
    }
}

int main(){
    int i = 0, j[2] = {0, 1};
    print(i);
    print(begin(j), end(j));
    return 0;
}