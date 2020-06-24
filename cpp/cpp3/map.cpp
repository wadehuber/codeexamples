#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    map<string, int> grades;
    
    // Add pairs to the map
    grades.insert(pair<string, int>("Bruce", 84)); 
    grades.insert(pair<string, int>("Rachel", 98));
    grades.insert(pair<string, int>("Liam", 99));
    grades.insert(pair<string, int>("Jackson", 90));
    grades.insert(pair<string, int>("Anna", 92));

    // Print the pairs in the map
    cout << "Grades:" << endl;
    for (map<string,int>::iterator itr=grades.begin(); itr!=grades.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    // Delete Jackson's grade
    int gradeCount = grades.erase("Jackson");
    cout << endl << "Removed " << gradeCount << " grades" << endl;

    // Print the remaining grades
    cout << endl << "Remaining grades:" << endl;
    for (map<string,int>::iterator itr=grades.begin(); itr!=grades.end(); itr++) {
        cout << "  " << itr->first << " " << itr->second << endl;
    }

    // Search the map
    cout << endl << "Searching for grades:" << endl;
    string searchName = "Rachel";
    if (grades.find(searchName) == grades.end()) {
        cout << "  Unable to find grade for " << searchName << endl;
    }
    else {
        cout << "  " << searchName << "'s grade is " << grades.at(searchName) << endl;
    }

    searchName = "Jackson";
    if (grades.find(searchName) == grades.end()) {
        cout << "  Unable to find grade for " << searchName << endl;
    }
    else {
        cout << "  " << searchName << "'s grade is " << grades.at(searchName) << endl;
    }

    // Update a map entry
    cout << endl << "Update Bruce's grade: " << endl;
    grades.at("Bruce") += 5;
    cout << "Bruce's updated grade is " << grades.at("Bruce") << endl;

    return 0;
}
