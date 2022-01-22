#include<iostream>
using namespace std;

void MyReplace(string& s, const string& oldVal, const string& newVal){
    auto ix = oldVal.size();

    while(ix <= s.size() + 1){
        if(s.substr(ix - oldVal.size(), oldVal.size()) == oldVal){
            s.replace(ix - oldVal.size(), oldVal.size(), newVal);
            ix += newVal.size();
        }else{
            ix++;
        }
    }
}

int main(){
    std::string str = "tho abc thru 123 tho";
    MyReplace(str, "tho", "though");
    MyReplace(str, "thru", "through");
    std::cout << str << std::endl;
    
    return 0;
}