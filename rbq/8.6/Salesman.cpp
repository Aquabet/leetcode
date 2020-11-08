#include<iostream>
#include<string>
#include"Employee.h"
#include"Salesman.h"
using namespace std;

Salesman::Salesman(double SalesVolume, int id, string name) : SalesVolume(SalesVolume), Employee(id,name) {}

double Salesman::getSalesVolume() {
    return SalesVolume;
}
