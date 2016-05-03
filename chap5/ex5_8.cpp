/*Write a program that reads and stores a series of integers and then computes the
sum of the first N integers. First ask for N, then read the values into a vector,
then calculate the sum of the first N values. For example:
“Please enter the number of values you want to sum:”
3
“Please enter some integers (press '|' to stop):”
12 23 13 24 15 |
“The sum of the first 3 numbers ( 12 23 13 ) is 48.”
Handle all inputs. For example, make sure to give an error message if the user
asks for a sum of more numbers than there are in the vector.*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<int> Sum_of_n_element(){
    int N;
    int sum = 0;
    vector<int> vec;
    cout << "Please enter the number of values you want to sum: " << endl;
    cin >> N;

    cout << "Please enter some integers (press '|' to stop)" << endl;
    for(int n; cin >> n; vec.push_back(n));

    if(N > vec.size())
        throw runtime_error("sum of more numbers than there are in vector \n");
    cout << "The sum of first " << N;
    cout << " (";
    for(int i = 0; i < N; ++i){
        cout << " " << vec[i];
        sum += vec[i];
    }
    cout << ")";
    cout << " is : " << sum << endl;;
    return vec;
}

vector<int> diff_vec(vector<int> vec){
    if(vec.size() <= 1)
        return vec;

    vector<int> ret;
    for(int i = 1; i < vec.size(); ++i)
        ret.push_back(vec[i] - vec[i - 1]);
    return ret;
}

int main(int argc, char const *argv[])
{
    try{
        vector<int> vec = Sum_of_n_element();
        vector<int> ret = diff_vec(vec);
        for(auto i : ret)
            cout << " " << i;
        cout << endl;
    }catch(runtime_error &e){
        cout << e.what();
    }catch(...){
        cout << "Exiting...";
    }
    return 0;
}
