#ifndef GROUPE_HPP
#define GROUPE_HPP

#include <list>
#include <string>
#include <iostream>
#include "Multimedia.h"

class Groupe : public std::list<Multimedia*> {
private:
    std::string groupName;

public:
    Groupe(const std::string& name) : groupName(name) {}

    std::string getName() const {
        return groupName;
    }

    void display(std::ostream& os) const {
        os << "Groupe : " << groupName << std::endl;
        for (const Multimedia* media : *this) {
            os << "--------------------------------" << std::endl;
            if (media) {
                media->display(os);
            }
        }
    }
};

#endif
