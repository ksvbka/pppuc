/*
    Ex 4_7 Modify the “mini calculator” from exercise 5 to accept (just) single-
    digit numbers written as either digits or spelled out.
*/

//#include "std_lib_facilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Vector to hold spelled out of digit
vector<string> spelled_digit{"zero","one", "two", "three", "four", "five", \
                             "six", "seven", "eight", "nine"};
// Vector to hold digit
vector<string> digit{"0","1", "2", "3", "4", "5", "6", "7", "8", "9"};

int digit_parse(string value){
    for(int i = 0; i < 10; ++i){
        if( value == spelled_digit[i] || value == digit[i])
            return i;
    }
    throw runtime_error("Bad input value");
}

int Mini_calculator(){
    cout<< "please enter two single digit (number or spelled out) values separated by an operator\n \
            The operator can be + - * or / : ";
    string str_val1;
    string str_val2;
    char op = 0;
    while (cin>> str_val1 >> op >> str_val2) {   // read number operation number
        string oper;
        int val1 = digit_parse(str_val1);
        int val2 = digit_parse(str_val2);
        int result;
        switch (op) {
        case '+':
            oper = "sum of ";
            result = val1 + val2;
            break;
        case '-':
            oper = "difference between ";
            result = val1 - val2;
            break;
        case '*':
            oper = "product of ";
            result = val1 * val2;
            break;
        default:
                runtime_error("bad operator");
        }
        cout << oper << val1 << " and " << val2 << " is " << result << endl;
        cout << "Try again: " << endl;;
    }
}


int main(int argc, char const *argv[]) {
    try {
        Mini_calculator();
    } catch (runtime_error &e) {
        cout << e.what() << '\n';
    } catch (...){
        cout << "exiting\n";
    }
}
