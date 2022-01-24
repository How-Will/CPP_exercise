#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main(){
    ifstream ifs("./10_29_input.txt");
    istream_iterator<string> str_it(ifs), eof;
    ostream_iterator<string> str_out(cout, "\n");
    vector<string> svec;

    while(str_it != eof){
        svec.push_back(*str_it++);
    }

    for(const auto &s : svec){
        cout << s << endl;
    }

    return 0;
}