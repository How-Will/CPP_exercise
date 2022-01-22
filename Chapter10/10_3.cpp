#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    vector<int> i_vec{1, 2, 3, 4, 5, 6};

    int total = accumulate(i_vec.cbegin(), i_vec.cend(), 0);

    cout << "Total: " << total << endl;
    return 0;
}