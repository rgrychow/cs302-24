// Challenge 01: Rotating Arrays; null solution
// Requirements for information up here?
// Does the input have to be exactly what is in the example?
// or is it different?
// Is the program suppose to quit after one input?

// Does it have to be read from the input file and written to the output file?

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    string inputFile = argv[1];
    ifstream file;

    // ofstream outputFile("outputTEST.txt");

    file.open(inputFile);
    

    if(argc != 2)
    {
        cerr << ":error:" << endl;
        return 0;
    }

    //int input;
    int size;
    int rotate_val;
    char direction;

    int counter = 0;
    int number;
    string line;

    vector<int> sequence;

    while(file >> size >> rotate_val >> direction)
    {
        // cout << size << " " << rotate_val << " " << direction << " " << endl;

        counter++;

        for(int i = 0; i < size; i++)
        {
            file >> number;
            sequence.push_back(number);
            // cout << number << " ";
        }

        //cout << direction << endl;

        if((direction != 'R') && (direction != 'L'))
        {
            cerr << "Invalid direction" << endl;
            return 0;
        }

        // printf("[ITERATION #%d] Size: %d\nRotate: %d\nDirection: %c\n\n", counter, size, rotate_val, direction);


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
        } 

        for(int i = 0; i < size; i++)
        {
            cout << sequence.at(i) << " ";
        }

        cout << endl;

        sequence.clear();

        //cout << "END OF ITERATION " << counter << endl;
    } 

    return 0;
}

