#include <iostream>
#include <limits>

using namespace std;

enum error_code{
    ER_NOUN,
    ER_VERB,
    ER_CONJ,
    NO_ERR
};

bool is_noun(string token){
    return( token == "birds" || token == "fish" || token == "c++");
}

bool is_verb(string token){
    return( token == "rules" || token == "fly" || token == "swim");
}

bool is_conjunction(string token){
    return( token == "and" || token == "or" || token == "but");
}

int sentence(){
    string token;
    cin >> token;
    if(!is_noun(token)){
        // return "nFalse - expected noun";
        return ER_NOUN;
    }
    cin >> token;
    if(!is_verb(token)){
        // return "False - expected verb";
        return ER_VERB;
    }
    if(cin >>token){
        if(is_conjunction(token))
            sentence();
        else
            return ER_CONJ;
    }
    return NO_ERR;
}

int main(int argc, char const *argv[]){

    cout << "sentence demo:" << endl;
    string token;
    while(cin){
        char ch;
        cin >> ch;
        if(ch == 'q') break;
        cin.putback(ch);

        int ret = sentence();
        switch(ret){
            case ER_NOUN:
                cout << "False - expected noun" << endl; break;
            case ER_VERB:
                cout << "False - expected verb" << endl; break;
            case ER_CONJ:
                cout << "False - expected conjunction" << endl; break;
            case NO_ERR:
                cout << "ok" << endl; break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}
