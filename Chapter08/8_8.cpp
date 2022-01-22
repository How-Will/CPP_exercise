#include<fstream>
#include<iostream>
#include"Sales_data.h"

using namespace std;

int main(int argc, char const* argv[]){
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::out | ofstream::app);
    Sales_data total;
    if(read(input, total)){ //读取第一条数据
        Sales_data trans;
        while (read(input, trans)){ //读取剩下的数据
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else{
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }else{
        cerr << "No data!" << endl;
    }
    return 0;
}