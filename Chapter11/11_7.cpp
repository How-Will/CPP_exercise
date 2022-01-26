#include<map>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main(){
    map<string, vector<string>> family;
    string family_name;
    string member_name;
    vector<string> s_vec;

    cout << "family name: ";
    cin >> family_name;
    while(cin >> member_name){
        s_vec.push_back(member_name);
    }
    family[family_name] = s_vec;

    for(const auto& e : family){
        cout << "family: " << e.first << endl;
        cout << "members: ";
        for(const auto& mem : e.second){
            cout << mem << " ";
        }
    }

    cout << endl;

    return 0;
}