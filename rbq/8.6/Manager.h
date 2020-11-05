#ifndef MANAGER_H
#define MANAGER_H
#include<string>
#include<Employee.h>
using namespace std;

class Manager: public Employee {
public:
    Manager(string);
    string getDepartment();
protected:
    string department;
};

#endif