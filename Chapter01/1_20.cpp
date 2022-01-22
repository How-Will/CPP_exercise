#include<iostream>
using namespace std;
#include "Sales_item.h"

int main(){
    Sales_item item;
    while (cin >> item) {
        cout << item << endl;
    }
    return 0;
}