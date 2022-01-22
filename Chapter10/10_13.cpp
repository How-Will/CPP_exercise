#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool myJudge(const string& s){
    return s.length() >= 5;
}

int main(){
    vector<string> words;
    string str;
    while(cin>>str){
        words.push_back(str);
    }

    auto end_partition = partition(words.begin(), words.end(), myJudge);
    words.erase(end_partition, words.end());
    for(const auto &s : words){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}