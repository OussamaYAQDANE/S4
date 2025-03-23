#pragma once

#include <string>
#include <vector>
#include "Movie.hpp"

class Movies{
private:
    std::vector<Movie> movies;

public:
    bool add_movie(std::string, std::string, int);

    bool increment_watched(std::string);

    void display();

};