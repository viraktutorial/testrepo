#pragma once

#include <iostream>
#include "Employee.cpp"
#include "DynamicArray.cpp"
#include <vector>
#include "EmployeeRepo.cpp"

using namespace std;

//business logics
class EmployeeService{
    private:
        //dynamic array
        vector<Employee *> employees;
    public:

        EmployeeService(){
            //loadEmployeeFromFile();
        }
        ~EmployeeService(){
            vector<Employee*>::iterator it;
            for(it=employees.begin();it!=employees.end();it++){
                delete *it;
            }
        }
        
        void addEmployee(Employee *employee){
            employees.push_back(employee);
        }

        void viewEmployee(){
            vector<Employee*>::iterator it;
            for(it=employees.begin();it!=employees.end();it++){
                (*it)->display();
                cout<<endl;
            }
        }

        void editEmployee(string name){
             vector<Employee*>::iterator it;
             for(it=employees.begin();it!=employees.end();it++){
                if((*it)->getName().compare(name)){
                    (*it)->getEmployee();
                    break;
                }
                
            }

        }
        void deleteEmployee(string name){
            vector<Employee*>::iterator it;
            for(it=employees.begin();it!=employees.end();it++){
                if((*it)->getName().compare(name)==0){
                    employees.erase(it);
                    break;
                }
            }
        }
    
    Employee* getEmployeeByName(string name){
        vector<Employee*>::iterator it;
         for(it=employees.begin();it!=employees.end();it++){
                if((*it)->getName().compare(name)==0){
                    return *it;
                }
          }
        return nullptr;
    }
    
    vector<Employee *> getAllEmployees(){
        return employees;
    }
    
   

    //Read and write object data into file
    void saveEmployeeToFile(){
         ofstream outputFile;
         outputFile.open("employees.bin", ios::out|ios::binary|ios::trunc);
         if(!outputFile){
            cout<<"Error in creating file...\n";
            exit(1);
        }else{
            vector<Employee*>::iterator it;
            for(it=employees.begin();it!=employees.end();it++){
                outputFile.write((char*) &it, sizeof(it));
                (*it)->display();
            }
        }
	
         outputFile.close();
    }
    void loadEmployeeFromFile(){
         Employee employee;
         ifstream inputFile;
         inputFile.open("employees.bin", ios::in|ios::binary);
        if(!inputFile){
		    cout<<"Error in opening file...\n";
		    exit(1);
	    }else{
            while(inputFile.read((char*)(&employee), sizeof(employee))){
                employees.push_back(&employee);
                employee.display();
                cout<<"H1"<<endl;
            }
        }
       
        
         cout<<"H2"<<endl;
         inputFile.close();
    }
      

};
