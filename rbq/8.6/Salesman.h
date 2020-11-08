#ifndef SALESMAN_H
#define SALESMAN_H
#include<string>
#include<Employee.h>
using namespace std;

class Salesman : virtual public Employee {
public:
    Salesman(double SalesVolume, int id, string name);
    double getSalesVolume();
private:
    double SalesVolume;
};

#endif