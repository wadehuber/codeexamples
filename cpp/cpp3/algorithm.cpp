#include<iostream>
#include<vector>
#include<algorithm>
#include<random>

int main() {    
    std::vector<int> vec = {7, 3, 4, 8, 1, 5, 2, 6, 9};
    std::vector<int> vec2= {1, 1, 0, 1, 0, 0, 1, 0, 0};

    // Print vector
    std::cout << "Original: " << std::endl;
    for (auto const & ele : vec) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    // Sort vector (note sort takes place in-place)
    std::sort(begin(vec), end(vec));
    std::cout << "Sorted: " << std::endl;
    for (auto const & ele : vec) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    // Shuffle vector (note shuffle takes place in-place)
    auto rand_engine = std::default_random_engine{};
    std::shuffle(begin(vec), end(vec), rand_engine);
    std::cout << "Shuffled: " << std::endl;
    for (auto const & ele : vec) {
        std::cout << ele << " ";
    }

    // Count
    std::cout << std::endl;
    std::cout << "std::count: " << std::endl;
    int num_ones = count (std::begin(vec2), std::end(vec2), 1);
    int num_zeros = count (std::begin(vec2), std::end(vec2), 0);
    std::cout << std::endl;
    std::cout << "There are " << num_zeros << " 0's and " << num_ones << " 1's in vec2" << std::endl;

    // Find
    std::cout << std::endl;
    std::cout << "std::find: " << std::endl;
    for (auto & ele : {-1, 2, 7, 12}) {
        if ( std::find(std::begin(vec), std::end(vec), ele) != std::end(vec) ) {
            std::cout << "Found " << ele << " in vec!" << std::endl;
        }
        else {
            std::cout << "Did not find " << ele << "in vec!" << std::endl;
        }
    }

    // The example belows use the following lambdas:
    //    Positive number: [](int x) {return (x >= 0);} 
    //    Negative number: [](int x) {return (x < 0);} 
    //        Even number: [](int x) {return ((x % 2) == 0);} 
    std::cout << std::endl;
    std::cout << "all_of, any_of, none_of:";
    // Are all numbers even?
    if (std::all_of(begin(vec), end(vec), [](int x) { return ((x % 2) == 0); })) {
        std::cout << "All numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "Not all numbers in vec are even" << std::endl;
    }

    if (std::all_of(begin(vec), end(vec), [](int x) { return (x > 0); })) {
        std::cout << "All numbers in vec are greater than 0" << std::endl;
    }
    else {
        std::cout << "Not all numbers in vec are greater than 0" << std::endl;
    }

    if (std::any_of(begin(vec), end(vec), [](int x) { return ((x % 2) == 0); })) {
        std::cout << "Some numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "No numbers in vec are even" << std::endl;
    }

    if (std::none_of(begin(vec), end(vec), [](int x) { return ((x % 2) == 0); })) {
        std::cout << "No numbers in vec are even" << std::endl;
    }
    else {
        std::cout << "Some numbers in vec are even" << std::endl;
    }
   

    return 0;
}