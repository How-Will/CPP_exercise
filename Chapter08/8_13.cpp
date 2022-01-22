#include<sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};


int main(int argc, char const *argv[]) {
  string line, word;
  vector<PersonInfo> people;
  ifstream is("./input.txt");
  while (getline(is, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  return 0;
}