#include <iostream>
#include <vector>

using namespace std;

/*3. Implement count() yourself. Test it.*/
template <typename Iterator, typename T>
int my_count(Iterator begin, Iterator end, const T& val) {
    int ret = 0;
    for (auto p = begin; p != end; ++p)
        if (*p == val) ret++;
    return ret;
}

/*4. Implement count_if() yourself. Test it.*/

template <typename Iterator, typename Pred>
int my_count_if(Iterator begin, Iterator end, const Pred& f) {
    int ret = 0;
    for (auto p = begin; p != end; ++p)
        if (f(*p)) ret++;
    return ret;
}

#include <vector>

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v{1,2,3,4,5,6,7,8,3,3};
    cout << my_count(v.begin(), v.end(), 3);
    cout << my_count_if(v.begin(), v.end(), [](const int& a){return a > 3;});

    return 0;
}
