/*Ex5.9 Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Find the largest
Fibonacci number that fits in an int.*/

#include <iostream>
#include <cstdint> // Use for INT32_MAX
#include <stdexcept>
#include <vector>

using namespace std;

vector<long long> fibonacci;

long long Fibonacci_nth(int n){
    if(n < 0) throw runtime_error("Bad input \n");
    long long ret;
    if(n <= 1){
        ret = 1;
        fibonacci.push_back(ret);
    }
    else{
        ret = fibonacci[n -2] + fibonacci[n -1];
        fibonacci.push_back(ret);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    try{
        cout << " Print all fibonacci that the values in range of int" << endl;
        long long ret;
        for(int i = 0; Fibonacci_nth(i) < (long long) (INT32_MAX); ++i)
            cout << fibonacci[i] << endl;
        return 0;

    }catch(runtime_error &e){
        cout << e.what();
    }catch(...){
        cout << "Exiting...";
    }

}
