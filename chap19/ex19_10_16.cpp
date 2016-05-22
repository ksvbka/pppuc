/*9. Re-implement vector::operator=() (§19.2.5) using an allocator (§19.3.7) for
   memory management.
*/
// vector& Vector::operator=(const vector& a){
//     if(this == &a) return *this // Self-assignment

//     if(a.sz <= space){
//         for(int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
//         sz = a.sz;
//         return *this;
//     }

//     double* p = new double[a.sz];
//     for(int i = 0; i < a.sz; ++i) p[i] = a.elem[i];
//     delete[] elem;
//     space = sz = a.sz;
//     elem = p;
//     return *this;
// }
/*
10. Implement a simple unique_ptr supporting only a constructor, destructor, –>,
    *, and release(). In particular, don’t try to implement an assignment or a
    copy constructor.
*/
template<typename T>
class Unique_ptr
{
public:
    Unique_ptr(): ptr{nullptr} {}
    Unique_ptr(T* pOject): ptr{pOject} {}
    ~Unique_ptr() {if(ptr) delete ptr;}
    T& operator*() {return *ptr;}
    // T operator->(){return ptr;}
    Unique_ptr(const T* &pOject) = delete;
    Unique_ptr& operator=(const T* &pOject) = delete;
private:
    T* ptr;
};

// #include <iostream>
// #include <vector>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     Unique_ptr<int> p = new int(3);
//     cout << *p + 3 << endl;
//     return 0;
// }
/*
11. Design and implement a counted_ptr<T> that is a type that holds a pointer to
    an object of type T and a pointer to a “use count” (an int) shared by all
    counted pointers to the same object of type T. The use count should hold the
    number of counted pointers pointing to a given T. Let the counted_ptr’s
    constructor allocate a T object and a use count on the free store. Let
    counted_ptr’s constructor take an argument to be used as the initial value
    of the T elements. When the last counted_ptr for a T is destroyed,
    counted_ptr’s destructor should delete the T. Give the counted_ptr
    operations that allow us to use it as a pointer. This is an example of a
    “smart pointer” used to ensure that an object doesn’t get destroyed until
    after its last user has stopped using it. Write a set of test cases for
    counted_ptr using it as an argument in calls, container elements, etc.
*/

/*
12. Define a File_handle class with a constructor that takes a string argument
    (the file name), opens the file in the constructor, and closes it in the
    destructor.
*/

/*
13. Write a Tracer class where its constructor prints a string and its
    destructor prints a string. Give the strings as constructor arguments. Use
    it to see where RAII management objects will do their job (i.e., experiment
    with Tracers as local objects, member objects, global objects, objects
    allocated by new, etc.). Then add a copy constructor and a copy assignment
    so that you can use Tracer objects to see when copying is done.
*/

/*
14. Provide a GUI interface and a bit of graphical output to the “Hunt the
    Wumpus” game from the exercises in Chapter 18. Take the input in an input
    box and display a map of the part of the cave currently known to the player
    in a window.
*/

/*
15. Modify the program from the previous exercise to allow the user to mark
    rooms based on knowledge and guesses, such as “maybe bats” and “bottomless
    pit.”
*/

/*
16. Sometimes, it is desirable that an empty vector be as small as possible. For
    example, someone might use vector<vector<vector<int>>> a lot but have most
    element vectors empty. Define a vector so that
    sizeof(vector<int>)==sizeof(int*), that is, so that the vector itself
    consists only of a pointer to a representation consisting of the elements,
    the number of elements, and the space pointer.*/
