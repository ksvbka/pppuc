/*Ex6.4 4. Define a class Name_value that holds a string and a value. Rework
exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Name_value{
public:
    string name_;
    int score_;
    Name_value(string name, int score):
        name_(name) , score_(score) {}
};

class ListStudent{
private:
    vector<Name_value> list;
public:
    bool is_vaild(string name){
        if(list.size() == 0) return 1;
        for(auto elem : list)
            if(elem.name_ == name) return 0;

        return 1;
    }
    void add(Name_value student){
        if(is_vaild(student.name_))
            list.push_back(student);
        else
            cout << "Doublicate name" << endl;
    }
    void input(){
        string name;
        int score;
        for(; cin >> name >> score && name != "NoName" && score != 0;){
            add({name,score});
        }
    }
    void printf(){
        for(auto elem : list)
            cout << " Name: " << elem.name_ << " \tScore: " << elem.score_ << endl;
    }

};

int main(int argc, char const *argv[])
{
    ListStudent List_student;
    try{
        List_student.input();
        List_student.printf();
    }catch(runtime_error &e){
        cout << e.what();
    }catch(...){
        cout << "Exiting...";
    }
    return 0;
}
