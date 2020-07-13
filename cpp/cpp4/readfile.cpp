#include<iostream>
#include<fstream>
#include<sstream>

// This program reads integers from a file and computes the sum
using namespace std;

int main(int argc, char * argv[]) {
    string buffer;
    ifstream numberFile;
    string number;
    int sum=0;
 
    // CHeck if a filename is passed
    if (argc < 2) {
         // cerr is like cout but prints to the error stream
        cerr << "Missing filename to read\n" << argv[1] << endl;
        exit(1);
    }

    // Open the file
    numberFile.open(argv[1]);
    if (!numberFile) {
         // cerr is like cout but prints to the error stream
        cerr << "Unable to open file " << argv[1] << endl;
        exit(1);
    }

    // Read the file line by line
    while ( getline(numberFile, buffer) ) {
        // An istringstream lets us stream integers from a string
        auto lineStream = istringstream{buffer};

        // Get each number from the lineStream
        while(lineStream >> number) {
            sum += stoi(number);
        }

    }

    cout << "Total = " << sum << endl;
    numberFile.close();

    return 0;
}
