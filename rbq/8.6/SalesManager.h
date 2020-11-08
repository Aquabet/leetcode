#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include<string>
#include"Salesman.h"
#include"Manager.h"

class SalesManager : public Salesman , public Manager {
public:
    SalesManager(double SalesVolume, string department, int id, string name);
    void trainSalesman();
};

#endif