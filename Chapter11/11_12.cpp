#include<iostream>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int main(){
    vector<pair<string, int>> pair_vec;
    string str;
    int ival;

    while(cin>>str>>ival){
        pair_vec.push_back(make_pair(str, ival));
    }

    return 0;
}