#include<vector>
#include<iostream>
#include<iterator>

using namespace std;

int main(){
    vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8};

    ostream_iterator<int> os_iter(cout, " ");

    for(vector<int>::reverse_iterator r_iter = ivec.rbegin(); r_iter != ivec.rend(); r_iter++){
        os_iter++ = *r_iter;
    }

    cout << endl;

    return 0;
}