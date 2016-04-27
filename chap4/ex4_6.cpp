/*
Ex4.6: Make a vector holding the ten string values "zero", "one", . . . "nine". Use
that in a program that converts a digit to its corresponding spelled-out value;
e.g., the input 7 gives the output seven. Have the same program, using the same
input loop, convert spelled-out numbers into their digit form; e.g., the input
seven gives the output 7.
*/

// #include "std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int Convert_number_app(){
    // Vector to hold spelled out of digit
    vector<string> spelled_digit{"one", "two", "three", "four", "five", \
                                 "six","seven", "eigh", "nine"};
    // Vector to hold digit
    vector<string> digit{"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for(string input; cin >> input && input != "quit";){
        for(int i = 0; i < digit.size(); ++i){
            // Check to detect input is digit
            if(input == digit[i]){
                cout << spelled_digit[i] << endl;
                break;
            }
            // Check to detect input is speelled digit
            else if(input == spelled_digit[i]){
                cout << digit[i] << endl;
                break;
            }
            // Detect bad input
            if(i == digit.size() -1 )
                cout << "Bad input!" << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    try {
        Convert_number_app();
    } catch (runtime_error e) {
        cout << e.what() << '\n';
    } catch (...){
        cout << "exiting\n";
    }
}
