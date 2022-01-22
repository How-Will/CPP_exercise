#include<iostream>
#include "Chapter6.h"
using namespace std;

unsigned fact(unsigned val){
    unsigned res = 1;
    while(val > 0){
        res *= val;
        val -= 1;
    }
    return res;
}

unsigned Abs(int val){
    return val >= 0 ? val : -val;
}