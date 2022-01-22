#include "7_12.h"
#include <iostream>
using namespace std;

int main() {
  Sales_data total(cin); //读入第一笔交易
  Sales_data trans;
  while (read(cin, trans)) {
    if (total.isbn() == trans.isbn())
      total.combine(trans);
    else {
      print(cout, total) << endl;
      total = trans;
    }
  }
  print(cout, total) << endl;
  return 0;
}