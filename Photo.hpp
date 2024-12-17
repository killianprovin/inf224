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

    void play() const override {
        std::string command = "open " + getFilename() + " &";
        system(command.data());
    }
};

#endif
