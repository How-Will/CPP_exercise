#include<vector>
#include<iostream>
#include<memory>

using namespace std;

shared_ptr<vector<int>> newVector(){
    return make_shared<vector<int>>();
}

void getVector(shared_ptr<vector<int>> ivec){
    int ival = 0;
    while(cin>>ival){
        ivec->push_back(ival);
    }
}

void printVector(shared_ptr<vector<int>> ivec){
    for(auto e : *ivec){
        cout << e << " ";
    }
    cout << endl;
}

int main(){
    auto vec_ptr = newVector();
    getVector(vec_ptr);
    printVector(vec_ptr);

    return 0;
}