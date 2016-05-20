/*Implement double linked list by pointer*/
#include <iostream>
using namespace std;

class Link{
public:
    string value;
    Link(const string& v, Link* p = nullptr, Link* n = nullptr)
        : value(v), prev_(p), next_(n) {}
    Link* insert(Link* n);          /*Insert n before this object*/
    Link* add(Link* n);             /*Insert n after this object*/
    Link* erase();                  /*Remove this object from list*/
    Link* find(const string& s);    /*Find s in const list*/
    const Link* find(const string& s) const;

    Link* advance(int n) const;     /*Move n position in list*/

    Link* next() const{ return next_;}
    Link* prev() const{ return prev_;}

private:
    Link* prev_;
    Link* next_;
};

/*Implement*/

Link* Link::insert(Link* n){
    if(n == nullptr) return this;
    if(this == nullptr) return n;

    n->next_ = this;
    if(prev_)
        prev_->next_ = n;
    n->prev_ = prev_;
    prev_ = n;

    return n;
}

/*Insert n after this object*/
Link* Link::add(Link* n){
    if(n == nullptr) return this;
    if(this == nullptr) return n;
    n->next_ = next_;
    if(next_)
        next_->prev_ = n;
    next_ = n;

    return n;
}
// Remove this object from list
Link* Link::erase(){
    if(this == nullptr) this;
    prev_->next_ = next_;
    if(next_)
        next_->prev_ = prev_;
    delete this;
}
/*Find s in const list*/
Link* Link::find(const string& s){
    while(this != nullptr){
        if(value == s)
            return this;
        prev_ = this;
        next_ = next_->next_;
    }
    return nullptr;
}

void print_all(Link* p){
    cout << "{" ;
    while(p){
        cout << p->value;
        if(p = p->next()) cout << ",";
    }
    cout << "}";
}

int main(int argc, char const *argv[])
{
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));

    print_all(norse_gods);
    return 0;
}

