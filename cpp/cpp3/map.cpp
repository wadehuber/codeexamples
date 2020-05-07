#include<iostream>
#include<iterator>
#include<string>
#include<map>

using namespace std;

int main() {
  map<string, int> grades;
  map<string,int>:: iterator itr;
  
  grades.insert(pair<string, int>("Bruce", 84));
  grades.insert(pair<string, int>("Rachel", 98));
  grades.insert(pair<string, int>("Liam", 99));
  grades.insert(pair<string, int>("Jackson", 90));
  grades.insert(pair<string, int>("Anna", 92));

  for(itr=grades.begin(); itr != grades.end();  ++itr) {
     cout << itr->first << " " << itr->second << endl;
  }

  // Delete Jackson's grade
  int gradeCount = grades.erase("Jackson");
  cout << endl << "Removed " << gradeCount << " Grades" << endl;
  cout << endl << "Remaining grades: " << endl;
  for(itr=grades.begin(); itr != grades.end();  ++itr) {
     cout << itr->first << " " << itr->second << endl;
  }

  cout << endl << "Finding grades: " << endl;
  string searchName = "Rachel";
  if (grades.find(searchName) == grades.end()) {
    cout << "Unable to find grade for " << searchName << endl;
  } 
  else {
    cout << searchName << "'s grade = " << grades.at(searchName) << endl; 
  }
  searchName = "Jackson";
  if (grades.find(searchName) == grades.end()) {
    cout << "Unable to find grade for " << searchName << endl;
  } 
  else {
    cout << searchName << "'s grade = " << grades.at(searchName) << endl; 
  }

  // Give Bruce 5 bonus points
  cout << endl << "Updating Bruce's grade: " << endl;
  grades.at("Bruce") += 5;
  cout << "Bruce's updated grade = " << grades.at("Bruce") << endl;

  return 0;
}
