#include <iostream>
#include <vector>

using namespace std;


/*7. Write a binary search function for a vector<int> (without using the standard
   one). You can choose any interface you like. Test it. How confident are you
   that your binary search function is correct? Now write a binary search
   function for a list<string>. Test it. How much do the two binary search
   functions resemble each other? How much do you think they would have
   resembled each other if you had not known about the STL?
   */


/* Only use for data struct support random accept []*/

template <typename Iter, typename T>
Iter my_binary_search(Iter begin, Iter end, const T& val)
{
    while(end - begin > 0){
        Iter mid = begin + (end - begin) / 2;
        if(*mid == val)
            return mid;
        if(*mid  < val)
            begin = mid + 1;
        else
            end = mid -1;
    }
    return end;
}

#include <vector>
#include <set>
int main(int argc, char const *argv[])
{
    vector<int> v{1,2,4,6,8, 23, 45, 46};
    auto p = my_binary_search(v.begin(), v.end(), 65);
    if(p != v.end())
        cout << *p;
    else
        cout << "\n Not found!";

    //NOTE: Failt to apply to list, map .. because it set and list don't support
    random accest []

    set<string> l;
    l.insert("Ana");
    l.insert("Gates");
    l.insert("Bill");
    l.insert("Zark");
    l.insert("Clever");

    // auto q = my_binary_search(l.begin(), l.end(), "Clever");
    // if(q != l.end())
    //     cout << *q;
    // else
    //     cout << "\n Not found!";

    return 0;
}


