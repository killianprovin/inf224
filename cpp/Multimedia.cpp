#include "Multimedia.h"
#include <iostream>

Multimedia::Multimedia(std::string name, std::string filename) {
    if (!isValid(name, false)) {
        throw std::invalid_argument("Nom invalide : " + name);
    }
    if (!isValid(filename, true)) {
        throw std::invalid_argument("Nom de fichier invalide : " + filename);
    }
    this->name = name;
    this->filename = filename;
}

std::string Multimedia::classname() const {
    return 0;
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

void Multimedia::getName(std::ostream& os) const {
    os << this->name << std::endl;
}

std::string Multimedia::getFilename() const {
    return this->filename;
}

void Multimedia::display(std::ostream& os) const {
    os << "Name: " << this->name << std::endl;
    os << "Filename: " << this->filename << std::endl;
}

void Multimedia::write(std::ostream& os) const {
    os << name << "\n";
    os << filename << "\n";
}

void Multimedia::read(std::istream& is) {
    std::getline(is, name);
    std::getline(is, filename);
}

void Multimedia::play() const { }

Multimedia::~Multimedia() {}