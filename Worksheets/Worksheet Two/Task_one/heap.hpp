#include <iostream>
#include <new>
using namespace std;

class bump{
    public:
        int i,n; //declares ints I and N
        int * p; //ptr for P

        bump(){ // Builds array and allocates memory based on user input
        };

        ~bump(){// clears pointer memory
        };

        void* allocate_func(){
            cout << "How many numbers would you like to type? ";
            cin >> i; //user input for memory space
            p = new (nothrow) int[i]; //Memory array P
            if (p == nullptr)
                cout << "Error: memory could not be allocated"; //Error if memory cant be allocated
            else
            {
                for (n=0; n<i; n++)
                {
                cout << "Enter number: ";
                cin >> p[n]; //take values from user to save in memory
                }
                cout << "You have entered: ";
                for (n=0; n<i; n++) //Shows what has been stored in the memory
                cout << p[n] << ", ";
            }
            return 0;
        };

        void deallocate_func(){
            delete[] p;
        }

};