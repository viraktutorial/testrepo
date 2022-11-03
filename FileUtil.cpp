#include <iostream>
#include <fstream>
#include "FileNotFoundException.cpp"
#include "User.cpp"
using namespace std;

class FileUtil{
private:
    ofstream fout;
public:
    void openOutputFile(string filename){
        try{
            fout.open(filename, ios::out|ios::app|ios::binary);
        }catch(FileNotFoundException e){
            cerr<<e.what()<<endl;
        }
    
    }
    
    void writeObject(User user){
        fout.write(reinterpret_cast<char *> (&user), sizeof(user));
    }
    
    void closeOutputFile(){
        fout.close();
    }
    
    ifstream openInputFile(string filename){
        ifstream fin;
        try{
            fin.open(filename, ios::in|ios::binary);
            
        }catch(FileNotFoundException e){
            cerr<<e.what()<<endl;
        }
        
        return fin;
    }
    
 
    
    
};
