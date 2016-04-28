/*
Ex 4.11: Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be divided by a prime number smaller than itself)
using a vector of primes in order (so that if the vector is called primes,
primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop that goes
from 1 to 100, checks each number to see if it is a prime, and stores each prime
found in a vector. Write another loop that lists the primes you found. You might
check your result by comparing your vector of prime numbers with primes.
Consider 2 the first prime.
*/

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> primes{2}; /*Vector hold primes number, init with first prime is 2*/

bool Is_prime(int n){
    for(auto prime : primes){
        if(n % prime == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    try {
        for(int i = 3; i < 100; ++i){
            if(Is_prime(i))
                primes.push_back(i);
        }
        for(auto prime : primes)
            cout << " " << prime;
    } catch (runtime_error &e) {
        cout << e.what() << '\n';
    } catch (...){
        cout << "exiting\n";
    }
}
