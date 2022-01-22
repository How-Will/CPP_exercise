#include<iostream>
#include<list>
#include<vector>

using namespace std;

// list 和 vector 是两种不同类型的容器，不能使用关系运算符比较
int main(){
    vector<int> ivec_1 = {1, 2, 3, 4, 5, 6};
    list<int> ilist_1 = {4, 3, 5, 6, 1, 7, 8};
    vector<int> ivec_2(ilist_1.begin(), ilist_1.end());
    list<int> ilist_2 = {1, 2, 3, 4, 5, 6};
    vector<int> ivec_3(ilist_2.begin(), ilist_2.end());

    cout << (ivec_1 == ivec_2 ? "True" : "False") << endl;
    cout << (ivec_1 == ivec_3 ? "True" : "False") << endl;


    return 0;
}