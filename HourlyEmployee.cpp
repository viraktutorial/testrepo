
#pragma once

#include <iostream>
#include "Employee.cpp"
#include "Payment.cpp"
using namespace std;

class HourlyEmployee: public Employee, public Payment{
private:
    double rate;
    double hour;
public:
    HourlyEmployee():Employee(), rate(0), hour(0){}
    HourlyEmployee(string name, Address address, double rate, double hour):Employee(name, address), rate(rate), hour(hour){}
    
    
    double getPayment(){
        return rate*hour;
    }

    void display(){
        Employee::display();
        cout<<" Rate:"<<rate<<" Hour:"<<hour;
    }
    void getEmployee(){
        Employee::getEmployee();
        cout<<"Enter rate: ";
        cin>>rate;
        cout<<"Enter hour: ";
        cin>>hour;
    }
};
