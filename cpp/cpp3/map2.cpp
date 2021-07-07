#include <iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    map<int, string> studentIDs;
    
    studentIDs.insert(pair<int, string>(1001134, "Doyle Myers"));
    studentIDs.insert(pair<int, string>(1075389, "Maureen Reyes"));
    studentIDs.insert(pair<int, string>(1162458, "Terence Peters"));
    studentIDs.insert(pair<int, string>(1779365, "Archie Bryant"));
    studentIDs.insert(pair<int, string>(2493890, "Margie Bell"));
    studentIDs.insert(pair<int, string>(2788773, "Robin Newman"));
    studentIDs.insert(pair<int, string>(3009755, "Kristy Sharp"));

    // Print the pairs in the map
    cout << "Student ID:" << endl;
    for (map<int,string>::iterator itr=studentIDs.begin(); itr!=studentIDs.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    int gradeCount = studentIDs.erase(2493890);
    cout << endl << "Removed " << gradeCount << " studentIDs" << endl;

    // Print the remaining studentIDs
    cout << endl << "Remaining studentIDs:" << endl;
    for (map<int,string>::iterator itr=studentIDs.begin(); itr!=studentIDs.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    // Search the map
    cout << endl << "Searching for studentIDs:" << endl;
    int searchID = 1234567;
    if (studentIDs.find(searchID) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << searchID << endl;
    }
    else {
        cout << "  Student ID " << searchID << " belongs to " << studentIDs.at(searchID) << endl;
    }

    searchID = 1779365;
    if (studentIDs.find(searchID) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << searchID << endl;
    }
    else {
        cout << "  Student ID " << searchID << " belongs to " << studentIDs.at(searchID) << endl;
    }

    return 0;
}