/*Ex 5.10 Implement a little guessing game called (for some obscure reason) “Bulls
and Cows.” The program has a vector of four different integers in the range 0 to
9 (e.g., 1234 but not 1122) and it is the user’s task to discover those numbers
by repeated guesses. Say the number to be guessed is 1234 and the user guesses
1359; the response should be “1 bull and 1 cow” because the user got one digit
(1) right and in the right position (a bull) and one digit (3) right but in the
wrong position (a cow). The guessing continues until the user gets four bulls,
that is, has the four digits correct and in the correct order.*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<int> solution{1,3,4,7}; // Hardcode :D


vector<int> input_diff(){
    /*Input guesses vector - range 1-9 and difference value*/
    int n;
    vector<int> ret;
    cout << "Input guesses vector 4 element - range 1-9 and difference value" << endl;
    for(int i = 0; i < 4 && cin >> n; ++i){
        if(n > 9 && n < 0) throw runtime_error("Bad input \n");
        if(ret.size() == 0)
            ret.push_back(n);
        else{
            for(int i = 0; i < ret.size(); ++i)
                if(n == ret[i]) throw runtime_error("Double value\n");
            ret.push_back(n);
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    try{
        bool success = 0;
        while(!success){
            vector<int> guesses = input_diff();
            for(int i = 0; i < 4; i++){
                if(guesses[i] != solution[i]){
                    cout <<i+1 <<" cow and 1 bull" << endl;
                    cout << "guesses again!" << endl;
                    break;
                }
                if(i == 4){
                    success = 1;
                    cout << "Congratulation! you win!" << endl;
                }
            }
        }
    }catch(runtime_error &e){
        cout << e.what();
    }catch(...){
        cout << "Exiting...";
    }

    return 0;
}
