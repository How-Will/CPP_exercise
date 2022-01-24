#include<vector>
#include<iostream>
#include<iterator>

using namespace std;

int main(){
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8};

    ostream_iterator<int> os_iter(cout, " ");

    auto iter = ivec.cend();

    while (iter != ivec.cbegin()){
        iter--;
        os_iter++ = *iter;
    }

    cout << endl;

    return 0;
}