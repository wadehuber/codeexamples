#include <iostream>
#include<string>
#include<map>

using namespace std;

class StudentID {
    private:
        int id;
        int year;
    public:
        explicit StudentID(int i, int y=2022) : id(i), year(y) { }

        bool operator<(const StudentID& b) const {
            if (this->id == b.id) {
                return this->year < b.year;
            }
            else {
                return this->id < b.id;
            }
        }

        friend ostream& operator<<(ostream& strm, const StudentID& m) {
            strm << "  ID : " << m.id << " " << m.year;
            return strm;
        }
};

int main() {

    map<StudentID, string> studentIDs;

    studentIDs.insert(pair<StudentID, string>(StudentID(1001134,2019), "Doyle Myers"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1075389,2019), "Maureen Reyes"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1162458,2022), "Terence Peters"));
    studentIDs.insert(pair<StudentID, string>(StudentID(1779365,2020), "Archie Bryant"));
    studentIDs.insert(pair<StudentID, string>(StudentID(2493890,2021), "Margie Bell"));
    studentIDs.insert(pair<StudentID, string>(StudentID(2788773,2022), "Robin Newman"));
    studentIDs.insert(pair<StudentID, string>(StudentID(3009755,2021), "Kristy Sharp"));

    // Print the map
    cout << "Student IDs:" << endl;
    for (auto const &pair : studentIDs) {
        cout << "  " << pair.first << " " << pair.second << endl;
    }

    cout << endl << "find() testing:" << endl;
    StudentID idToSearch(2788773);
    if (studentIDs.find(idToSearch) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << idToSearch << endl;
    }
    else {
        cout << "  StudentID: " << idToSearch << " belongs to " 
                << studentIDs.at(idToSearch) << endl;
    }

    StudentID idToSearch2(1111111);
    if (studentIDs.find(idToSearch2) == studentIDs.end()) {
        cout << "  Unable to find record for student ID " << idToSearch2 << endl;
    }
    else {
        cout << "  StudentID: " << idToSearch2 << " belongs to " 
                << studentIDs.at(idToSearch2) << endl;
    }

    return 0;
}
