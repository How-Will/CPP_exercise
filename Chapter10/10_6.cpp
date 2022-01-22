#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main(){
    list<int> i_list = {1, 2, 3, 5, 6};

    fill_n(i_list.begin(), i_list.size(), 0);

    for(auto elem : i_list){
        cout << elem << endl;
    }

    return 0;
}