#include<algorithm>
#include<iostream>
#include<string>
#include<vector>


using namespace std;

void elimDups(vector<string>& svec){
    sort(svec.begin(), svec.end());
    auto endUnique = unique(svec.begin(), svec.end());
    svec.erase(endUnique, svec.end());
}

void biggies(vector<string>& words, vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string& a, const string& b){
                    return a.size() < b.size();
                });

    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string& a){ return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << (count > 2 ? "words" : "word") 
        << " of length " << sz << " or longer" << endl;
    
    for_each(wc, words.end(),
            [](const string& s){ cout << s << " "; });
    cout << endl;
}

int main(){

    vector<string> svec{"c++",     "primer", "fifth",
                                "edition", "hi",     "abc"};
    biggies(svec, 5);

    return 0;
}