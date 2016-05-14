#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
/*Ex8.2:
Write a function print() that prints a vector of ints to cout. Give it
two arguments: a string for “labeling” the output and a vector.
*/

void print(string label, vector<int> v){
    cout << label << ": " << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " " ;
}

/*Ex8.3:
Create a vector of Fibonacci numbers and print them using the function
from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n),
where integers x and y are ints, v is an empty vector<int>, and n is the number
of elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number
is one that is part of a sequence where each element is the sum of the two
previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21,
. . . . Your fibonacci() function should make such a sequence starting with its
x and y arguments.
*/

void fibonacci(int x, int y, vector<int>& v, int n){
    if(n <= 0) {
        cout << "n can't <= 0" << endl;
        return;
    }
    v.clear();
    if(n >= 1) v.push_back(x);
    if(n >= 2) v.push_back(y);
    int z; // hold temp data
    for(int i = 2; i < n; ++i){
        z = x + y;
        v.push_back(z);
        x = y;
        y = z;
    }
    return;
}

int main(int argc, char const *argv[])
{
    char exit = 'n';
    int n;
    int firstElem;
    int secondElem;
    vector<int> vFibonacci;
    try{
        while(exit != 'y' || exit != 'Y'){
            cout << "Element of Fibonacci: n = ";
            cin >> n;

            cout << "\nfirstElem: ";
            cin >> firstElem;

            cout << "\nsecondElem: ";
            cin >> secondElem;

            fibonacci(firstElem,secondElem,vFibonacci,n);

            print("Result: ",vFibonacci);

            cout << "\nDo you what to exit? (y/n): ";
            cin >> exit;
        }
        return 0;
    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting..." << endl;
    }

}

