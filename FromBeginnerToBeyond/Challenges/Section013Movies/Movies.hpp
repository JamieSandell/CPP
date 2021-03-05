#ifndef MOVIES_HPP
#define MOVIES_HPP

#include <iostream>
#include <vector>
#include "Movie.hpp"

using std::vector;

class Movies
{
private:
    vector<Movie> movies;
    
    bool movie_exists(std::string name) const;
public:
    Movies();
    ~Movies();
    
    bool increment_watched(std::string name);
    bool add_movie(std::string name, std::string rating, int watched);
    void display() const;

};

#endif // MOVIES_HPP
