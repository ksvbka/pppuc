/*9. Re-implement vector::operator=() (§19.2.5) using an allocator (§19.3.7) for
   memory management.
*/
vector& Vector::operator=(const vector& a){
    if(this == &a) return *this // Self-assignment

    if(a.sz <= space){
        for(int i = 0; i < a.sz; ++i) elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz];
    for(int i = 0; i < a.sz; ++i) p[i] = a.elem[i];
    delete[] elem;
    space = sz = a.sz;
    elem = p;
    return *this;
}
/*
10. Implement a simple unique_ptr supporting only a constructor, destructor, –>,
    *, and release(). In particular, don’t try to implement an assignment or a
    copy constructor.
*/
template<typename T>
class Unique_ptr
{
public:
    Unique_ptr(): ptr_{nullptr} {}
    Unique_ptr(T* pOject): ptr_{pOject} {}
    ~Unique_ptr() {if(ptr_) delete ptr_;}
    T& operator*() {return *ptr_;}
    T* operator->(){return ptr_;}

    Unique_ptr(const T* &pOject) = delete;
    Unique_ptr& operator=(const T* &pOject) = delete;
private:
    T* ptr_;
};

// #include <iostream>
// #include <vector>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     Unique_ptr<vector<int>> p = new vector<int>{1,2,34, 45 ,24};
//     cout << p->size();
//     for(auto i = 0; i < p->size(); ++i)
//         cout << " " << p->at(i);
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

template<typename T>
class counted_ptr
{
public:
    /*Default constructor*/
    counted_ptr(): ptr_{nullptr}, count_{new int(1)} {}
    /*Constructor ptr with n element*/
    counted_ptr(int n): ptr_{new T[n]}, count_{new int(1)} {}
    /*constructor ptr with n element and initialize for it*/
    counted_ptr(int n, T init_value): counted_ptr(n) {
        count_ = new int(1);
        for(int i = 0; i < n; ++i)
            ptr_[i] = init_value;
    }
    ~counted_ptr(){
        if(--(*count_) == 0)
            delete[] ptr_;
    }
    /*Copy constructor*/
    counted_ptr(const T* &pOject){
        ptr_ = pOject.ptr_;
        count_ = pOject.count_;
        ++(*count_);
    }

    /*Assignment constructor*/
    counted_ptr& operator=(const T* &pOject){
        if(&pOject == this) return this;
        --(*count_);
        if(*count_ == 0){
            delete count_;
            delete ptr_;
        }

        ptr_ = pOject.ptr_;
        count_ = pOject.count_;
        ++(*count_);
        return this;
    }

    T& operator*() {return *ptr_;}
    T* operator->(){return ptr_;}

    int count() {return (*count_);}

private:
    T* ptr_;
    int* count_;
};

// #include <iostream>
// #include <vector>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     counted_ptr<int> p(3,3);
//     counted_ptr<int> q = p;
//     counted_ptr<int> r = q;
//     cout << r.count();

//     return 0;
// }

/*
12. Define a File_handle class with a constructor that takes a string argument
    (the file name), opens the file in the constructor, and closes it in the
    destructor.
*/
#include <fstream>
#include <stdio.h>
#include <iostream>

class File_handle {
    FILE* f;
    string fname;
public:
    File_handle(const string& fn, const string& m);
    ~File_handle();
    FILE* file() { return f;    }
};

File_handle::File_handle(const string& fn, const string& m)
    : f(0), fname(fn)
{
    cout << "Opening file " << fname << "\n";
    f = fopen(fn.c_str(),m.c_str());
    if (!f) error("Problem opening ",fname);
}

File_handle::~File_handle()
{
    cout << "Closing file " << fname << "\n";
    int i = fclose(f);
    if (i!=0) error("Problem with closing ",fname);
}

void f(const string& s)
{
    File_handle fh(s,"w");
    cout << "Enter a string you would like to write into the file: ";
    string in;
    getline(cin,in);
    fwrite(in.c_str(),sizeof(char),in.size(),fh.file());
}

// #include <stdexcept>
// int main(int argc, char const *argv[])
// {
//     try{
//         std::string file_path;
//         std::cout << "Enter file path: ";
//         std::cin >> file_path;
//         File_handle f{file_path};

//     }catch(std::exception& e){
//         std::cout << e.what() << std::endl;
//     }

