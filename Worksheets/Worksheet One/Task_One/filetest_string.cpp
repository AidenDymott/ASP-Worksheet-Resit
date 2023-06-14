#include "my_string.hpp"

int main(){
    my_string s("Hello World"); // create obj of str class with value "Hello World"
    s.print(); // print hello world using constructor
    {
        my_string t = s; // copy value s to value t
        s.print();//Second print showing s has same value
        t.print();//Prints Value t
        std::cout << s.getChar(1); // gets character 1 from string
        s.print();//print s str
        t.print();//Prints t str
    }
    s.setChar(1,'E'); // Sets cha 2 in str to E
    s.print(); // Prints new str(s) 
    
    return 0;
}


