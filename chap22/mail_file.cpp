#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message {
  public:
    Message(Line_iter p1, Line_iter p2): first_{p1}, last_{p2}
    {}
    Line_iter begin() const { return first_;}
    Line_iter end() const { return last_;}
    ~Message() {};
  private:
    Line_iter first_;
    Line_iter last_;
};

/*Define Mail file*/
using Mess_iter = vector<Message>::const_iterator;

struct Mail_file
{
    string name_;
    vector<string> lines_;
    vector<Message> msg_;

    Mail_file(const string& file_name); // Read file in to lines;

    Mess_iter begin() const { return msg_.begin();}
    Mess_iter end() const {return msg_.end();}

};

/*
    Initialize Mail file from a file.
    - Read the lines from file_name to file;
    - Find the messages in the lines and compose them in m
    - For simplicity assume every message is ended by a ---- line
*/
Mail_file::Mail_file(const string& file_name){
    ifstream in{file_name}; // open file
    if(!in){
        cerr << "no " << file_name << endl;
    }
    // Read conten to lines
    for(string s; getline(in,s);){
        lines_.push_back(s);
    }

    // build the vector of Messegases
    auto first = lines_.begin();
    for(auto p = lines_.begin(); p != lines_.end(); ++p){
        if(*p == "----"){ // End of messegase
            msg_.push_back(Message(first, p));
            first = p + 1;
        }
    }
}

/* Helper function */

int is_prefix(const string& s, const string& p){
    int n = p.size();
    if(string(s,0,n) == p) return n;
    return 0;
}

/*
    Find the name of the sender in a Message;
    return true if found
    if found, place the sender's name in s;
*/

bool find_from_addr(const Message* m, string& s){
   for(auto x = m->begin(); x != m->end(); ++x){
        if(int n = is_prefix(*x, "From: ")){
            s = string(*x,n);
            return true;
        }
    }
    return false;
}

string find_subject(const Message* m){
    // for(const auto& x : m)
    for(auto x = m->begin(); x != m->end(); ++x)
        if(int n = is_prefix(*x, "Subject: ")) return string(*x,n);
    return "";
}


int main(int argc, char const *argv[])
{
    Mail_file mfile{"my-email-file.txt"};

    /*Gather messages from each sender together in multimap */
    multimap<string, const Message*> sender;
    for(const auto& m : mfile){
        string s;
        if(find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    /* Iterate through the multimap and extract the subjects of sender name's message*/
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for(auto p = pp.first; p != pp.second; ++p)
        cout << find_subject(p->second) << "\n";

    return 0;
}
