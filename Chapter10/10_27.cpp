#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

int main(){
    vector<int> ivec{1, 2, 2, 3, 4, 4, 6, 5, 6, 6};
    list<int> ilst;
    unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
    for(const auto i : ilst){
        cout << i << " ";
    }

    cout << endl;

    return 0;
}