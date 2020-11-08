#include<iostream>
#include<string>
#include"Salesman.h"
#include"Employee.h"
#include"Manager.h"
#include"SalesManager.h"
#include"Technician.h"
using namespace std;

int main() {
	Employee Boss(0, "People's Richer Mr.Ma");
	cout << "employee类对象的名字：" << Boss.getName() << endl;
	Technician aTechnicianman( 1, "Write bug", 1, "Stupid Technician");
	Salesman aSaleman(0.01, 2, "Stupid Saleman");
	Manager aManager("debug department", 3, "Hard Debuger");
	SalesManager(10000, "SalesManager Department", 4, "Cool SalesManager");
}