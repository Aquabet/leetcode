#ifndef MANAGER_H
#define MANAGER_H
#include<string>
#include<Employee.h>
using namespace std;

class Manager: virtual public Employee {
public:
    Manager(string department, int id, string name);
    string getDepartment();
protected:
    string department;
};

#endif