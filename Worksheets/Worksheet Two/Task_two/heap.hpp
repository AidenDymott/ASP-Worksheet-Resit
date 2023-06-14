#include <iostream>
#include <iterator>
#include <new>
using namespace std;

class bump{
    public:
        int i, n; //declares ints I and N
        int * memArray; //ptr for P

        bump(){ // Builds array and allocates memory based on user input
        };

        ~bump(){// clears pointer memory
        };

        void* allocate_func(){
            cout << "How many numbers would you like to type? ";
            cin >> i; //user input for memory space
            memArray = new (nothrow) int[i]; //Memory array P
            if (memArray == nullptr)
                cout << "Error: memory could not be allocated"; //Error if memory cant be allocated
            else
            {
                for (n=0; n<i; n++)
                    {
                    cout << "Enter number: ";
                    cin >> memArray[n]; //take values from user to save in memory
                    }
                cout << "You have entered: ";
                for (n=0; n<i; n++) //Shows what has been stored in the memory
                    cout << memArray[n] << " ";
            }
            return 0;
        };

        void deallocate_func(){
            delete[] memArray;
        }

        void TEST_MEMORY_SIZE(){
            int array_length = sizeof(memArray) / 2;
            if (array_length == i){
                cout << "\nMemory is correct size" << endl;
            }
            else if (array_length != i){
                cout << "\nMemory isn't correct size"<< endl;

            }
        };


};