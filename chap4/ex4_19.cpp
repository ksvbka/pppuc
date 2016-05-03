/*
Ex 4.19:  Write a program where you first enter a set of name-and-value pairs,
such as Joe 17 and Barbara 22. For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding positions, so
that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0.
Check that each name is unique and terminate with an error message if a name is
entered twice. Write out all the (name,score) pairs, one per line.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argc, char const *argv[]){
    try{
        vector<string> names;
        vector<int> scores;
        string name;
        int score;
        while(cin >> name >> score && name != "NoName"){
            for(int i = 0; i < names.size(); i++){
                if(name == names[i]) throw runtime_error("Duplicate");
            }
            names.push_back(name);
            scores.push_back(score);
        }
        for(int i = 0; i < name.size(); i++)
            cout << "Name: " << names[i] << "Score: " << scores[i] << endl;
        return 0;
    }catch(runtime_error &e){
        cout << e.what();
    }catch(...){
        cout << "Exiting...";
    }


}
