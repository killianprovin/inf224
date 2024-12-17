#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Multimedia.h"
#include <iostream>
#include <string>

class Video : public Multimedia {
private:
    int duration;

public:
    Video(const std::string& name = "", const std::string& filename = "", int duration = 0)
        : Multimedia(name, filename), duration(duration) {}

    int getDuration() const {
        return duration;
    }

    void setDuration(int duration) {
        this->duration = duration;
    }

    void display(std::ostream& os) const override {
        Multimedia::display(os);
        os << "Durée de la vidéo : " << duration << " secondes" << std::endl;
    }
};

#endif
