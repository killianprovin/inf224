#include "Multimedia.h"
#include <iostream>

Multimedia::Multimedia(std::string name, std::string filename) {
    this->name = name;
    this->filename = filename;
}

void Multimedia::setName(std::string name) {
    this->name = name;
}

void Multimedia::setFilename(std::string filename) {
    this->filename = filename;
}

std::string Multimedia::getName() const {
    return this->name;
}

std::string Multimedia::getFilename() const {
    return this->filename;
}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << this->name << std::endl;
    os << "Filename: " << this->filename << std::endl;
}

void Multimedia::play() const { }

Multimedia::~Multimedia() {}