#include<iostream>
#include"Employee.h"
#include"Manager.h"
using namespace std;

Manager::Manager(string department, int id, string name) : department(department), Employee(id,name) {}

string Manager::getDepartment() {
    return department;
}