//     return 0;
// }

/*
13. Write a Tracer class where its constructor prints a string and its
    destructor prints a string. Give the strings as constructor arguments. Use
    it to see where RAII management objects will do their job (i.e., experiment
    with Tracers as local objects, member objects, global objects, objects
    allocated by new, etc.). Then add a copy constructor and a copy assignment
    so that you can use Tracer objects to see when copying is done.
*/

#include <iostream>
class Tracer
{
public:
    Tracer(): name_{} {
        std::cout << "Default tracer constructor: " << std::endl;
    }
    Tracer(std::string s):name_{s} {
        std::cout << "Tracer constructor: " << name_ << std::endl;
    };
    Tracer(const Tracer& obj): name_{obj.name_ + "_cpy"}{
        std::cout << "Copy constructor of: " << name_ << std::endl;
    }
    Tracer& operator=(const Tracer& obj){
        name_ = obj.name_ + "_asi";
        std::cout << "Copy assignment of: " << name_ << std::endl;
        return *this;
    }
    ~Tracer(){
        std::cout << "Tracer destructor: " << name_ << std::endl;
    };

private:
    std::string name_;
};

// #include <vector>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     Tracer obj{"local"};
//     Tracer obj2 = obj;

//     Tracer* pObj = new Tracer("Allocated with new"); // leaks!
//     vector<Tracer> v(3, {"vector"});

//     return 0;
// }

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
    the number of elements, and the space pointer.
*/

#include <iostream>

template<typename T>
struct Vec_rep {
    int sz_;
    T* elem_;
    int space_;

    Vec_rep(): sz_{0}, elem_{nullptr}, space_{0} {}
    Vec_rep(int n): sz_{n}, elem_{new T[n]}, space_{n} {}
    Vec_rep(int n, T init_value) : Vec_rep(n){
        for(int i = 0; i < n; ++i)
            elem_[i] = init_value;
    }

    ~Vec_rep(){ if(elem_) delete[] elem_;}
};

template<typename T>
class Mini_vec
{
public:
    Mini_vec(): vec_{new Vec_rep<T>} {}
    Mini_vec(int n): vec_{new Vec_rep<T>(n)} {}
    Mini_vec(int n, T init_value): vec_{new Vec_rep<T>(n,init_value)} {}
    /*Copy constructor*/
    Mini_vec(const Mini_vec& rhs): vec_{new Vec_rep<T>(rhs.vec_->sz_)}{
        for(int i = 0; i < vec_->sz_; ++i)
            vec_->elem_[i] = rhs.vec_->elem_[i];
    }

    T& operator[](int n) { return vec_->elem[n]; }
    const T& operator[](int n) const { return vec_->elem_[n]; }

    int size() const { return vec_->sz_; }
    int capacity() const { return vec_->space_; }

    Mini_vec& operator=(const Mini_vec& rhs);

    ~Mini_vec() { delete vec_;}

    template <typename L>
    friend std::ostream& operator<<(std::ostream& os, const Mini_vec<L>& rhs);

private:
    Vec_rep<T>* vec_;
};

template <typename T>
Mini_vec<T>& Mini_vec<T>::operator=(const Mini_vec<T>& rhs){
    if(this == &rhs) return *this;
    if(vec_->sz_ >= rhs.size()){
        vec_->sz_ = rhs.size();
        for(int i = 0; i < vec_->sz_; ++i)
            vec_->elem_[i] = rhs[i];
        return *this;
    }

    Vec_rep<T> *p = new Vec_rep<T>(rhs.vec_->sz_);
    for(int i = 0; i < rhs.size(); ++i)
        p->elem_[i] = rhs[i];
    delete vec_;
    vec_ = p;
    return *this;
}


template <typename L>
std::ostream& operator<<(std::ostream& os, const Mini_vec<L>& rhs){
    std::cout << "vec: ";
    for(int i = 0; i < rhs.size(); ++i)
        std::cout << " " << rhs[i];
    std::cout << std::endl;
}

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    cout << "Mini_vec size: " << sizeof(Mini_vec<double>) << endl;;
    cout << "Vec_rep  size: " << sizeof(Vec_rep<double>) << endl;

    Mini_vec<int> p{1,3};
    Mini_vec<int> q = p;
    p = {5,5};

    cout << p;
    return 0;
}
