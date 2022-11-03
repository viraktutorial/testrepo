
#include <iostream>
#include <vector>
#include <fstream>
#include "User.cpp"

using namespace std;

class UserManager{

public:

    
    void userRegister(){
        string username;
        string password;
        cout<<"Enter the username:";
        cin>>username;
        cout<<"Enter the password: ";
        cin>>password;
        //write text into file
        ofstream fout;
        fout.open("users.txt", ios::app);
        fout<<username<<" "<<password<<endl;
        cout<<"Registered sucessfully"<<endl;
        
    }
    
    void userLogin(){
        string username, user;
        string password, pass;
        cout<<"Enter the username:";
        cin>>username;
        cout<<"Enter the password: ";
        cin>>password;
        
        //read text into file
        ifstream fin;
        int count=0;
        fin.open("users.txt", ios::in);
        while(fin>>user>>pass){
            if(username==user && password==pass){
                count=1;
                break;
            }
        }
        if(count==1){
            cout<<"valid"<<endl;
        }else{
            cout<<"invalid"<<endl;
        }
    }
    
    void userRegister2(User user){
        ofstream fout;
 
        fout.open("users.dat", ios::out|ios::binary|ios::app);
        fout.write(reinterpret_cast<char *> (&user), sizeof(user));
        fout.close();
        cout<<"User has been created"<<endl;
   
    }
    
    bool userLogin2(){
        string username;
        string password;
        cout<<"Enter the username:";
        cin>>username;
        cout<<"Enter the password: ";
        cin>>password;
        
        User user;
        ifstream fin;
        fin.open("users.dat", ios::in|ios::binary);
        while(fin.read(reinterpret_cast<char *>(&user), sizeof(user))){
            if(user.getUsername()==username && user.getUsername()==password){
                return true;
            }
        }
              
        return false;
        
        
    }
    
    void dispalyAllUsers(){
        User user;
        ifstream fin;
        fin.open("users.dat", ios::in|ios::binary);
        while(fin.read(reinterpret_cast<char *>(&user), sizeof(user))){
            user.display();
        }
    }
    
    vector<User> getAllUser(){
        vector<User> users;
        User user;
        ifstream fin;
        fin.open("users.dat", ios::in|ios::binary);
        while(fin.read(reinterpret_cast<char *>(&user), sizeof(user))){
            users.push_back(user);
        }
        return users;
    }
    
    User getUserByName(string name){
        User user("","");
        ifstream fin;
        fin.open("users.dat", ios::in|ios::binary);
        while(fin.read(reinterpret_cast<char *>(&user), sizeof(user))){
            if(user.getUsername()==name){
                return user;
            }
        }
        return user;
    }
    
    void updateUser(User userUpdate){
        bool found=false;
        fstream fio;
        User user;
        fio.open("users.dat", ios::in|ios::out|ios::binary);
        while(!fio.eof() && found==false){
            fio.read(reinterpret_cast<char *>(&user), sizeof(user));
            if(user.getUsername()==userUpdate.getUsername()){
                user.display();
                cout<<"Enter the new user"<<endl;
                user=user.getUser();
                int pos=(-1)*static_cast<int>(sizeof(user));
                fio.seekp(pos, ios::cur);
                fio.write(reinterpret_cast<char *> (&user), sizeof(user));
                cout<<"User updated"<<endl;
                found=true;
            }
        }
        fio.close();
        if(found==false){
            cout<<"User not found"<<endl;
        }
        
    }
    
    bool updateUser2(string name){
        User user;
        fstream fio;
        fio.open("users.dat", ios::in|ios::out|ios::binary);
        while(!fio.eof()){
            fio.read(reinterpret_cast<char *>(&user), sizeof(user));
            if(user.getUsername()==name){
                user.display();
                cout<<"Enter the new user"<<endl;
                user.getUser();
                int pos=(-1)*static_cast<int>(sizeof(user));
                fio.seekp(pos, ios::cur);
                fio.write(reinterpret_cast<char *> (&user), sizeof(user));
                cout<<"User updated"<<endl;
                
                return true;
            }
        }
        fio.close();
        return false;
        
    }
    
    void deleteUser(string name){
        User user;
        ifstream fin;
        fin.open("users.dat", ios::in | ios::binary);
        fin.seekg(0, ios::beg);
        
        ofstream fout;
        fout.open("temp.dat", ios::out|ios::binary);
        while(fin.read(reinterpret_cast<char *>(&user), sizeof(user))){
            if(user.getUsername()!=name){
                fout.write(reinterpret_cast<char *>(&user), sizeof(user));
            }
        }
        fout.close();
        fin.close();
        remove("users.dat");
        rename("temp.dat", "users.dat");
        
        cout<<"User has been deleted"<<endl;
        
    }
    
   
    
   

};
