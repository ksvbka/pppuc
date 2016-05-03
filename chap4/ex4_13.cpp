/* Ex4.13 Create a program to find all the prime numbers between 1 and 100.
There is a classic method for doing this, called the “Sieve of Eratosthenes.” If
you don’t know that method, get on the web and look it up. Write your program
using this method.*/

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> primes; /*Vector hold primes number, init with first prime is 2*/

int Sieve_of_eratosthenes(int n){
    /*Init*/
    for(int i = 2; i <= n ; ++i)
        primes.push_back(i);
    /*Calculation*/
    for(int i = 0; i < primes.size(); ++i)
        for(int j = i+1; j < primes.size(); ++j){
            if(primes[j] % primes[i] == 0)
                primes.erase(primes.begin() + j);
        }
}

int main(){
    try{
        cout << "Enter max range of sieve array: " << endl;
        int n;
        cin >> n;
        Sieve_of_eratosthenes(n);
        for(auto elem : primes)
            cout << " " << elem;

    }catch(runtime_error &e){
        cout << e.what();
    }
    catch(...){
        cout << "Exiting!";
    }
}
