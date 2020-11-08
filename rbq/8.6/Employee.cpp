#include<Employee.h>
#include<iostream>
#include<string>
using namespace std;

Employee::Employee(int id, string name) : id(id), name(name) {}

void Employee::setName(string aName) {
    name = aName;
}

string Employee::getName() {
    return name;
}