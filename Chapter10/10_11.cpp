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

//比较函数，用来按长度排序单词
bool isShorter(const string& s1, const string& s2){
    return s1.size() < s2.size();
}

int main(){
    vector<string> words;
    string str;
    while(cin>>str){
        words.push_back(str);
    }

    elimDups(words);

    stable_sort(words.begin(), words.end(), isShorter);

    for(const auto& elem : words){
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}