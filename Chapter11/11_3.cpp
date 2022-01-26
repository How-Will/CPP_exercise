#include<iterator>
#include<map>
#include<iostream>
#include<set>

using namespace std;

int main(){
    //统计输入中每个单词出现的次数
    map<string, size_t> word_count;
    istream_iterator<string> is_iter(cin), eof;

    while(is_iter != eof){
        ++word_count[*is_iter++];
    }

    for(const auto &w : word_count){
        cout << w.first << " occurs " << w.second
            << (w.second > 1 ? " times" : " time") << endl;
    }


    return 0;
}