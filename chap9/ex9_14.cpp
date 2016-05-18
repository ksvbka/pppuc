/*Ex9.14
Design and implement a Money class for calculations involving dollars and
cents where arithmetic has to be accurate to the last cent using the 4/5
rounding rule (.5 of a cent rounds up; anything less than .5 rounds down).
Represent a monetary amount as a number of cents in a long int, but input and
output as dollars and cents, e.g., $123.45. Do not worry about amounts that
don’t fit into a long int.
*/

#include <iostream>
#include <stdexcept>

using namespace std;

/*Convert dollar (in doube) to cent */
long toCent(double m);

class Money
{
public:
    Money(): amount_(0) {};

    Money(double m): amount_(toCent(m)) {};

    Money(const Money& otherMoney){
        amount_ = otherMoney.amount_;
    }

    long amount() const {return amount_;}

    Money& operator+=(const Money& rhs);
    Money& operator-=(const Money& rhs);

    double toDollar();

    friend ostream& operator<<(ostream& os, const Money& rhs);
    friend istream& operator>>(istream& is, Money& rhs);
private:
    long amount_;
};
/*Helper function*/
Money operator+(Money lhs, Money rhs);
Money operator-(Money lhs, Money rhs);

/*----------------IMPLEMENT----------*/
long toCent(double m){
    long cent_x_10 = (long)(m * 1000);
    if(cent_x_10 % 10 > 5)
        return(cent_x_10 / 10 + 1);
    return(cent_x_10 / 10);
}
 Money& Money::operator+=(const Money& rhs){
    amount_ += rhs.amount();
    return *this;
 }

 Money& Money::operator-=(const Money& rhs){
    amount_ -= rhs.amount();
    return *this;
 }

Money operator+(Money lhs, Money rhs){
    return lhs += rhs;
}
Money operator-(Money lhs, Money rhs){
    return lhs -= rhs;
}

ostream& operator<<(ostream& os, const Money& rhs){
    cout << "$" << rhs.amount()/100 << "." << rhs.amount() % 100;
}
istream& operator>>(istream& is, Money& rhs){
    double input_money;
    cin >> input_money;
    rhs = Money(input_money);
}

int main(int argc, char const *argv[])
{
    Money a(1000.2345);
    Money b(23.3424);
    cout << a + b;
    cout << "Enter the amount of money: ";
    cin >> a;
    cout << a;
    return 0;
}
