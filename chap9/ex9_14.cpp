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
#include <vector>

using namespace std;

/*Convert dollar (in doube) to cent */
long toCent(double m);

/**/
struct Convert_coeff{
    string name_;
    double coeff_;
    Convert_coeff(string currency, double coeff)
    : name_(currency), coeff_(coeff)
    {}
};

/*Global convert table*/
static vector<Convert_coeff> Convert_table{Convert_coeff{"DKK", 2.5}};

/**/
double get_currency(string name){
    for(auto item : Convert_table){
        if(item.name_ == name)
            return item.coeff_;
    }
    throw runtime_error("Don't support this currency");
}

class Money
{
public:
    Money(): amount_(0) {};

    Money(double m): amount_(toCent(m)), currency_("USD") {};

    Money(double m, string currency)
        : amount_(toCent(m)), currency_(currency)
    {};

    Money(const Money& otherMoney){
        amount_ = otherMoney.amount_;
        currency_ = otherMoney.currency_;
    }

    long amount() const {return amount_;}
    string currency() const { return currency_;}

    Money& operator+=(const Money& rhs);
    Money& operator-=(const Money& rhs);

    double toDollar();

    friend ostream& operator<<(ostream& os, const Money& rhs);
    friend istream& operator>>(istream& is, Money& rhs);
private:
    long amount_;
    string currency_;
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
    amount_ += get_currency(rhs.currency()) * rhs.amount();
    return *this;
 }

 Money& Money::operator-=(const Money& rhs){
    amount_ -= get_currency(rhs.currency()) * rhs.amount();;
    return *this;
 }

Money operator+(Money lhs, Money rhs){
    return lhs += rhs;
}
Money operator-(Money lhs, Money rhs){
    return lhs -= rhs;
}

ostream& operator<<(ostream& os, const Money& rhs){
    cout << rhs.amount()/100 << "." << rhs.amount() % 100 << rhs.currency() ;
}

istream& operator>>(istream& is, Money& rhs){
    string input_currency;
    double input_money;

    cin >> input_money >>input_currency ;
    rhs = Money(input_money, input_currency);
}

int main(int argc, char const *argv[])
{
    try{
        Money a(1000.2345, "USD");
        Money b(100, "DKK");
        cout << a + b;
        cout << "Enter the amount of money: ";
        cin >> a;
        cout << a;
    }catch(runtime_error &e){
        cout << e.what();
    }
    return 0;
}
