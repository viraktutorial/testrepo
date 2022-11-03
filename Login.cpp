#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Login
{

        private:
            string username;
            string password;
            int role;
        public:
            void Register()
            {
                ofstream fs("logindata.dat",ios::app);
                cout<<"Enter username: ";
                cin>>username;
                cout<<"Enter password: ";
                cin>>password;
                cout<<"Press 1. Student 2. Faculty 3. Admin"<<endl;
                cin>>role;
                fs<<username<<" "<<password<<" "<<role<<" ";
                fs.close();
            }
            void login(string username,string password)
            {
                ifstream fs("logindata.dat",ios::in);
                while(!fs.eof())
                {
                fs>>username>>password>>role;
               
                    if(username.compare(this->username)==0 && password.compare(this->password)==0)
                {
                    if(role==1)
                    {
                        cout<<"Welcome to student : "<<username;
                    }
                    else if(role==2)
                    {
                        cout<<"Welcome to faculty : "<<username;
                    }
                    else if(role==3)
                    {
                        cout<<"Welcome to admin : "<<username;
                    }
                }
           
                }
                fs.close();
            }
};
