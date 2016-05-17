/*
Ex9.2:
Design and implement a Name_pairs class holding (name,age) pairs where name is a
string and age is a double. Represent that as a vector<string> (called name) and
a vector<double> (called age) member. Provide an input operation read_names()
that reads a series of names. Provide a read_ages() operation that prompts the
user for an age for each name. Provide a print() operation that prints out the
(name[i],age[i]) pairs (one per line) in the order determined by the name vector.
Provide a sort() operation that sorts the name vector in alphabetical order and
reorganizes the age vector to match. Implement all “operations” as member
functions. Test the class (of course: test early and often).

*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Name_pairs{
public:
    Name_pairs(){};
    ~Name_pairs(){};

    /*Read serial of input name, end by string "end" */
    void read_names();
    /*Read the age of each name input*/
    void read_ages();
    /*Print the name - age in one line, order by name vector*/
    void print();
    /*Sort name vector and reorganizes the age vector to match*/
    void sort_name();

private:
    vector <string> name;
    vector <double> age;
};

void Name_pairs::read_names(){
    cout << "Enter the serial of name, end by string 'end' "<< endl;
    for(string s; cin >> s && s != "end";){
        name.push_back(s);
    }
}

void Name_pairs::read_ages(){
    int size = name.size();
    double age_;
    cout << "You are input " << size << " name, Enter the age of each name inputed "<< endl;
    for(int i = 0; i < size; ++i){
        cout << "Age of " << name[i] << " :";
        cin >> age_;
        // TODO: cheking vaild age_
        age.push_back(age_);
    }
}

void Name_pairs::print(){
    for(int i = 0; i < name.size(); ++i)
        cout << name[i] << "\t: " << age[i] << endl;
}

void Name_pairs::sort_name(){
    /*TODO: Incerase performance*/
    vector<string> org_name = name;
    vector<double> sorted_age = vector<double>(name.size());
    sort(name.begin(), name.end());

    for(int i = 0; i < name.size(); ++i){
        for(int j = 0; j < name.size(); ++j){
            if(name[i] == org_name[j])
                sorted_age[i] = age[j];
        }
    }
    age = sorted_age;
}

int main(int argc, char const *argv[])
{
    Name_pairs myName_pairs;
    myName_pairs.read_names();
    myName_pairs.read_ages();
    myName_pairs.print();
    cout << "Sort name to alphabetical: "<< endl;
    myName_pairs.sort_name();
    myName_pairs.print();
    return 0;
}
