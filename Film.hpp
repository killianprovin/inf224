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
        chapterCount = count;
        if (count > 0) {
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
};

#endif
