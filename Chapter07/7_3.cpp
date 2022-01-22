#include"7_2.h"
#include<iostream>
#include<string>

using namespace std;

int main(){
    Sales_data total;
    double price = 0;

    if(cin >> total.bookNo >> total.units_sold >> price){
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> price){
            if(total.bookNo == trans.bookName){
                trans.revenue = trans.units_sold * price;
                total.combine(trans);
            }else{
                cout << total.bookNo << " " << total.units_sold << " "
                     << total.revenue << " " << total.revenue / total.units_sold
                     <<endl;
                total = trans;
            }
        }

        cout << total.bookNo << " " << total.units_sold << " " << total.revenue
             << " " << total.revenue / total.units_sold << endl;
    }else{
        cerr << " No data?!" << endl;
        return -1;
    }
    return 0;
}