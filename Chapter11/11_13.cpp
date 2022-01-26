#include<iostream>
#include<string>
#include<utility>
#include<vector>

using namespace std;

int main(){
    vector<pair<string, int>> pair_vec1;
    vector<pair<string, int>> pair_vec2;
    vector<pair<string, int>> pair_vec3;

    string str;
    int ival;

    while(cin>>str>>ival){
        pair_vec1.push_back(make_pair(str, ival));
        pair_vec2.push_back({str, ival});
        pair_vec3.push_back(pair<string, int>(str, ival));
    }

    return 0;
}