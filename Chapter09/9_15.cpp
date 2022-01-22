#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> ivec_1 = {1, 2, 3, 4};
    vector<int> ivec_2 = {2, 3, 4, 5};

    cout << (ivec_1 == ivec_2 ? "ture" : "false") << endl;

    return 0;
}