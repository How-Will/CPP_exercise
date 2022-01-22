#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> ivec;
    
    for(decltype(ivec.size()) ix = 0; ix != 100; ix++){
        ivec.push_back(ix);
        cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    }
    
    return 0;
}