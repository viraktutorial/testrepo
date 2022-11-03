#pragma once

#include <iostream>
#include "Employee.cpp"
#include <vector>
#include <fstream>

using namespace std;

class EmployeeRepo: public EmployeeDAO{
public:
    //Read and write object data into file
    void saveEmployee(vector<Employee*>& employees){
        ofstream outputFile;
        outputFile.open("employees.dat", ios::out|ios::binary);
        vector<Employee*>::iterator it;
        for(it=employees.begin();it!=employees.end();it++){
            outputFile.write(reinterpret_cast<char *> (&it), sizeof(it));
        }
        outputFile.close();
    }
    
    vector<Employee*> loadEmployee(){
         vector<Employee*> employees;
         Employee *employee;
         ifstream inputFile;
         inputFile.open("employees.dat", ios::in|ios::binary);
         while(inputFile.read(reinterpret_cast<char *>(&employee), sizeof(*employee))){
             employees.push_back(employee);
         }
         return employees;
    }
    
    //Read and write text data into file
    void saveData(vector<Employee*> employees){
       ofstream outFile;
       outFile.open ("employee_details.dat", ios::out | ios::trunc);
        vector<Employee*>::iterator it;
        for(it=employees.begin();it!=employees.end();it++){
            outFile<<(*it)->getName()<<endl;
        }
        outFile.close();
    }
    
    void loadData(){
       ifstream inFile;
       inFile.open("employee_details.txt", ios::in|ios::binary);
       string line;
        while(getline(inFile, line)){ 
            //  cout << line << "\n"; //print the data of the string
        }
        inFile.close();
    }

    

};
