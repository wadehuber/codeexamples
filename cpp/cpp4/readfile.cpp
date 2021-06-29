#include<iostream>
#include<fstream>
#include<sstream>

// Read a file of integers and compute the sum

using namespace std;

int main(int argc, char * argv[]) {
 
    string buffer;
    ifstream numberFile;
    int number;
    int sum = 0;

    // Check if a filename is passed
    if (argc < 2) {
         // cerr is like cout but prints to the error stream
        cerr << "Missing filename" << endl;
        exit(1);
    }

    // Open the file
    numberFile.open(argv[1]);
    if (!numberFile) {
        cerr << "Unable to open file: " << argv[1] << endl;
        exit(1);
    }

    // Read the file line by line
    while ( getline(numberFile, buffer)) {
        auto lineStream = istringstream(buffer);

        while(lineStream >> number) {
            sum += number;
        }
    }

    cout << "Total = " << sum << endl;

    numberFile.close();

    return 0;
}
