#include<iostream>
#include"Employee.h"
#include"SalesManager.h"
#include"Salesman.h"
using namespace std;

SalesManager::SalesManager(double SalesVolume, string department, int id, string name) : Employee(id,name),Salesman(SalesVolume, id, name), Manager(department, id, name) {}

void SalesManager::trainSalesman() {
    cout<<"Finish to run function trainSalesman"<<endl;
}