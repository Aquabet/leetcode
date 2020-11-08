#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include<string>
#include<Employee.h>
using namespace std;

class Technician : virtual public Employee {
public:
    Technician(int grade, string projectName, int id, string name);
    void setProjectName(string);
    string getProjectName();
    int getGrade;
    void promote(int);
protected:
    string projectName;
    int grade;
};

#endif