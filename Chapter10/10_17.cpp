#include "Sales_data.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    vector<Sales_data> data_vec;
    Sales_data d_1 = Sales_data("978-7-121-15535-2", 10, 5.1);
    Sales_data d_2 = Sales_data("0-201-703530X", 20, 4.1);
    Sales_data d_3 = Sales_data("4-201-703530X", 30, 2.1);
    data_vec.push_back(d_1);
    data_vec.push_back(d_2);
    data_vec.push_back(d_3);


    sort(data_vec.begin(), data_vec.end(), 
        [](const Sales_data& data1, const Sales_data& data2){
            return data1.isbn() < data2.isbn();
        });

    for(const auto& elem : data_vec){
        print(cout, elem) << endl;
    }

    return 0;
}