#include<iostream>
#include<string>
using namespace std;

void MyReplace(string& s, const string& oldVal, const string& newVal){
    auto iter = s.begin() + oldVal.size();
    while(iter != s.end()){
        if(string(iter - oldVal.size(), iter) == oldVal){
            iter = s.erase(iter - oldVal.size(), iter);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size();
        }else{
            ++iter;
        }
    }
    if(string(iter - oldVal.size(), iter) == oldVal){
        iter = s.erase(iter - oldVal.size(), iter);
        iter = s.insert(iter, newVal.begin(), newVal.end());
    }
}

int main(){
    std::string str = "tho abc thru 123 tho";
    MyReplace(str, "tho", "though");
    MyReplace(str, "thru", "through");
    std::cout << str << std::endl;

    return 0;
}