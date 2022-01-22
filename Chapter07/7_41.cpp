#include <iostream>
#include <string>

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

 public:
  //非委托构造函数
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
          std::cout << "Sales_data(const string&, unsigned, double)" << std::endl;
      }
  //委托构造函数
  Sales_data() : Sales_data("", 0, 0.0f){
      std::cout << "Sales_data()" << std::endl;
  }
  Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {
      std::cout << "Sales_data(const string&)" << std::endl;
  }
  Sales_data(std::istream &);

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

 private:
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
  double avg_price() const;
};

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = data.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

int main(){
    Sales_data data1;
    Sales_data data2("abc");

    return 0;
}