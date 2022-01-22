#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> i_vec;

    int elem = 0;
    while(cin>>elem){   // 读取int序列存入到vector中
        i_vec.push_back(elem);
    }

    cout << count(i_vec.cbegin(), i_vec.cend(), 3) << " times" << endl;

    return 0;
}