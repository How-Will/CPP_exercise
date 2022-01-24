#include<iterator>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

int main(){
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilst_1;
    list<int> ilst_2;
    list<int> ilst_3;

    copy(ivec.cbegin(), ivec.cend(), inserter(ilst_1, ilst_1.begin()));
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst_2));
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst_3));

    for(const auto it : ilst_3){
        cout << it << " " << endl;
    }

    return 0;
}