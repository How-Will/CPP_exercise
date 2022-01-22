#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main(){
    string line, word;  //分别保存来自输入的一行和单词
    vector<PersonInfo> people;  //保存来自输入的所有记录
    istringstream record;

    while(getline(cin, line)){
        PersonInfo info;    //创建一个保存此记录数据的对象
        record.str(line); //将record和line绑定
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();  //置位
    }
    return 0;
}
