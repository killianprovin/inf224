//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"

using namespace std;

int main(int argc, const char* argv[])
{
    std::cout << "Hello brave new world" << std::endl;

    Multimedia media1("Photo Test", "/home/photo/test.jpg");
    Multimedia media2;

    media1.display(cout);
    media2.display(cout);

    media1.setName("Photo Test 2");

    media1.display(cout);

    return 0;
}