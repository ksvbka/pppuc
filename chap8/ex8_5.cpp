/*
Ex 8.5:
Write two functions that reverse the order of elements in a vector<int>. For
example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should
produce a new vector with the reversed sequence, leaving its original vector
unchanged. The other reverse function should reverse the elements of its vector
without using any other vectors (hint: swap).
*/

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm> // for swap (c++98)
#include <utility>  // for swap (c++11)

using namespace std;

vector<int> create_reverse(vector<int> v){
    vector<int> reverse;
    for(int i = v.size() - 1; i >= 0; --i)
        reverse.push_back(v[i]);
    return reverse;
}

void reverse_this(vector<int>& v){
    int mid = v.size() / 2;
    int end = v.size() -1;
    for(int i = 0; i < mid; ++i)
        swap(v[i], v[end - i]);
}

// int main(int argc, char const *argv[])
// {
//     vector<int> v{1,2,3,4,5,6,7};
//     try{
//         /*Test create_reverse:*/
//         vector<int> reverse = create_reverse(v);
//         for(auto i : reverse)
//             cout << " " << i;
//         cout << endl;
//         Test reverse_this:
//         reverse_this(v);
//         for(auto i: v)
//             cout << " " << i;
//         cout << endl;
//     }catch(runtime_error &e){
//         cout << e.what() << endl;
//     }catch(...){
//         cout << "Exiting..." << endl;
//     }
//     return 0;
// }

int main(int argc, char const *argv[])
{
    vector<int> v(10000,10000);
    try{
        // /*Test performance of create_reverse: real  0m0.452s*/
        // for (int i = 0; i < 1000; ++i)
        //     vector<int> reverse = create_reverse(v);

        // /*Test performance of reverse_this: real  0m0.144s*/
        // for (int i = 0; i < 1000; ++i)
        //     reverse_this(v);

        /*Test performance of std lib: real  0m0.215s ???*/
        for (int i = 0; i < 1000; ++i)
            reverse(v.begin(), v.end());
    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting..." << endl;
    }
    return 0;
}
