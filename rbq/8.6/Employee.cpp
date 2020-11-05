#include<Employee.h>
#include<bits/stdc++.h>
using namespace std;

Employee::Employee(int aId, string aName) {
    id = aId;
    name = aName;
}
void Employee::setName(string aName) {
    name = aName;
}
string Employee::getName() {
    return name;
}