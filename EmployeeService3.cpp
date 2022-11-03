#include <iostream>
#include "Employee.cpp"
#include "DynamicArray.cpp"
using namespace std;

//business logics
class EmployeeService{
    private:
        //static
        Employee *employees[100];
        int count=0;
    public:

        EmployeeService(){

        }

        void addEmployee(Employee &employee){
            employees[count]=&employee; 
            count++;
        }
        
        void addEmployee(Employee *employee){
            employees[count]=employee; 
            count++;
        }

        void viewEmployee(){
            for(int i=0;i<count;i++){
                employees[i]->display();
                cout<<endl;
            }
        }
        void editEmployee(string name){
            int index=findEmployeeName(name);
            if(index==-1){
                cout<<"Employee name is not found"<<endl;
            }else{
                employees[index]->getEmployee();
            }

        }
        void deleteEmployee(string name){
            int index=findEmployeeName(name);
            if(index==-1){
                cout<<"Employee name is not found"<<endl;
            }else{
                for(int j=index;j<count-1;j++){
                    employees[j]=employees[j+1];
                }
                count--;
            }
        }

        int findEmployeeName(string name){
            for(int i=0;i<count;i++){
                if(employees[i]->getName().compare(name)==0){
                    return i;
                }
            }
            return -1;
        }

};