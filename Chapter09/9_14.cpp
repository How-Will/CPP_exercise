#include<iostream>
#include<list>
#include<vector>
#include<string>

using namespace std;

int main(){
    list<const char*> clist = {"hello", "world"};

    vector<string> svec;
    svec.assign(clist.begin(), clist.end());
    for (auto s : svec)
        cout << s << endl;

    return 0;
}