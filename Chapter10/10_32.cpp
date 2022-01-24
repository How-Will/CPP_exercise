#include<iostream>
#include"Sales_item.h"
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>

using namespace std;

bool compareIsbn(const Sales_item& item1, const Sales_item& item2){
    return item1.isbn() < item2.isbn();
}

int main(){
    istream_iterator<Sales_item> in_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    vector<Sales_item> itemVec(in_iter, eof);

    sort(itemVec.begin(), itemVec.end(), compareIsbn);

    auto iter_beg = itemVec.cbegin();
    while (iter_beg != itemVec.cend()) {
        auto iter_end =
            find_if(iter_beg, itemVec.cend(), [&iter_beg](const Sales_item& item) {
            return iter_beg->isbn() != item.isbn();
            });
        *out_iter++ = accumulate(iter_beg, iter_end, Sales_item(iter_beg->isbn()));
        iter_beg = iter_end;
    }

    return 0; 
}