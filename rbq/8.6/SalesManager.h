#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include<string>
#include<Salesman.h>
#include<Manager.h>

class SalesManager : public Salesman, public Manager {
public:
    SalesManager(int id, string name, double SalesVolume, string department);
    void trainSalesman();
};

#endif