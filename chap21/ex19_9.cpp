/*
9. Define an Order class with (customer) name, address, data, and
   vector<Purchase> members. Purchase is a class with a (product) name,
   unit_price, and count members. Define a mechanism for reading and writing
   Orders to and from a file. Define a mechanism for printing Orders. Create a
   file of at least ten Orders, read it into a vector<Order>, sort it by name
   (of customer), and write it back out to a file. Create another file of at
   least ten Orders of which about a third are the same as in the first file,
   read it into a list<Order>, sort it by address (of customer), and write it
   back out to a file. Merge the two files into a third using std::merge().
*/

#include <iostream>
#include <vector>

using namespace std;

class Purchase
{
public:
    Purchase(): product_name_{""}, unit_price_{0}, unit_count_{0}
    {}
    Purchase(string name, double price, double count)
        : product_name_{name}, unit_price_{price}, unit_count_{count}
    {}

    string& product_name() { return product_name_;}
    const string& product_name() const { return product_name_;}

    double unit_price() { return unit_price_;}
    const double unit_price() const { return unit_price_;}

    double unit_count() { return unit_count_;}
    const double unit_count() const { return unit_count_;}

    friend ostream& operator<<(ostream& os, const Purchase& purchase);
    friend istream& operator>>(istream& is, Purchase purchase);

private:
    string product_name_;
    double unit_price_;
    double unit_count_;
};

ostream& operator<<(ostream& os, const Purchase& purchase){
    os << purchase.product_name_ <<"\t" << purchase.unit_price_ << "\t" << purchase.unit_count_ << endl;
    return os;
}

istream& operator>>(istream& is, Purchase& purchase){
    ;
}

class Customer
{
public:
    Customer(): name_{""}, address_{""}, goods_()
    {}
    Customer(string name, string address, const vector<Purchase>& goods)
        : name_{name}, address_{address}, goods_{goods}
    {}

    string& name() {return name_;}
    const string& name() const{return name_;}

    vector<Purchase>& list_goods() {return goods_;}
    const vector<Purchase>& list_goods() const {return goods_;}

    friend ostream& operator<<(ostream& os, const Customer& customer);
    friend istream& operator>>(istream& is, Customer customer);

    void print_list_goods(ostream& os) const {
        os << "\t LIST GOODS" << endl;
        int index = 1;
        for(auto p : goods_)
            os << index++ <<". "<< p;
    }

    /*TODO: Use stl algorithm */
    const double total() const {
        double ret = 0;
        for(auto p : goods_)
            ret += p.unit_price() * p.unit_count();
        return ret;
    }

private:
    string name_;
    string address_;
    vector<Purchase> goods_;
};

ostream& operator<<(ostream& os, const Customer& customer){
    os << "\t INVOICE" << endl;
    os << "--------------------------------" << endl;
    os << "Name   : " << customer.name_ << endl;
    os << "address: "<< customer.address_<< endl;
    os << "--------------------------------" << endl;
    customer.print_list_goods(os);

    os << "--------------------------------" << endl;
    os << "               TOTAL: " << customer.total() << endl;
    return os;
}

istream& operator>>(istream& is, Customer customer){
;
}

#include <algorithm>
int main(int argc, char const *argv[])
{
    vector<Customer> test;
    test.push_back({"Kien", "SeeSpace",vector<Purchase>{{"Macbook", 340000, 2}} });
    test.push_back({"Bill Gate", "MicroSoft",vector<Purchase>{{"Boing 747", 340000, 2}}});
    test.push_back({"Obama", "USA",vector<Purchase>{{"China", 340000, 2}}});

    sort(test.begin(), test.end(), \
        [](const Customer& a, const Customer&b){ \
            return a.name() < b.name();
        }\
    );

    for(auto elem : test)
        cout << "\n\n" << elem;
    return 0;
}
