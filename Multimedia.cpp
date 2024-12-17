#include "Multimedia.h"
#include <iostream>

Multimedia::Multimedia(std::string name, std::string filename) {
    this->name = name;
    this->filename = filename;
}

Multimedia::Multimedia() {
    this->name = "";
    this->filename = "";
}

void Multimedia::setName(std::string name) {
    this->name = name;
}

void Multimedia::setFilename(std::string filename) {
    this->filename = filename;
}

std::string Multimedia::getName() {
    return this->name;
}

std::string Multimedia::getFilename() {
    return this->filename;
}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << this->name << std::endl;
    os << "Filename: " << this->filename << std::endl;
}

Multimedia::~Multimedia() {}