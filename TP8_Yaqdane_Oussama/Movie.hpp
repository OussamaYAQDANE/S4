#pragma once

#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;

public:
    Movie(std::string, std::string, int);

    std::string get_name();

    std::string get_rating();

    int get_watched();

    void set_name(std::string n);

    void set_rating(std::string r);

    void set_watched(int w);

    void display();

    void increment_watched();
};