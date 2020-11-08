#include<Employee.h>
#include<iostream>
#include<string>
#include<Technician.h>
#include<Employee.h>

using namespace std;

Technician::Technician(int grade, string projectName, int id, string name) : grade(grade), projectName(projectName), Employee(id,name) {}

void Technician::setProjectName(string aProjectName) {
    projectName = aProjectName;
}
