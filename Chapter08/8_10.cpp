#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void readFile(string file, vector<string>& vec){
    ifstream input("data.txt"); //打开文件
    if(input){
        string line;
        while (getline(input, line))
        {
            vec.push_back(line);
        }
    }
}

int main(){
    vector<string> str_vec; //保存来自一个文件中的行
    readFile("./data.txt", str_vec);
    
    for(auto& str : str_vec){
        istringstream iss(str);
        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}