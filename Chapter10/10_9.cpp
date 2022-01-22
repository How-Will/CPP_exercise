#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

void elimDups(vector<string>& words){
    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());
}

int main(){
    vector<string> words;
    string str;
    while(cin>>str){
        words.push_back(str);
    }

    elimDups(words);

    for(auto elem : words){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}