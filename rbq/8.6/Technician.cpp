#include<Technician.h>
#include<iostream>
#include<string>
using namespace std;

Technician::Technician(int grade, string projectName, int id, string name) : grade(grade), projectName(projectName), Employee(id,name) {}
void Technician::setProjectName(string projectName) : projectName(projectName) {}
