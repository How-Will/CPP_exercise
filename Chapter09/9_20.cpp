#include<iostream>
#include<list>
#include<deque>

using namespace std;

int main(){
    list<int> ilist = {1, 2, 3, 5, 7, 8, 9};
    deque<int> even_deq;
    deque<int> odd_deq;

    for(auto iter = ilist.begin(); iter != ilist.end(); iter++){
        if((*iter) % 2 == 0)  //偶数
            even_deq.push_back(*iter);
        else    //奇数
            odd_deq.push_back(*iter);
    }

    return 0;
}