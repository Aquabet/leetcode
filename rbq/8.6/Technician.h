#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include<string>
#include<Employee.h>
using namespace std;

class Technician : public Employee {
public:
    Technician(int ,string);
    void setProjectName(string);
    string getProjectName();
    int getGrade;
    void promote(int);
protected:
    string projectName;
    int grade;
};

#endif