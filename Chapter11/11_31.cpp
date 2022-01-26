#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    multimap<string, string> ss_map = {{"Jack", "<River>"},
                                       {"Jack", "<Trun to life>"},
                                       {"William", "<Love>"}};
    
    string author = "Jack";
    string work = "<River>";
    
    auto beg = ss_map.find(author);
    auto cnt = ss_map.count(author);

    while(cnt){
        if(beg->second == work){
            ss_map.erase(beg);
            break;
        }
        ++beg;
        --cnt;
    }

    for (const auto &p : ss_map)
        std::cout << p.first << " " << p.second << std::endl;

    return 0;
}