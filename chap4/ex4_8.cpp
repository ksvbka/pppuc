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

using namespace std;

int Least_square_calculation(){
    long long grain_goal;
    cout << "Input the grains you need: ";
    cin >> grain_goal;

    if( grain_goal == 1){
        cout << "The least square you need is 1";
        return 0;
    }
    if( grain_goal <= 3){
        cout << "The least square you need is 2";
        return 0;
    }

    long long grain_cal = 3;
    long long grain_nth = 2;
    int square_count;

    for(square_count = 3; grain_cal < grain_goal; ++square_count){
        grain_nth *= grain_nth;
        grain_cal += grain_nth;
        cout << "Square: " << square_count << " grains: " << grain_cal << endl;
    }
    cout << "The least square you need is " << square_count;
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

