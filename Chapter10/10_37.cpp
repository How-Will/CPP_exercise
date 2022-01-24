#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
#include<iostream>

using namespace std;


int main(){
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 9, 10};

    list<int> ilst;

    copy(ivec.crbegin() + 3, ivec.crend() - 2, front_inserter(ilst));

    for(const auto e : ilst){
        cout << e << " "; 
    }
    cout << endl;



    return 0;
}