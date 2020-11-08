#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

Employee::Employee(int id, string name) : id(id), name(name) {}

void Employee::setName(string aName) {
    name = aName;
}

string Employee::getName() {
    return name;
}