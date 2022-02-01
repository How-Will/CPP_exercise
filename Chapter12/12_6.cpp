#include<vector>
#include<iostream>

using namespace std;

vector<int>* newVector(){
    return new vector<int>;
}

vector<int>* getVector(vector<int>* ivec){
    int ival = 0;
    while(cin>>ival){
        ivec->push_back(ival);
    }
    return ivec;
}

void printVector(vector<int>* ivec){
    for(auto e : *ivec){
        cout << e << " ";
    }
    cout << endl;
    delete ivec;
}

int main(){
    printVector(getVector(newVector()));

    return 0;
}