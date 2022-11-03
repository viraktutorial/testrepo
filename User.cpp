#include <iostream>
using namespace std;

class User{
private:
    string username;
    string password;
    int role;
public:
    //constructors
    User(){}
    User(string username, string password):username(username),password(password){}
    User(string username, string password, int role):username(username),password(password), role(role){}
    //setter and getter methods
    string getUsername(){
        return this->username;
    }
    void setUsername(string username){
        this->username=username;
    }
    string getPassword(){
        return this->password;
    }
    void setPassword(string password){
        this->password=password;
    }
    
    void display(){
        cout<<"Username: "<<username<<" Password: "<<password<<" Role: "<<role<<endl;
    }
    
    User getUser(){
        string username;
        string password;
        cout<<"Enter the username:";
        cin>>username;
        cout<<"Enter the password: ";
        cin>>password;
        cout<<"Press 1. Admin 2.Faculty"<<endl;
        cin>>role;
        User user(username, password, role);
        return user;
    }

    
  
};
