#ifndef PERSON_H
#define PERSON_H

# include<string>
using namespace std;

struct Person{
    string name;
    string adress;

    string get_name() const{
        return name;
    }

    string get_adress() const{
        return adress;
    }
};

#endif