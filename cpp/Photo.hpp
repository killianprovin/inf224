#ifndef PHOTO_HPP
#define PHOTO_HPP

#include "Multimedia.h"
#include <iostream>
#include <string>

class Photo : public Multimedia {
private:
    int latitude;
    int longitude;

public:
    Photo(const std::string name = "", const std::string filename = "", int latitude = 0, int longitude = 0)
        : Multimedia(name, filename), latitude(latitude), longitude(longitude) {}

    std::string classname() const override {
        return "Photo";
    }

    int getLatitude() const {
        return latitude;
    }

    int getLongitude() const {
        return longitude;
    }

    void setLatitude(int latitude) {
        this->latitude = latitude;
    }

    void setLongitude(int longitude) {
        this->longitude = longitude;
    }

    void display(std::ostream& os) const override {
        Multimedia::display(os);
        os << "Latitude de la photo : " << latitude << std::endl;
        os << "Longitude de la photo : " << longitude << std::endl;
    }

    void write(std::ostream& os) const override {
        os << "Photo\n";
        Multimedia::write(os);
        os << latitude << "\n";
        os << longitude << "\n";
    }

    void read(std::istream& is) override {
        std::string type;
        if (!std::getline(is, type)) {
            throw std::runtime_error("Impossible de lire le type.");
        }
        if (type != "Photo") {
            throw std::invalid_argument("Type mismatch");
        }
        Multimedia::read(is);
        std::string line;
        if (!std::getline(is, line)) {
            throw std::runtime_error("Impossible de lire latitude.");
        }
        latitude = std::stoi(line);

        if (!std::getline(is, line)) {
            throw std::runtime_error("Impossible de lire longitude.");
        }
        longitude = std::stoi(line);
    }

    void play() const override {
        std::string command = "xdg-open " + getFilename() + " &";
        system(command.data());
    }
};

#endif
