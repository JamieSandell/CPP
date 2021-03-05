#include "Movies.hpp"

Movies::Movies()
{
}

Movies::~Movies()
{
}

void Movies::display() const {
    if (movies.size() == 0) {
        std::cout << "Movie Collection" << std::endl;
        std::cout << "---------------------" << std::endl;
        for (auto const& movie: movies) {
            movie.display();
        }    
    }
    else {
        std::cout << "Sorry, no movies to display." << std::endl;
    }
}

bool Movies::increment_watched(std::string name) {
    for (Movie &movie: movies) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

bool Movies::movie_exists(std::string name) const{
    for (const Movie &movie: movies) {
        if (movie.get_name() == name) {
            return true;
        }
    }
    return false;
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    if (movie_exists(name) == false) {
        Movie movie{name, rating, watched};
        movies.push_back(movie);
        return true;
    }
    else {
        std::cout << "Movie: " << name << " already exists in the collection." << std::endl;
        return false;
    }
}

