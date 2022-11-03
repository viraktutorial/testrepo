#pragma once

#include <iostream>
#include <fstream>
#include "Address.cpp"
using namespace std;

//concrete class
class Employee{
private:
    //data memb*ers
    string name;
    Address address; //composition

public:
    //constructors
    Employee():name("unknown"){}
    Employee(string name):name(name){}
    Employee(string name, Address address):name(name), address(address){}
    Employee(string name, string street, string city):name(name), address(street, city){}
    
    ~Employee(){
      
    }
    //setter and getter methods
    Address getAddress(){
        return address;
    }
    void setAddress(Address address){
        this->address=address;
    }
    void setAddress(string street, string city){
        address.setStreet(street);
        address.setCity(city);
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name=name;
    }
    //method members
    virtual void display(){
        cout<<"Name:"<<name;
        address.display();
    }

    virtual void getEmployee(){
        cout<<"Enter name: ";
        cin>>name;
        address.getAddress();
       
    }

// void save(ofstream& of)
// {
//   of.write(, sizeof(number));
//   of.write(name, sizeof(name));
//   of.write(&gpa, sizeof(gpa));
// }

// void load(ifstream& inf)
// {
//   inf.read(&number, sizeof(number));
//   inf.read(name, sizeof(name));
//   inf.read(&gpa, sizeof(gpa));
// }
 

    
};
