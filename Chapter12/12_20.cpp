#include"12_19.h"
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream input("./12_20_input.txt");
    string line;
    StrBlob strBlob;
    StrBlobPtr strBlobPtr(strBlob);


    while(getline(input, line)){
        strBlob.push_back(line);
    }

    for(decltype(strBlob.size()) i = 0; i != strBlob.size(); i++){
        cout << strBlobPtr.deref() << endl;
        strBlobPtr.incr();
    }

    return 0;
}