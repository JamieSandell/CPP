#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>

class Movie
{
public:
    Movie(std::string _name, std::string _rating, int _watched);
    ~Movie();
    
    void display() const;
    void increment_watched();
    std::string get_name() const;
    
private:
    std::string name;
    std::string rating;
    int watched;
};

#endif // MOVIE_HPP
