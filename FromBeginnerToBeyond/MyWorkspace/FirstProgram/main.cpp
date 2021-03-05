#include <iostream>

int main() {
    int favouriteNumber;
    
    std::cout << "What's your favourite number between 1 and 100? : " << std::endl;
    std::cin >> favouriteNumber;
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really!! " << favouriteNumber << " is my favourite number!" << std::endl;

    return 0;
}