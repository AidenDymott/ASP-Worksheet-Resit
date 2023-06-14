#include "my_string.hpp"
#include<memory> //Import smart pointer (shared pointer)

int main(){
    my_string s("Hello World"); // create obj of str class with value "Hello World".
    std::shared_ptr<my_string> ptr1 = std::make_shared<my_string>(); //Creating shared pointer.  
    s.print(); std::cout <<" [" << ptr1.use_count() << "]" << std::endl;
    
    {
        std::shared_ptr<my_string> ptr2 = ptr1; //In new scope share pointer reasource .
        my_string t = s; // copy value s to value t
        s.print(); std::cout <<" [" << ptr2.use_count() << "]" << std::endl; // Prints from constructor and shows how many instances of the pointer there are, in this case 2.
        t.print(); std::cout <<" [" << ptr2.use_count() << "]" << std::endl;
        std::cout << s.getChar(1); // uses the get func to return the 2nd(1st) character in stored string.
        s.print(); std::cout <<" [" << ptr2.use_count() << "]" << std::endl;
        t.print(); std::cout <<" [" << ptr2.use_count() << "]" << std::endl;
    }//Pointer withing scope is "freed".
    s.setChar(1,'E'); // Sets second char in to a capital E.
    s.print(); std::cout <<" [" << ptr1.use_count() << "]" << std::endl; // Prints modified value and shows reference count.
    ptr1.reset(); //Clears Pointer Memory
    std::cout << "Reference : [" << ptr1.use_count() << "]" << std::endl; //reference count 0 as the pointer hasn't been called.
    return 0; //Show ref count 0;
}

//clang++ -std=c++17 filetest_string.cpp my_string.cpp -o prog

