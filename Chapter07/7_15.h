#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

struct Person {
  string name;
  string address;

  //构造函数
  Person() = default;
  Person(const string& name, const string& address):name(name), address(address){

  }
  Person(istream& is);
};

istream& read(istream& is, Person& person) {
    is >> person.name >> person.address;
    return is;
}

ostream& print(ostream& os, const Person& person) {
    os << person.name << " " << person.address;
    return os;
}

Person::Person(istream& is){
    read(is, *this);
}

#endif