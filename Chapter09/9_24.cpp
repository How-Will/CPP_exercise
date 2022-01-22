#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> ivec;

    cout << ivec.at(0);
    cout << ivec[0];
    cout << ivec.front();
    cout << *(ivec.begin());

    return 0;
}