#ifndef FILM_HPP
#define FILM_HPP

#include "Video.hpp"
#include <iostream>
#include <string>

class Film : public Video {
private:
    int* chapterDurations;
    int chapterCount;

public:
    Film(const std::string& name = "", const std::string& filename = "", int duration = 0, 
         const int* durations = nullptr, int count = 0)
        : Video(name, filename, duration), chapterCount(count) {
        if (durations && count > 0) {
            chapterDurations = new int[count];
            for (int i = 0; i < count; ++i) {
                chapterDurations[i] = durations[i];
            }
        } else {
            chapterDurations = nullptr;
            chapterCount = 0;
        }
    }

    ~Film() {
        delete[] chapterDurations;
    }

    void setChapterDurations(const int* durations, int count) {
        delete[] chapterDurations;
        chapterCount = count;
        if (durations && count > 0) {
            chapterDurations = new int[count];
            for (int i = 0; i < count; ++i) {
                chapterDurations[i] = durations[i];
            }
        } else {
            chapterDurations = nullptr;
            chapterCount = 0;
        }
    }

    const int* getChapterDurations() const {
        return chapterDurations;
    }

    int getChapterCount() const {
        return chapterCount;
    }

    void display(std::ostream& os) const override {
        Video::display(os);
        os << "Nombre de chapitres : " << chapterCount << std::endl;
        if (chapterDurations && chapterCount > 0) {
            os << "Durées des chapitres : ";
            for (int i = 0; i < chapterCount; ++i) {
                os << chapterDurations[i] << " ";
            }
            os << "secondes" << std::endl;
        }
    }
};

#endif