#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    vector<string> i_vec;

    string elem;
    while(cin>>elem){   // 读取int序列存入到vector中
        i_vec.push_back(elem);
    }

    cout << count(i_vec.cbegin(), i_vec.cend(), "hello") << " times" << endl;

    return 0;
}