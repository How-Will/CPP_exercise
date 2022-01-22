#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>
using namespace std;

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    double revenue = 0.0;  // 总收入

    Sales_data &combine(const Sales_data &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    string isbn() const { return bookNo; }

    double avg_price() const;
};

Sales_data add(const Sales_data &data1, const Sales_data &data2){
    Sales_data sum = data1;
    return sum.combine(data2);
}

istream& read(istream& is, Sales_data& data){
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& data){
    os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
    << data.avg_price();
    return os;
}

#endif