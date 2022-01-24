#include<algorithm>
#include<vector>
#include<string>
#include<functional>
#include<iostream>

using namespace std;

bool check_size(const string& s, string::size_type ival){
    return s.size() < ival;
}



int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6};

    auto it = find_if(ivec.begin(), ivec.end(),
            bind(check_size, "hello", placeholders::_1));

    if(it != ivec.end()){
        cout << *it << endl;
    }

    return 0;
}