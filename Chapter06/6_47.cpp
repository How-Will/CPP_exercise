#include<iostream>
#include<vector>
// 使用#define NDEBUG，从而关闭调试状态。
// 默认情况下未定义NDEBUG，则可以进行调试
//#define NDEBUG
using namespace std;

void print_vector(vector<int>& vec){

    #ifndef NDEBUG
        cout << "Vector size: " << vec.size() <<
        ", " << __DATE__ << " " << __TIME__ << endl;
    #endif

    if(vec.empty())
        return;
    cout << vec.back() << endl;
    vec.pop_back();
    print_vector(vec);
}


int main(){
    vector<int> iv = {1, 2, 3, 4, 5};
    print_vector(iv);
    return 0;
}