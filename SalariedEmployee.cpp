
#pragma once

#include <iostream>
#include "Employee.cpp"
#include "Payment.cpp"
using namespace std;

class SalariedEmployee: public Employee, Payment{
private:
    double salary;
public:
    SalariedEmployee():Employee(), salary(0){}
    SalariedEmployee(string name, Address address, double salary):Employee(name, address), salary(salary){}
    
    //setter and getter
    double getSalary(){
        return salary;
    }

    double getPayment(){
        return salary;
    }
    
    void display(){
        Employee::display();
        cout<<" Salary:"<<salary;
    }
    void getEmployee(){
        Employee::getEmployee();
        cout<<"Enter salary: ";
        cin>>salary;
    }
};

