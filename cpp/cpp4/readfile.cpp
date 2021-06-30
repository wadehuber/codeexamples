#include<iostream>
#include<fstream>
#include<sstream>

// Read a file of integers and compute the sum

using namespace std;

int main(int argc, char * argv[]) {
    ifstream numberFile; 
    string buffer;
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
        cerr << "Unable to open file " << argv[1] << endl;
        exit(2);
    }

    // Read the file line by line 
    while (getline(numberFile, buffer)) {
        auto lineStream = istringstream(buffer);

        // Get each number from lineStream
        while(lineStream >> number) {
            sum += number;
        }
    }

    cout << "Total = " << sum << endl;
    numberFile.close();

    return 0;
}
