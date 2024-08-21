/* Ryan Grychowski, solution.cpp

Challenge #1 - Reads an input file that contains a sequence size, rotate value, and 
rotation direction followed by a sequence of numbers with size corresponding to the value 
specified. The program will preform the indicated rotation and write the rotated sequences
to an output file. 

*/

// Challenge 01: Rotating Arrays; null solution
// Requirements for information up here?
// Does the input have to be exactly what is in the example?
// or is it different?
// Is the program suppose to quit after one input?

// Does it have to be read from the input file and written to the output file?

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    int input;
    int size;
    int rotate_val;
    char direction;

    vector<int> sequence;
    
    cin >> size >> rotate_val >> direction;

    if((direction != 'R') && (direction != 'L'))
    {
        cerr << "Invalid direction" << endl;
        return 0;
    }

    //printf("Size: %d\nRotate: %d\nDirection: %c\n\n", size, rotate_val, direction);


    for(int i = 0; i < size; i++)
    {
        cin >> input;

        if(input == 0)
        {
            return 0;
        }

        sequence.push_back(input);
    }

    //cout << "Size: " << size << endl;

    if(direction == 'R')
    {
        // printf("Right Rotate\n");

        for(int j = 0; j < rotate_val; j++)
        {
            int last = sequence.back();

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

        for(int i = 0; i < size; i++)
        {
            cout << sequence.at(i) << " ";
        }

        cout << endl;
    }
    else if(direction == 'L')
    {
        //printf("Left Rotate\n");
        for(int j = 0; j < rotate_val; j++)
        {

            int first = sequence.front();

            for(int i = 0; i < size; i++)
            {
                if((i + 1) == size)
                {
                    sequence.at(i) = first;
                    //cout << first << endl;
                }
                else
                {
                    sequence.at(i) = sequence.at(i + 1);
                    //cout << sequence.at(i) << " ";
                }
            }
        }
        for(int i = 0; i < size; i++)
        {
            cout << sequence.at(i) << " ";
        }

        cout << endl;
        
    }

    return 0;
}

