//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"

using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    Film* film = new Film("Film", "./media/video1.mov", 120, new int[3]{10, 20, 30}, 3);

    film->display(std::cout);
    film->setChapterDurations(new int[2]{15, 25}, 2);
    film->setDuration(150);
    film->display(std::cout);
    film->setChapterDurations({}, 0);
    film->setDuration(150);
    film->display(std::cout);

    delete film;

    return 0;
}  