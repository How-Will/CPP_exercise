#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(){
    deque<string> sdeq;
    string word;
    while(cin >> word)
        sdeq.push_back(word);

    for(auto iter = sdeq.begin(); iter != sdeq.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}