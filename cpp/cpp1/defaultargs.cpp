// Default argument example
#include<iostream>
using namespace std;

// Print a list of numbers (start to end by step).  The default number
//   of columns is 5 which will be used if no number of columns is
//   specified.
void iterate(int start, int end, int step, int columns = 5)
{
    int count = 1;  // to keep track of # of columns

    for (int ii=start; ii <= end; ii += step)
    {
        cout << ii << "\t";
        if ( (count % columns) == 0) {
            cout << endl;
        }
        count ++;
    }
    cout << endl;
}

int main ()
{
    // Call iterate with 3 parameters (use default columns)
    cout << "iterate(0,40,1)" << endl;
    iterate(0,40,1);
    // Call iterate with 4 parameters (columns=8)
    cout << endl;
    cout << "iterate(0,40,1,8)" << endl;
    iterate(0,40,1,8);

    return 0;
}

