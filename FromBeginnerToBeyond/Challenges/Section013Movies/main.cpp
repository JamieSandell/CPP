#include <iostream>
#include "Movies.hpp"

using namespace std;

int main() {
    Movies movies {};
    movies.add_movie("Back to the Future", "12", 5);
    movies.add_movie("Back to the Future II", "12", 5);
    movies.add_movie("Back to the Future", "12", 5);
    movies.increment_watched("Back to the Future");
    movies.display();
    
    return 0;
}