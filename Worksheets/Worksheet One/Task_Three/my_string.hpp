#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <string>

class my_string{
    public:

    // Default constructor
        my_string(); 
    // constructor
        my_string(const char* welcome);
    // Deconstructor    
        ~my_string();
    // Print func
        void print();
    //getter
        char getChar(const int& i);
    // Sets character
        void setChar(const int& i, const char& c);

    private:
        std::string hello;

};
#endif