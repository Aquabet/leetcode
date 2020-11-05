#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
using namespace std;

class Employee {
public:
    Employee(int , string );
    void setName(string);
    string getName();
protected:
    int id;
    string name;
};

#endif