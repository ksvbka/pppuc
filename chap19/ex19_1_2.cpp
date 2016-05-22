#include <iostream>
#include <vector>

using namespace std;
/*
1. Write a template function f() that adds the elements of one vector<T> to the
   elements of another; for example, f(v1,v2) should do v1[i]+=v2[i] for each
   element of v1.
*/

template<typename T>
void f(vector<T> &v1, const vector<T> &v2){
    int min_leng = v1.size() < v2.size() ? v1.size() : v2.size();

    for(int i = 0; i < min_leng; ++i)
        v1[i] += v2[i];

    if(v1.size() >= v2.size())
        return;
    else
        for(int i = min_leng; i < v2.size(); ++i)
            v1.push_back(v2[i]);
    return;
}

/*
2. Write a template function that takes a vector<T> vt and a vector<U> vu as
   arguments and returns the sum of all vt[i]*vu[i]s.
*/

template<typename T>
T g(const vector<T> &vt, const vector<T> &vu){
    T sum = 0;
    int min_leng = vt.size() < vu.size() ? vt.size() : vu.size();
    for(int i = 0; i < min_leng; ++i)
        sum += vt[i] * vu[i];
    if(vt.size() == vu.size())
        return sum;
    if(vt.size() > vu.size())
        for(int i = min_leng; i < vu.size(); ++i)
            sum += vu[i];
    else
        for(int i = min_leng; i < vt.size(); ++i)
            sum += vt[i];
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<int> v1 {1, 3, 5, 7};
    vector<int> v2 {2,3,4,5,65,6,7,};

    f(v1,v2);
    for(auto i : v1)
        cout << " " << i;
    cout << endl;
    cout << "sum: " <<  g(v1,v2) << endl;
    return 0;
}
