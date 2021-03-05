#include "Movie.hpp"

using std::cout;
using std::endl;

Movie::Movie(std::string _name, std::string _rating, int _watched) : name(_name), rating(_rating), watched(_watched)
{
}

Movie::~Movie()
{
}

void Movie::display() const {
    cout << name << " - " << rating << " - " << watched << endl;
}

void Movie::increment_watched() {
    ++watched;
}

std::string Movie::get_name() const {
    return name;
}

