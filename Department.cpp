#pragma once

#include <iostream>
#include "Employee.cpp"
using namespace std;

class Department{
private:
    string name;
    Employee* employee; //aggregation
    
    //Employee* employees=new Employee[20];
    
public:
    Department():name("unknown"), employee(nullptr){}
    Department(string name, Employee* employee):name(name), employee(employee){}
    
//    ~Department(){
//        cout<<"Destroyed department"<<endl;
//    }
    //setter and getter
    void setEmployee(Employee* employee){
        if(this->employee!=nullptr){
            delete employee;
        }
        this->employee=employee;
    }
    void setEmployee(string name, Address address){
        if(this->employee!=nullptr){
            delete employee;
        }
        this->employee=new Employee(name, address);
    }
    
    void display(){
        cout<<"Name:"<<name<<endl;
        employee->display();
        
    }
    
};

