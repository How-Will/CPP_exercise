#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(){
    list<string> slist;
    string word;
    while(cin >> word)
        slist.push_back(word);

    for(auto iter = slist.begin(); iter != slist.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}