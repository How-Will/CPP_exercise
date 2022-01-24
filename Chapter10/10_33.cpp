#include<iterator>
#include<iostream>
#include<fstream>

using namespace std;

void myStream(const string& in_file, const string& out_file_1, const string& out_file_2){
    ifstream ifs(in_file);
    ofstream ofs_1(out_file_1), ofs_2(out_file_2);

    istream_iterator<int> in_iter(ifs), eof;
    ostream_iterator<int> out_iter_1(ofs_1, " "), out_iter_2(ofs_2, "\n");

    while (in_iter != eof){
        if(*in_iter % 2){
            // odd
            out_iter_1 = *in_iter;
        }else{
            out_iter_2 = *in_iter;
        }
        in_iter++;
    }
}

int main(){
    myStream("10_33.txt", "10_33_odd.txt", "10_33_even.txt");

    return 0;
}