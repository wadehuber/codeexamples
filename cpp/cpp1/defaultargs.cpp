// Default argument example
#include<iostream>
using namespace std;

// Print a list of numbers (start to end by step).  
void iterate(int start, int end, int step=1, int columns=5)
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
    // Call iterate with 4 parameters (columns=8)
    cout << endl;
    cout << "iterate(1,40,1,8)" << endl;
    iterate(1,40,1,8);

    // Call iterate with 3 parameters (use default column value)
    cout << endl;
    cout << "iterate(1,200,10)" << endl;
    iterate(1,200,10);
    
    // Call iterate with 2 parameters (use the default step & column values)
    cout << endl;
    cout << "iterate(1,50)" << endl;
    iterate(1,50);

    return 0;
}

