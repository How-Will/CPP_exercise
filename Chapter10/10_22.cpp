#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<functional>


bool myJudge(const std::string str, std::string::size_type sz){
    return str.size() >= sz ? true : false;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  std::cout << std::endl
            << count_if(words.begin(), words.end(),
                        std::bind(myJudge, std::placeholders::_1, 6))
            << std::endl;
  return 0;
}