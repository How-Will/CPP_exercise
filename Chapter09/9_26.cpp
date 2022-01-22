#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    
    vector<int> ivec;
    list<int> ilist;
    for (auto a : ia){
        ivec.push_back(a);
        ivec.push_back(a);
    }

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        if (!((*it) % 2)) {
        ivec.erase(it);
        }
    }
    for (auto it = ilist.begin(); it != ilist.end(); ++it) {
        if ((*it) % 2) {
        ilist.erase(it);
        }
    }
    return 0;
}