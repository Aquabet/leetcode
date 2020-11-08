#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<iostream>
using namespace std;

class Employee {
public:
    Employee(int id, string name);
    void setName(string);
    string getName();
protected:
    int id;
    string name;
};

#endif