#include<algorithm>
#include<iostream>
#include<list>
#include<iterator>
#include<string>

using namespace std;

void elimDup(list<string>& slst){
    // tslst.sort();
    slst.unique();
}

int main(){
    list<string> words;
    
    istream_iterator<string> is_iter(cin), eof;
    ostream_iterator<string> os_iter(cout, " ");

    while(is_iter != eof){
        words.push_back(*is_iter);
        is_iter++;
    }

    elimDup(words);

    for(const auto s : words){
        *os_iter++ = s;
    }

    cout << endl;

    return 0;
}