/*Try to calculate the number of rice grains that the inventor asked for in
exercise 8 above. You’ll find that the number is so large that it won’t fit in
an int or a double. Observe what happens when the number gets too large to
represent exactly as an int and as a double. What is the largest number of
squares for which you can calculate the exact number of grains (using an int)?
What is the largest number of squares for which you can calculate the
approximate number of grains (using a double)?*/

#include <iostream>
#include <cstdint> // Use for INT32_MAX
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
    else{
        grain = grain_nth[n - 2] * grain_nth[n - 2];
        grain_nth.push_back(grain);
    }

    return grain;
}

int Max_square_grain_int(){
    int count;
    long long sum = 0;
    for(count = 1; sum <= INT32_MAX; ++count){
        sum += cal_grain_nth(count);
    }
    cout << "Max grain in int is: " << sum << " square : "<< count -1 << endl;
}

int main(int argc, char const *argv[]) {
    try {
        Max_square_grain_int();
    } catch (runtime_error &e) {
        cout << e.what() << '\n';
    } catch (...){
        cout << "exiting\n";
    }
}
