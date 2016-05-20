#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

/* Part1: Using free-store allocated */
// Fill array with 10 random value int from 0 - 99
void fill_array(int *a, int size){
    srand (time(NULL));
    for(int i = 0; i < size; ++i)
        a[i] = rand() % 100;
}

ostream& print_array(ostream& os, int *a, int size){
    for(int i = 0; i < size; ++i)
        os <<"arr[" << i << "] = " << a[i] << endl;
    return os;
}

/* Part2: Using vector */
void fill_vector(vector<int> &v, int size){
    srand (time(NULL));
    for(int i = 0; i < size; ++i)
        v.push_back(rand()% 100);
}

ostream& print_vector(ostream& os, vector<int> v){
    for(int i = 0; i < v.size(); ++i)
        cout << "v[" << i << "] = " << v[i] << endl;
    return os;
}
int main(int argc, char const *argv[])
{
    int size = 20;

    int* arr = new int[size];
    print_array(cout, arr, size);

    fill_array(arr, size);
    print_array(cout, arr, size);

    cout << "---------------------------------------\n";
    vector<int> v;
    fill_vector(v,10);
    print_vector(cout, v);

    int* p = new int(7); //ex1
    cout << "Add of p: " << p << " value: " << *p;
    delete p;
    delete[] arr;
    return 0;
}
