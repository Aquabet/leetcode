#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include<string>
#include<Employee.h>
#include<Salesman.h>
#include<Manager.h>

class SalesManager : public Salesman, public Manager {
public:
    SalesManager();
    void trainSalesman();
};

#endif