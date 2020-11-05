#ifndef SALESMAN_H
#define SALESMAN_H
#include<string>
#include<Employee.h>

class Salesman : virtual public Employee {
public:
    Salesman(double SalesVolume);
    double getSalesVolume();
private:
    double SalesVolume;
};

#endif