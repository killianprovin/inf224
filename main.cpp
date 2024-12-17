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

    Multimedia* photo1 = new Photo("photo1", "./media/photo1.png");
    Multimedia* photo2 = new Photo("photo2", "./media/photo2.png");
    Multimedia* photo3 = new Photo("photo3", "./media/photo3.png");
    Multimedia* video1 = new Video("video1", "./media/video1.mov");
    Multimedia* video2 = new Video("video2", "./media/video2.mov");

    Multimedia* media[5] = {photo1, video1, photo2, photo3, video2};

    for (int i = 0; i < 5; i++) {
        media[i]->display(cout);
    }

    return 0;
}  