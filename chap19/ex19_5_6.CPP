/*5. Define a class Int having a single member of class int. Define constructors,
   assignment, and operators +, –, *, / for it. Test it, and improve its design
   as needed (e.g., define operators << and >> for convenient I/O).
6. Repeat the previous exercise, but with a class Number<T> where T can be any
   numeric type. Try adding % to Number and see what happens when you try to use
   % for Number<double> and Number<int>.
*/
#include <iostream>

using namespace std;

template<typename T>
class Number
{
public:
    Number(){};
    Number(T val): val_{val} {}
    ~Number(){};
    /*Copy constructor*/
    Number(const T& rhs){
        val_ = rhs.val_;
    }
    /*Assignment*/
    Number& operator=(const T& rhs){
        val_ = rhs.val_;
        return *this;
    }

    T val() { return val_; }
    const T val() const { return val_;}

    void set(T buff) { val_ = buff;}

    Number& operator+=(const Number& rhs){
        val_ += rhs.val();
        return *this;
    }

    Number& operator-=(const Number& rhs){
        val_ -= rhs.val();
        return *this;
    }

    Number& operator*=(const Number& rhs){
        val_ *= rhs.val();
        return *this;
    }
    template<typename L>
    friend ostream& operator<<(ostream& os, const Number<L>& rhs);

    template<typename L>
    friend istream& operator>>(istream& is, Number<L>& rhs);
private:
    T val_;
};
template<typename T>
Number<T> operator+(Number<T> arg1, Number<T> arg2){
    return arg1 += arg2;
}

template<typename T>
Number<T> operator-(Number<T> arg1, Number<T> arg2){
    return arg1 -= arg2;
}

template<typename T>
Number<T> operator*(Number<T> arg1, Number<T> arg2){
    return arg1 *= arg2;
}

template<typename T>
ostream& operator<<(ostream& os, const Number<T>& rhs){
    os << rhs.val_;
    return os;
}

template<typename T>
istream& operator>>(istream& is, Number<T>& rhs){
    is >> rhs.val_;
    return is;
}

int main(int argc, char const *argv[])
{
    Number<int> s1, s2;
    cout << "Input two numbers: ";
    cin >> s1 >> s2;
    cout << "sum: "<< s1 + s2 << endl;
    cout << "Sub: "<< s1 - s2 << endl;
    cout << "Mul: "<< s1 * s2 << endl;
    return 0;
}
