/*Ex 4.16 In the drill, you wrote a program that, given a series of numbers, found
the max and min of that series. The number that appears the most times in a
sequence is called the mode. Create a program that finds the mode of a set of
positive integers.*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/*Create data struct to hold number and count*/
struct Number {
    int value;
    int count;
    Number(): value(0), count(0) {}
    Number(int _value) : value(_value), count(0) {}
};

int main(int argc, char const *argv[]) {
    vector<Number> vec;
    int flag = 0;

    /* Input value */
    cout << "Enter the series integer, end with \"e\" " << endl;
    for (int n; cin >> n;) {
        if (vec.size() == 0)
            vec.push_back(n);
        else {
            for (int i = 0; i < vec.size(); ++i) {
                if (vec[i].value == n) {
                    vec[i].count++;
                    flag = 1;
                }
            }
            if (!flag)
                vec.push_back(n);
            flag = 0;

        }
    }

    /*Find "mode" */
    Number mode = vec[0];

    for (auto elem : vec) {
        if (mode.count < elem.count)
            mode = elem;
    }

    cout << "Mode of array is: " << mode.value << " Count: " << mode.count << endl;
    return 0;
}

