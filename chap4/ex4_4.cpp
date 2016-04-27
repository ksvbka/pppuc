/*
Ex4.4: Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure out what the
number is (e.g., “Is the number you are thinking of less than 50?”). Your
program should be able to identify the number after asking no more than seven
questions. Hint: Use the < and <= operators and the if-else construct.
*/

#include <iostream>
#include <cassert>

using namespace std;

int App_main()
{
    int low = 0;
    int high = 100;
    int mid;
    int guess;
    char ret;

    cout << "Enter the guess: " << endl;
    cin >> guess;

    while(low <= high){
        mid = (low + high) / 2;
        if(mid == guess){
            cout << "You are thinking about " << mid << ":lmao: "<< endl;
            return 0;
        }

        cout << "Is the number you are thinking of less than " << mid << " ?" <<endl;
        cin >> ret;
        if(ret == 'y' || ret == 'Y')
            high = mid + 1;
        else
            low = mid - 1;
    }
    return 0;
}

int main(){
    try{
        App_main();
    }catch(runtime_error e){
        cout << e.what() << endl;
    }catch(...){
        cout << "exiting .." << endl;
    }
}
