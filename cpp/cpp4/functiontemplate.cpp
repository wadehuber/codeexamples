#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void printVector(vector<T> vec) {
    for(auto const & ii : vec) {
        cout << ii << " ";
    }
}

template<typename C, typename T>
T sumElements(C container, T n) {
    for(auto const & ii : container) {
        n += ii;
    }
    return n;
}


int main() {
    vector<int> vInt = {1, 2, 3, 4, 5};
    vector<double> vDub = {1.0, 2.3, 4.5, 6.7, 8.123, 9.9999};

    cout << "int vector: ";
    printVector(vInt);
    cout << endl;

    cout << "double vector: ";
    printVector(vDub);
    cout << endl;

    cout << endl;
    cout << "sumelements:" << endl;
    cout << "  int vector: " << sumElements(vInt, 0) << endl;;
    cout << "  double vector: " << sumElements(vDub, 0.0) << endl;;

    cout << endl;

    return 0;
}
