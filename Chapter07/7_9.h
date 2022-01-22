#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

struct Person {
  string name;
  string address;
};

istream& read(istream& is, Person& person) {
    is >> person.name >> person.address;
    return is;
}

ostream& print(ostream& os, const Person& person) {
    os << person.name << " " << person.address;
    return os;
}

#endif