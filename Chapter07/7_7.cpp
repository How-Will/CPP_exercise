#include"7_6.h"
#include<iostream>
#include<string>

using namespace std;

int main(){
    Sales_data total;

    if(read(cin, total)){
        Sales_data trans;
        while(read(cin, trans)){
            if(total.bookNo == trans.bookName){
                total.combine(trans);
            }else{
                print(cout, trans) << endl;
                total = trans;
            }
        }

        print(cout, total) << endl;
    }else{
        cerr << " No data?!" << endl;
        return -1;
    }
    return 0;
}