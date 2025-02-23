#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "Multimedia.h"
#include <iostream>
#include <string>

class Video : public Multimedia {
private:
    int duration;

public:
    Video(const std::string name = "", const std::string filename = "", int duration = 0)
        : Multimedia(name, filename), duration(duration) {}

    std::string classname() const override {
        return "Video";
    }

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

    void write(std::ostream& os) const override {
        os << "Video\n";
        Multimedia::write(os);
        os << duration << "\n";
    }

    void read(std::istream& is) override {
        std::string type;
        if (!std::getline(is, type)) {
            throw std::runtime_error("Impossible de lire le type.");
        }
        if (type != "Video") {
            throw std::invalid_argument("Type mismatch");
        }
        Multimedia::read(is);

        std::string line;
        if (!std::getline(is, line)) {
            throw std::runtime_error("Impossible de lire duration.");
        }
        duration = std::stoi(line);
    }

    void play() const override {
        std::string command = "mpv " + getFilename() + " &";
        system(command.data());
    }
};

#endif
