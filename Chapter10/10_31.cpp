#include<iterator>
#include<algorithm>
#include<functional>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");

    vector<int> ivec;

    copy(in_iter, eof, back_inserter(ivec));
    sort(ivec.begin(), ivec.end());

    unique_copy(ivec.begin(), ivec.end(),
                out_iter);

    cout << endl;

    return 0;
}