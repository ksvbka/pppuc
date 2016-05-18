/*Ex9.13
Design and implement a rational number class, Rational. A rational number has
two parts: a numerator and a denominator, for example, 5/6 (five-sixths, also
known as approximately .83333). Look up the definition if you need to. Provide
assignment, addition, subtraction, multiplication, division, and equality
operators. Also, provide a conversion to double. Why would people want to use a
Rational class?
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class Rational{
public:

    Rational(int num): num_(num), den_(1) {};
    Rational(int num, int den): num_(num), den_(den) {
        if(den_ == 0) throw runtime_error("Divide 0");
    };

    Rational(const Rational& ra): num_(ra.num_), den_(ra.den_) {};
    ~Rational(){};

    double to_double();
    int num() { return num_;}
    int den() { return den_;}
    int num() const { return num_;}
    int den() const { return den_;}

    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational&  rhs);
    Rational& operator*=(const Rational&  rhs);
    Rational& operator/=(const Rational&  rhs);
    friend ostream& operator<<(ostream& os, const Rational& rhs);
private:
    int num_;
    int den_;
};

double Rational::to_double(){
    return (double(num_)/double(den_));
}

Rational& Rational::operator+=(const Rational& rhs){
    num_ =num_ * rhs.den() + den_ * rhs.num();
    den_ = den_ * rhs.den();
    return *this;
}

Rational& Rational::operator-=(const Rational&  rhs){
    num_ =num_ * rhs.den() - den_ * rhs.num();
    den_ = den_ * rhs.den();
    return *this;
}

Rational& Rational::operator*=(const Rational&  rhs){
    num_ *= rhs.num();
    den_ *= rhs.den();
    return *this;
}

Rational& Rational::operator/=(const Rational&  rhs){
    num_ *= rhs.den();
    den_ *= rhs.num();
    return *this;
}

Rational operator+(Rational  left, const Rational&  right){
    return left+=right;
}

Rational operator-(Rational  left, const Rational&  right){
    return left -= right;
}

Rational operator*(Rational  left, const Rational&  right){
    return left*= right;
}

Rational operator/(Rational left, const Rational&  right){
    return left /= right;
}

ostream& operator<<(ostream& os, const Rational& rhs){
    os << rhs.num() << "/" << rhs.den();
    return os;
}

int main(int argc, char const *argv[])
{
    try{
        Rational a (1,2);
        cout << a + 3 << endl;

        Rational b(a);
        Rational c(3,4);
         cout << b + a + c << endl;

    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting..." << endl;
    }

    return 0;
}
