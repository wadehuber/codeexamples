#include<iostream>
#include<thread>
#include<mutex>

// compile with:
//   g++ threads.cpp --std=c++11 -pthread
//   g++ --std=c14 -pedantic -Wall -pthread threads.cpp

using namespace std;

mutex writeMutex;

// This funtion counts to 10 with a small random delay between counts
//   The tabs argument lets us differentiate between different
//   threads visually.  
void count_to_ten(int tabs) {
    int delay;

    for(int jj=0;jj<10;jj++) {
	delay = ((tabs % 4) * 100) + (rand() % 1000);  
	this_thread::sleep_for(chrono::milliseconds(delay));

	// The next line locks the output stream so the threads
	//   write over each other.  
	unique_lock<mutex> lock(writeMutex);
	for(int ii=0;ii<tabs;ii++) {
	    cout << "\t";
	}

	cout << jj << endl;
    }
}

int main() {
    constexpr int numThreads = 6;
    std::thread t[numThreads];

    srand(time(NULL));

    // count_to_ten(3);
    // Create the threads
    for(int ii=0;ii<numThreads;ii++) {
	t[ii] = thread(count_to_ten, ii);
    }

    // Wait for each thread to complete
    for(int ii=0;ii<numThreads;ii++) { 
        t[ii].join();
    }

    cout << "FINISHED" << endl;

    return 0;
}
