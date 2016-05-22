#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


/*1. Define template<typename T> struct S { T val; };.*/

template<typename T>
struct S {
    T val;
    /*2. Add a constructor, so that you can initialize with a T.*/
    S(T val_): val(val_) {}
    /*5. Add a function template get() that returns a reference to val.*/
    T& get();
    /*11. const version for get()*/
    const T& get() const;

    /*9. Add a set() function template so that you can change val.*/
    void set(const T& val_) { val = val_;}
    /*10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than
    §19.2.5.*/
    void operator=(const T&);
    /*12. Define a function template<typename T> read_val(T& v) that reads from cin
    into v.*/
    void read_val();

};
/*6. Put the definition of get() outside the class.*/
template<typename T>
T& S<T>::get(){
    return val;
}

template<typename T>
const T& S<T>::get() const {
    return val;
}


template<typename T>
void S<T>::operator=(const T& rhs){
    val = rhs;
}


/*
3. Define variables of types S<int>, S<char>, S<double>, S<string>, and
   S<vector<int>>; initialize them with values of your choice.
*/
S<int> val_int(3);
S<char> val_char('3');
S<double> val_double(3.54);
S<string> val_string("I'm a string, bitch!");
S<vector<int>> val_vec_int({1, 2, 3, 4});

/*
4. Read those values and print them.
*/
void test_read_and_print() {
    cout << val_int.val << endl;
    cout << val_double.val << endl;
    cout << val_string.val << endl;
    for (int i = 0; i < val_vec_int.val.size(); ++i)
        cout << val_vec_int.val[i] << " ";
    cout << endl;
}


/*
8. Do 4 again using get().
*/

void test_read_and_print_using_get(){
    cout << val_int.get()<< endl;
    cout << val_double.get() << endl;
    cout << val_string.get() << endl;
    for (int i = 0; i < val_vec_int.get().size(); ++i)
        cout << val_vec_int.get()[i] << " ";
    cout << endl;
}


/*
12. Define a function template<typename T> read_val(T& v) that reads from cin
    into v.
*/

template<typename T>
void S<T>::read_val(){
    T buff;
    cin >> buff;
    this->set(buff);
}


/*
13. Use read_val() to read into each of the variables from 3 except the
    S<vector<int>> variable.
*/



int main(int argc, char const *argv[]) {

    int a = val_int.get() + 3;
    cout << a << endl;

    test_read_and_print_using_get();
    return 0;
}
