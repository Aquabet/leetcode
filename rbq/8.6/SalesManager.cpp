#include<iostream>
#include<SalesManager.h>
using namespace std;

SalesManager::SalesManager(int id, string name, double SalesVolume, string department) : Employee(id,name),Salesman(SalesVolume, id, name), Manager(department, id, name) {}

void SalesManager::trainSalesman() {
    cout<<"Finish to run function trainSalesman"<<endl;
}