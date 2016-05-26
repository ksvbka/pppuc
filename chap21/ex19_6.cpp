#include <iostream>
#include <vector>

using namespace std;

/*6. In the Fruit example in §21.6.5, we copy Fruits into the set. What if we
   didn’t want to copy the Fruits? We could have a set<Fruit*> instead. However,
   to do that, we’d have to define a comparison operation for that set.
   Implement the Fruit example using a set<Fruit*, Fruit_comparison>. Discuss
   the differences between the two implementations.
*/

struct Fruit {
    string name;
    int count;
    double unit_price;

    Fruit() : name{""}, count{0}, unit_price{0}
    {}

    Fruit(string n, int c, double u): name{n}, count{c}, unit_price{u}
    {}
};

ostream& operator<<(ostream& os, const Fruit& obj)
{
    os << obj.name << " : " << obj.count << " : "<< obj.unit_price << endl;
    return os;
}

struct Fruit_order {
    bool operator()(const Fruit* a, const Fruit* b) const {
        return a->name < b->name;
    }
};

#include <set>
int main(int argc, char const *argv[])
{
    set<Fruit*, Fruit_order> inventory;
    inventory.insert(new Fruit{"a", 3, 3.3});
    inventory.insert(new Fruit{"z", 5, 5.5});
    inventory.insert(new Fruit{"b", 7, 7.7});

    for(auto elem : inventory)
        cout << *elem;
    return 0;
}
