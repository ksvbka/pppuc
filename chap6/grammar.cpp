#include <iostream>

using namespace std;

bool is_noun(string token){
    return( token == "birds" || token == "fish" || token == "c++");
}

bool is_verb(string token){
    return( token == "rules" || token == "fly" || token == "swim");
}

bool is_conjunction(string token){
    return( token == "and" || token == "or" || token == "but");
}

string sentence(){
    string token;
    cin >> token;
    if(!is_noun(token)){
        // cout << "\nFalse - expected noun" << endl;
        return "false";
    }
    cin >> token;
    if(!is_verb(token)){
        // cout << "\nFalse - expected verb" << endl;
        return "false";
    }
    if(cin >>token){
        if(is_conjunction(token))
        sentence();
    }
    return "ok";
}

int main(int argc, char const *argv[])
{
    cout << "sentence demo:" << endl;
    string token;
    bool val = false;
    while(cin){
        char ch;
        cin >> ch;
        if(ch == 'q') break;
        cin.putback(ch);

        cout << sentence() << endl;
    }
    return 0;
}
