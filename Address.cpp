#pragma once

#include <iostream>
using namespace std;

class Address{
private:
    string street;
    string city;
public:
    Address():street("unknown"), city("unknown"){}
    Address(string street, string city):street(street), city(city){}
    Address(Address& address){
        this->street=address.street;
        this->city=address.city;
    }
    
//    ~Address(){
//        cout<<"Destroyed address"<<endl;
//    }
//
    //setter and geter methods
    
    
    void setStreet(string street){
        this->street=street;
    }
    
    void setCity(string city){
          this->city=city;
      }

    //method members
    void display(){
        cout<<"Street:"<<street<<" City:"<<city;
    }

    void getAddress(){
        cout<<"Enter street: ";
        cin>>street;
        cout<<"Enter city: ";
        cin>>city;
    }

    //
    friend istream& operator >>(istream& in, Address &address){
        cout<<"Enter street: ";
        in>>address.street;
        cout<<"Enter city: ";
        in>>address.city;
        return in;
    }
    
};


