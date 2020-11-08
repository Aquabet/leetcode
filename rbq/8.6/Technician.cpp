#include<iostream>
#include<string>
#include"Employee.h"
#include"Technician.h"
using namespace std;

Technician::Technician(int grade, string projectName, int id, string name) : grade(grade), projectName(projectName), Employee(id,name) {}

void Technician::setProjectName(string aProjectName) {
    projectName = aProjectName;
}

string Technician::getProjectName() {
    return projectName;
}

int Technician::getGrade() {
    return grade;
}

void Technician::promote(int promoteGrade) {
    grade += promoteGrade;
}
