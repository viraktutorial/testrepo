#pragma once

#include <iostream>
#include "Employee.cpp"
#include <vector>
#include <fstream>

using namespace std;

class EmployeeDAO{
public:
    //Read and write object data into file
    virtual void saveEmployee(vector<Employee*>& employees)=0;
    
    virtual vector<Employee*> loadEmployee()=0;
    
    //Read and write text data into file
    virtual void saveData(vector<Employee*> employees)=0;
    
    virtual void loadData()=0;

    

};
