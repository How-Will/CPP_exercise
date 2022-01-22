#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
  Sales_data() = default; // 默认构造函数，执行默认初始化
  Sales_data(const string& s): bookNo(s){}
  Sales_data(const string& s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n){}
  Sales_data(istream& is);

  string bookNo;
  string bookName;
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

double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

istream &read(istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = data.units_sold * price;
  return is;
}

ostream &print(ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}  //因为使用到了类外的成员函数，必须在类外定义

// 类信息应该单独定义在头文件中，这里为了方便就免了

int main(){
    Sales_data data1;
    Sales_data data2("0-201-78345-X");
    Sales_data data3("0-201-78345-X", 3, 20);
    Sales_data data4(std::cin);

    return 0;
}