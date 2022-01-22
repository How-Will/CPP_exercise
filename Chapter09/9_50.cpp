#include<iostream>
#include<string>
#include<vector>
using namespace std;


int SumIntVec(const vector<string>& s_vec){
    int res = 0;
    for(auto iter = s_vec.begin(); iter != s_vec.end(); iter++){
        res += stoi(*iter);
    }
    return res;
}

double SumDoubleVec(const vector<string>& s_vec){
    double res = 0;
    for(auto elment : s_vec){
        res += stod(elment);
    }
    return res;
}

int main(){
    vector<string> s_vec1{"1", "2", "3", "4"};
    vector<string> s_vec2{"1.3", "1.4", "3.0"};
    cout << SumIntVec(s_vec1) << endl;
    cout << SumDoubleVec(s_vec2) << endl;

    return 0;
}