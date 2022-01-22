#include<list>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    list<int> ilist = {1, 2, 3, 4, 5};
    vector<int> ivec = {1, 2, 3, 4}; 

    vector<double> dvec(ilist.begin(), ilist.end());
    vector<double> dvec_2(ivec.begin(), ivec.end());



    for (auto d : dvec)
        cout << d << endl;
    for (auto d : dvec_2)
        cout << d << endl;

    return 0;
}