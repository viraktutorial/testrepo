#include <iostream>
#include <fstream>
#include "Employee.cpp"
#include "Department.cpp"
#include "SalariedEmployee.cpp"
#include "HourlyEmployee.cpp"
#include "EmployeeService.cpp"

using namespace std;

enum{
    ADD_EMPLOYEE=1,
    VIEW_EMPLOYEE,
    EDIT_EMPLOYEE,
    DELETE_EMPLOYEE,
    SAVE_EMPLOYEE,
    LOAD_EMPLOYEE,
    EXIT_APPLICATION
};
enum{
    SALARIED_EMPLOYEE=1,
    HOURLY_EMPLOYEE
};

class Application{
private:

public:
    void run(){
        int option;
        int choice = 0;
        int count=0;
        string name;

        SalariedEmployee salariedEmployee;
        HourlyEmployee hourlyEmployee;

        EmployeeService employeeService;
    


        do{
            showMenu();

            int choice=getCommand();

            switch(choice){
                case ADD_EMPLOYEE:
                    cout<<"EMPLOYEE TYPES"<<endl;
                    cout<<"1. Salaried Employee"<<endl;
                    cout<<"2. Hourly Employee"<<endl;
                    cout<<"Please enter your option: ";
                    cin>>option;
                    switch(option){
                        case SALARIED_EMPLOYEE:
                            salariedEmployee.getEmployee();
                            employeeService.addEmployee(&salariedEmployee);
                            break;
                        case HOURLY_EMPLOYEE:
                            hourlyEmployee.getEmployee();
                            employeeService.addEmployee(&hourlyEmployee);
                            count++;
                            break;
                    }
                    break;
                case VIEW_EMPLOYEE:
                    cout<<"Employee Info: "<<endl;
                    employeeService.viewEmployee();
                    cout<<endl;
                    break;
                case EDIT_EMPLOYEE:
                    cout<<"Enter name to edit ";
                    cin>>name;
                    employeeService.editEmployee(name);
                    break;
            
                case DELETE_EMPLOYEE:
                    cout<<"Enter name to delete ";
                    cin>>name;
                    employeeService.deleteEmployee(name);
                    break;
                case SAVE_EMPLOYEE:
                    employeeService.saveEmployeeToFile();
                    cout<<"Data has been saved"<<endl;
                    break;
                case LOAD_EMPLOYEE:
                    employeeService.loadEmployeeFromFile();
                    cout<<"Data has been loaded"<<endl;
                    break;
            }
        }while(choice!=7);

        cout<<"Exit program"<<endl;
    }

    void showMenu(){
        cout<<"WELCOME TO EMPLOYEE MANAGEMENT SYSTEM 1.0"<<endl;
        cout<<"MAIN MENU"<<endl; 
        cout<<"1. ADD EMPLOYEE"<<endl;
        cout<<"2. VIEW EMPLOYEE"<<endl;
        cout<<"3. EDIT EMPLOYEE"<<endl;
        cout<<"4. DELETE EMPLOYEE"<<endl;
        cout<<"5. SAVE EMPLOYEE TO FILE"<<endl;
        cout<<"6. LOAD EMPLOYEE FROM FILE"<<endl;
        cout<<"7. EXIT PROGRAM"<<endl;
    }

    int getCommand(){
        int choice;
        cout<<"Please enter your choice: ";
        cin>>choice;
        while(!isLegal(choice)){
            cout<<"Invalid choice, please enter again(1-7)"<<endl;
            showMenu();
            cin>>choice;
        }
        return choice;
    }

    bool isLegal(int c){
        return ((c==1) || (c==2) || (c==3) || (c==4) || (c==5) | (c==6) | (c==7));
    }


};
