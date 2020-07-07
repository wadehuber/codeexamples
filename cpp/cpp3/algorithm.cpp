#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

int main() {    
    std::vector<int> vec = {7, 3, 4, 8, 1, 5, 2, 6, 9};
    std::vector<int> vec2= {1, 1, 0, 1, 0, 0, 1, 0, 0};

    // Print vector using iterator
    std::cout << "vec: ";
    for (auto ii=vec.begin(); ii!= vec.end(); ii++) {
        std::cout << *ii << " ";
    }
    std::cout << std::endl;

    
    // Print vector using range for
    std::cout << "vec2: ";
    for (auto const & ele : vec2) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    // Sort vector - sort is performed in-place
    std::sort(begin(vec), end(vec));
    std::cout << "Sorted vec: ";
    for (auto const & ele : vec) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    // Shuffle vector (in-place)
    auto rand_engine = std::default_random_engine {};
    std::shuffle(begin(vec), end(vec), rand_engine);
    std::cout << "Shuffled vec: ";
    for (auto const & ele : vec) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    // Count
    std::cout << std::endl;
    std::cout << "std::count: " << std::endl;
    int num_zeros = count(begin(vec2), end(vec2), 0);
    int num_ones = count(begin(vec2), end(vec2), 1);
    std::cout << "There are " << num_zeros << " 0's and " << num_ones << " 1's in vec2" << std::endl;


    // Find
    std::cout << std::endl;
    std::cout << "std::find: " << std::endl;
    for (auto & ele : {-1, 2, 7, 12}) {
        if ( std::find(begin(vec), end(vec), ele) != end(vec) ) {
            std::cout << "  Found " << ele << " in vec!" << std::endl;
        }
        else {
            std::cout << "  Did NOT find " << ele << " in vec!" << std::endl;
        }
    }

    // The example belows use the following lambdas:
    //    Positive number: [](int x) {return (x >= 0);} 
    //    Negative number: [](int x) {return (x < 0);} 
    //        Even number: [](int x) {return ((x % 2) == 0);} 
    std::cout << std::endl;
    std::cout << "std::all_of, any_of, & none_of: " << std::endl;
    // Are all the numbers in vec even?
    if (std::all_of(begin(vec), end(vec), [](int x) {return ((x % 2) == 0); })) {
        std::cout << "All numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "Not all numbers in vec are even" << std::endl;
    }

    // Are all the numbers in vec >= 0?
    if (std::all_of(begin(vec), end(vec), [](int x) {return (x >= 0);} )) {
        std::cout << "All numbers in vec are positive" << std::endl;
    }
    else {
        std::cout << "Not all numbers in vec are positive" << std::endl;
    }

    // Are any numbers in vec even?
    if (std::any_of(begin(vec), end(vec), [](int x) {return ((x % 2) == 0); } )) {
        std::cout << "Some numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "No numbers in vec are even" << std::endl;
    }

    // Are none of the numbers in vec even?
    if (std::none_of(begin(vec), end(vec), [](int x) {return ((x % 2) == 0); } )) {
        std::cout << "None of the numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "Some numbers in vec are even" << std::endl;
    }

    return 0;
}
