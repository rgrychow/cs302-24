/* Ryan Grychowski, solution.cpp

Challenge #1 - Reads an input file that contains a sequence size, rotate value, and 
rotation direction followed by a sequence of numbers with size corresponding to the value 
specified. The program will preform the indicated rotation and write the rotated sequences
to an output file. 

*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

    int size;
    int rotate_val;
    char direction;

    int number;

    vector<int> sequence;

    // Reads in the size, rotate value, and direction and stores
    // these values in their respective variables.
    while(cin >> size >> rotate_val >> direction)
    {
        // Reads in the sequence of numbers and stores them in 
        // vector sequence.
        for(int i = 0; i < size; i++)
        {
            cin >> number;
            sequence.push_back(number);
        }

        // Performs the right rotation algorithm if true.
        if(direction == 'R')
        {
            for(int j = 0; j < rotate_val; j++)
            {

                int last = sequence.back();

                // Works end to beginning of sequence and brings the first 
                // element to the end of sequence. 
                for(int i = size - 1; i >= 0; i--)
                {
                    if(i == 0)
                    {
                        sequence.at(i) = last;
                    }
                    else
                    {
                        sequence.at(i) = sequence.at(i - 1);
                    }
                }
            }
        }

        // Performs the left rotation algorithm if true.
        else if(direction == 'L')
        {
            for(int j = 0; j < rotate_val; j++)
            {

                int first = sequence.front();

                // Works beginning to end of sequence and brings the last 
                // element to the beginning of sequence. 
                for(int i = 0; i < size; i++)
                {
                    if((i + 1) == size)
                    {
                        sequence.at(i) = first;
                    }
                    else
                    {
                        sequence.at(i) = sequence.at(i + 1);
                    }
                }
            }
        } 

        // Prints the rotated sequence.
        for(int i = 0; i < size; i++)
        {
            if(i == (size - 1))
            {
                cout << sequence.at(i);
            }
            else
            {
                cout << sequence.at(i) << " ";
            }
        }

        cout << endl;

        // Clears the sequence for the next iteration.
        sequence.clear();

    } 

    return 0;
}
