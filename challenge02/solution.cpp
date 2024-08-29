// Challenge 02: Closest Numbers
// Name:  Ryan M. Grychowski

// Brief description:

// This code solves the problem of finding the smallest possible difference in a list 
// of numbers based on the storing values in a vector, iteratively subtracting values 
// of this vector after it is sorted, and stores these pairs in a vector to be sent to 
// console out. 

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
    
    int size;
    int number;

    // Parses through each line.
    while(cin >> size)
    {

        // Vector to store numbers 
        vector<int> numbers;

        // Parses through the second line that follows the size of the list of numbers.
        // Adds these numbers to vector.
        for(int i = 0; i < size; i++)
        {
            cin >> number;
            numbers.push_back(number);
        }

        // Establishes a ceiling for the largest value that the difference could be.
        int smallest_difference = INT_MAX;

        // Sorts the numbers for easy calculation.
        sort(numbers.begin(), numbers.end());

        // Vector to store pairs of numbers with the smallest difference.
        vector<pair<int, int>> closest_pair;

        // Parses through the list of numbers to find the smallest difference.
        for(int i = 1; i < size; i++)
        {

            int difference = numbers.at(i) - numbers.at(i - 1);

            // Tests for the smallest difference by comparing to the max int value initialized above.
            // If true, then add to vector of closest pairs.
            if(difference < smallest_difference)
            {
                smallest_difference = difference;
                closest_pair.clear();
                closest_pair.push_back({numbers.at(i - 1), numbers.at(i)});
            }

            // Otherwise, the differences could be equal which covers the case for duplicates.
            // Adds these duplicates to the closest pair vector.
            else if(difference == smallest_difference)
            {
                closest_pair.push_back({numbers.at(i - 1), numbers.at(i)});
            }
        }

        // Prints the vector with the smallest differences.
        for(size_t i = 0; i < closest_pair.size(); i++)
        {
            cout << closest_pair[i].first << " " << closest_pair[i].second;

            // Catches the case for an extra space at the end of each line.
            if(i < closest_pair.size() - 1)
            {
                cout << " ";
            }
        }
   
        cout << endl;

    }

    return EXIT_SUCCESS;
    
}

