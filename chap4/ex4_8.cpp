/* Ex 4.8: There is an old story that the emperor wanted to thank the inventor of
the game of chess and asked the inventor to name his reward. The inventor asked
for one grain of rice for the first square, 2 for the second, 4 for the third,
and so on, doubling for each of the 64 squares. That may sound modest, but there
wasn’t that much rice in the empire! Write a program to calculate how many
squares are required to give the inventor at least 1000 grains of rice, at least
1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of
course, and probably an int to keep track of which square you are at, an int to
keep the number of grains on the current square, and an int to keep track of the
grains on all previous squares. We suggest that you write out the value of all
your variables for each iteration of the loop so that you can see what’s going
on.*/

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Vector hold grain of nth cell;
vector<long long> grain_nth;

long long cal_grain_nth(int n){
    long long grain;
    if(n <= 0)
        throw runtime_error("Bad input");
    if(n <= 2){
        grain = n;
        grain_nth.push_back(grain);
    }
    else
        grain = grain_nth[n - 2] * grain_nth[n - 2];
    grain_nth.push_back(grain);
    return grain;
}

int Least_square_calculation(){
    long long grain_goal;
    cout << "Input the grains you need: ";
    cin >> grain_goal;

    long long sum = 0;
    int count;
    for(count = 1; sum < grain_goal; ++count){
        sum += cal_grain_nth(count);
        cout << "Square: " << count << " grains: " << sum << endl;
    }
    cout << "The least square you need is " << count - 1;
    return 0;
}

int main(int argc, char const *argv[]) {
    try {
        Least_square_calculation();
    } catch (runtime_error &e) {
        cout << e.what() << '\n';
    } catch (...){
        cout << "exiting\n";
    }
}

