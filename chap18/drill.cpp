#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
/*
Array drill:
1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
*/
int ga[10] = {1,2,4,8,16};
/*
2. Define a function f() taking an int array argument and an int argument
   indicating the number of elements in the array.
3. In f():
a. Define a local int array la of ten ints.
b. Copy the values from ga into la.
c. Print out the elements of la.
d. Define a pointer p to int and initialize it with an array allocated on the
   free store with the same number of elements as the argument array.
e. Copy the values from the argument array into the free-store array.
f. Print out the elements of the free-store array.
g. Deallocate the free-store array.
*/
void f(int a[], int size){
    int la[10];

    int elements_count = size < 10 ? size : 10;
    for(int i = 0; i < elements_count; ++i)
        la[i] = a[i];

    cout << "\n Elements of local array" << endl;
    for(auto i : la)
        cout << " " << i;

    int* p = new int[size];
    for(int i = 0; i < size; ++i)
        p[i] = a[i];

    cout << "\n Elements of free-store: " << endl;
    for(int i = 0; i < size; ++i)
        cout << " " << p[i];
    delete[] p;
}

/*
4. In main():
a. Call f() with ga as its argument.
b. Define an array aa with ten elements, and initialize it with the first ten
   factorial values (1, 2*1, 3*2*1, 4*3*2*1,etc.).
c. Call f() with aa as its argument.
*/

/*
Standard library vector drill:
1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16,
   etc.
2. Define a function f() taking a vector<int> argument.
3. In f():
a. Define a local vector<int> lv with the same number of elements as the
   argument vector.
b. Copy the values from gv into lv.
c. Print out the elements of lv.
d. Define a local vector<int> lv2; initialize it to be a copy of the argument
   vector.
e. Print out the elements of lv2.

*/
vector<int> gv{1,2,4,8,16};

void fv(vector<int> v){
    vector<int> lv = v;
    cout << "\nElements of vector lv: " << endl;
    for(auto elem : lv)
        cout << " " << elem;
}

/*
4. In main():
a. Call f() with gv as its argument.
b. Define a vector<int> vv, and initialize it with the first ten factorial
   values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
c. Call f() with vv as its argument.
*/

int main(int argc, char const *argv[])
{
    try{
        /*No-std version:D*/
        f(ga,10);
        int factorial_arr[10];
        factorial_arr[0] = 1;
        for(int i = 1; i < 10; ++i)
            factorial_arr[i] = factorial_arr[i-1] * i;

        f(factorial_arr,10);

        /*std lib version*/
        fv(gv);

    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting...!" << endl;
    }
}
