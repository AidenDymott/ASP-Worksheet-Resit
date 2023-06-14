#include "my_string.hpp"
// Default constructor
my_string::my_string(){}

//constructor, takes the input from line 5 in filetest_string.cpp
my_string::my_string(const char* welcome){
    hello = welcome;
}
// Deconstructor
my_string::~my_string(){
}
// print function
void my_string::print(){
    std::cout << hello << std::endl;
}
//Setter
void my_string::setChar(const int& i, const char& c){
    hello[i] = c;
}
//Getter
char my_string::getChar(const int& i){
    std::cout << hello[i] << std::endl;
    return 0;
}



//clang++ -std=c++17 filetest_string.cpp my_string.cpp -o prog