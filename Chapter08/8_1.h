#ifndef H_8_1
#define H_8_1

#include<iostream>
#include<string>
using namespace std;

istream& read(istream& is){
    string data;
    while(!is.eof()){
        is >> data;
        cout << data << endl;
    }
    is.clear();
    return is;
} 

#endif