#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<int>& vec){
    if(vec.empty())
        return;
    cout << vec.back();
    vec.pop_back();
    print_vector(vec);
}


int main(){
    vector<int> iv = {1, 2, 3, 4, 5};
    print_vector(iv);
    return 0;
}