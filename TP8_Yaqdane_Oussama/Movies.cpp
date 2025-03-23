#include "Movies.hpp"

void Movies::display(){
    for (Movie& movie: movies){
        movie.display();
    }
}

bool Movies::add_movie(std::string n, std::string r, int w){
    for (Movie& movie: movies){
        if (movie.get_name() == n){
            return false;
        }
    }

    movies.push_back(Movie(n, r, w));
    return true;
}

bool Movies::increment_watched(std::string n){
    for (Movie& movie: movies){
        if (movie.get_name() == n){
            movie.increment_watched();
            return true;
        }
    }

    return false;
}
