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
        if (multimediaMap.find(name) != multimediaMap.end()) {
            std::cerr << "Erreur: un objet multimedia avec le nom '" << name << "' existe déjà." << std::endl;
            return nullptr;
        }
        auto photo = std::make_shared<Photo>(name, filename, lat, lon);
        multimediaMap[name] = photo;
        return photo;
    }

    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& filename, int duration) {
        if (multimediaMap.find(name) != multimediaMap.end()) {
            std::cerr << "Erreur: un objet multimedia avec le nom '" << name << "' existe déjà." << std::endl;
            return nullptr;
        }
        auto video = std::make_shared<Video>(name, filename, duration);
        multimediaMap[name] = video;
        return video;
    }

    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& filename, int duration, const int* chapters, int count) {
        if (multimediaMap.find(name) != multimediaMap.end()) {
            std::cerr << "Erreur: un objet multimedia avec le nom '" << name << "' existe déjà." << std::endl;
            return nullptr;
        }
        auto film = std::make_shared<Film>(name, filename, duration, chapters, count);
        multimediaMap[name] = film;
        return film;
    }

    std::shared_ptr<Groupe> createGroup(const std::string& name) {
        if (groupMap.find(name) != groupMap.end()) {
            std::cerr << "Erreur: un groupe avec le nom '" << name << "' existe déjà." << std::endl;
            return nullptr;
        }
        auto group = std::make_shared<Groupe>(name);
        groupMap[name] = group;
        return group;
    }

    void getAllMultimedia(std::ostream& os) const {
        for (const auto& multimediaPair : multimediaMap) {
            multimediaPair.second->getName(os);
        }
    }

    void getAllGroup(std::ostream& os) const {
        for (const auto& groupPair : groupMap) {
            groupPair.second->getName(os);
        }
    }

    void displayMultimedia(const std::string& name, std::ostream& os) const {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            it->second->display(os);
        } else {
            os << "Erreur: objet multimedia '" << name << "' non trouvé." << std::endl;
        }
    }

    void displayGroup(const std::string& name, std::ostream& os) const {
        auto it = groupMap.find(name);
        if (it != groupMap.end()) {
            it->second->display(os);
        } else {
            os << "Erreur: groupe '" << name << "' non trouvé." << std::endl;
        }
    }

    void playMultimedia(const std::string& name) const {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            it->second->play();
        } else {
            std::cerr << "Erreur: objet multimedia '" << name << "' non trouvé." << std::endl;
        }
    }

    void removeMultimedia(const std::string& name) {
        auto it = multimediaMap.find(name);
        if (it != multimediaMap.end()) {
            for (auto& groupPair : groupMap) {
                groupPair.second->remove(it->second);
            }
            multimediaMap.erase(it);
        } else {
            std::cerr << "Erreur: objet multimedia '" << name << "' n'existe pas." << std::endl;
        }
    }

    void removeGroup(const std::string& name) {
        auto it = groupMap.find(name);
        if (it != groupMap.end()) {
            groupMap.erase(it);
        } else {
            std::cerr << "Erreur: groupe '" << name << "' n'existe pas." << std::endl;
        }
    }
};

#endif
