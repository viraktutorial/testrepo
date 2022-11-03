

#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

//#pragma once
#include <iostream>
using namespace std;

class FileNotFoundException: public exception{
public:
    const char* what() const throw(){
        return "The file not found\n";
    }
};

#endif
