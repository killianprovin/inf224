#ifndef FILM_HPP
#define FILM_HPP

#include "Video.hpp"
#include <iostream>
#include <string>

class Film : public Video {
private:
    int* chapterDurations;
    int chapterCount;

    void copyChapterDurations(const int* durations, int count) {
        if (count < 0) {
            throw std::invalid_argument("La taille du tableau de chapitres ne peut pas être négative.");
        }
        chapterCount = count;
        if (count > 0) {
            if (durations == nullptr) {
                throw std::invalid_argument("Le tableau de chapitres est nul alors que la taille est positive.");
            }
            chapterDurations = new int[count];
            for (int i = 0; i < count; ++i) {
                chapterDurations[i] = durations[i];
            }
        } else {
            chapterDurations = nullptr;
        }
    }

public:
    Film(const std::string& name = "", const std::string& filename = "", int duration = 0, 
         const int* durations = nullptr, int count = 0)
        : Video(name, filename, duration), chapterDurations(nullptr), chapterCount(0) {
        copyChapterDurations(durations, count);
    }

    std::string classname() const override {
        return "Film";
    }

    ~Film() {
        delete[] chapterDurations;
    }

    Film(const Film& other) : Video(other) {
        copyChapterDurations(other.chapterDurations, other.chapterCount);
    }

    Film& operator=(const Film& other) {
        if (this != &other) {
            Video::operator=(other);
            delete[] chapterDurations;
            copyChapterDurations(other.chapterDurations, other.chapterCount);
        }
        return *this;
    }

    void setChapterDurations(const int* durations, int count) {
        delete[] chapterDurations; 
        copyChapterDurations(durations, count);
    }

    void display(std::ostream& os) const override {
        Video::display(os);
        os << "Nombre de chapitres : " << chapterCount << std::endl;
        if (chapterDurations) {
            os << "Durées des chapitres : ";
            for (int i = 0; i < chapterCount; ++i) {
                os << chapterDurations[i] << " ";
            }
            os << "secondes" << std::endl;
        }
    }

    void write(std::ostream& os) const override {
        os << "Film\n";
        Video::write(os);
        os << chapterCount << "\n";
        for (int i = 0; i < chapterCount; i++) {
            os << chapterDurations[i] << "\n";
        }
    }

    void read(std::istream& is) override {
        std::string type;
        if (!std::getline(is, type)) {
            throw std::runtime_error("Impossible de lire le type.");
        }
        if (type != "Film") {
            throw std::invalid_argument("Type mismatch");
        }
        Video::read(is);
        std::string line;
        if (!std::getline(is, line)) {
            throw std::runtime_error("Impossible de lire chapterCount.");
        }
        chapterCount = std::stoi(line);

        delete[] chapterDurations;
        chapterDurations = nullptr;

        if (chapterCount > 0) {
            chapterDurations = new int[chapterCount];
            for (int i = 0; i < chapterCount; i++) {
                if (!std::getline(is, line)) {
                    throw std::runtime_error("Impossible de lire la durée du chapitre " + std::to_string(i));
                }
                chapterDurations[i] = std::stoi(line);
            }
        }
    }
};

#endif
