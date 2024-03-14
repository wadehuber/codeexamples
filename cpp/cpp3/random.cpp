#include<iostream>
#include<random>

int main() {    

    std::random_device rd;

    std::uniform_int_distribution<int> dist(1,10);  // range 1-10, inclusive
    for (int ii=0;ii<20;ii++) {
        std::cout << dist(rd) << " ";
    }
        std::cout << std::endl;

    return 0;

}
