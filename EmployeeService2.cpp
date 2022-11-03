#include <iostream>
#include "Employee.cpp"
#include "DynamicArray.cpp"
using namespace std;

//business logics
class EmployeeService{
    private:
        //dynamic
        DynamicArray<Employee> *employees;
    
    public:

        EmployeeService(){

        }

        void addEmployee(Employee &employee){
            employees->add(employee);
        }
        

        void viewEmployee(){
          
        }
        void editEmployee(string name){
            int index=findEmployeeName(name);
            if(index==-1){
                cout<<"Employee name is not found"<<endl;
            }else{
             
            }

        }
        void deleteEmployee(string name){
            int index=findEmployeeName(name);
            if(index==-1){
                cout<<"Employee name is not found"<<endl;
            }else{
           
            }
        }

        int findEmployeeName(string name){
            
            return -1;
        }

};