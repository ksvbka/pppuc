/* Ex4.3: Read a sequence of double values into a vector. Think of each value as
the distance between two cities along a given route. Compute and print the total
distance (the sum of all distances). Find and print the smallest and greatest
distance between two neighboring cities. Find and print the mean distance
between two neighboring cities.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<double> distances;
    double sum = 0;
    double smallest;
    double greatest;

    cout << "Enter the distances of cities:" << endl;

    for(double value; cin >> value;){
        distances.push_back(value);
        sum += value;
        if(distances.size() == 1)
            smallest = greatest = distances[0];
        else{
            smallest = smallest > value ? value : smallest;
            greatest = greatest < value ? value : greatest;
        }
    }

    cout << " The mean distance is: "       << sum/distances.size() << endl;
    cout << " The smallest distances is : " << smallest << endl;
    cout << " The greatest distances is : " << greatest << endl;

    return 0;
}
