#include <iostream>
#include<string>
#include<map>

using namespace std;

class StudentID {
    private:
        int id;
        int year;
    public:
        StudentID(int i, int y=2021) {
            id = i;
            year = y;
        }
        bool operator<(const StudentID& a);  // Lets us use this in a map

        friend ostream& operator<<(ostream& strm, const StudentID& m) {
            strm << "  ID : " << m.id << " " << m.year;
            return strm;
        }
        friend bool operator<(const StudentID& a, const StudentID& b) {
            return a.id < b.id;
        }
};

int main() {
    map<StudentID, string> studentIDs;

    studentIDs.insert(pair<StudentID, string>(StudentID(1001134,2021), "Doyle Myers"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1075389,2021), "Maureen Reyes"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1162458,2021), "Terence Peters"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1779365,2021), "Archie Bryant"));
    studentIDs.insert(pair<StudentID, string>(StudentID(2493890,2021), "Margie Bell"));
    studentIDs.insert(pair<StudentID, string>(StudentID(2788773,2021), "Robin Newman"));
    studentIDs.insert(pair<StudentID, string>(StudentID(3009755,2021), "Kristy Sharp"));

    // Print the pairs in the map
    cout << "Student ID:" << endl;
    for (auto itr=studentIDs.begin(); itr!=studentIDs.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    cout << endl << "Erasing student" << endl;
    int gradeCount = studentIDs.erase(StudentID(1162458));
    cout << endl << "Removed " << gradeCount << " studentIDs" << endl;

    // Print the remaining studentIDs
    cout << endl << "Remaining studentIDs:" << endl;
    for (auto itr=studentIDs.begin(); itr!=studentIDs.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    // Search the map
    cout << endl << "Searching for studentIDs:" << endl;
    StudentID searchID(1234567);
    if (studentIDs.find(searchID) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << searchID << endl;
    }
    else {
        cout << "  Student ID " << searchID << " belongs to " << studentIDs.at(searchID) << endl;
    }

    searchID = 2788773;
    if (studentIDs.find(searchID) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << searchID << endl;
    }
    else {
        cout << "  Student ID " << searchID << " belongs to " << studentIDs.at(searchID) << endl;
    }

    return 0;
}