#ifndef GESTIONNAIRE_HPP
#define GESTIONNAIRE_HPP

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"
#include "Groupe.hpp"

class Gestionnaire {
private:
    std::map<std::string, std::shared_ptr<Multimedia>> multimediaMap;
    std::map<std::string, std::shared_ptr<Groupe>> groupMap;

public:
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& filename, int lat, int lon) {
        auto photo = std::make_shared<Photo>(name, filename, lat, lon);
        multimediaMap[name] = photo;
        return photo;
    }

    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& filename, int duration) {
        auto video = std::make_shared<Video>(name, filename, duration);
        multimediaMap[name] = video;
        return video;
    }

    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& filename, int duration, const int* chapters, int count) {
        auto film = std::make_shared<Film>(name, filename, duration, chapters, count);
        multimediaMap[name] = film;
        return film;
    }

    std::shared_ptr<Groupe> createGroup(const std::string& name) {
        auto group = std::make_shared<Groupe>(name);
        groupMap[name] = group;
        return group;
    }

    void displayMultimedia(const std::string& name) const {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            it->second->display(std::cout);
        }
    }

    void displayGroup(const std::string& name) const {
        auto it = groupMap.find(name);
        if (it != groupMap.end()) {
            it->second->display(std::cout);
        }
    }

    void playMultimedia(const std::string& name) const {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            it->second->play();
        }
    }

    void removeMultimedia(const std::string& name) {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            for (auto& groupPair : groupMap) {
                groupPair.second->remove(it->second);
            }
            multimediaMap.erase(it);
        }
    }

    void removeGroup(const std::string& name) {
        auto it = groupMap.find(name);
        if (it != groupMap.end()) {
            groupMap.erase(it);
        }
    }
};

#endif
