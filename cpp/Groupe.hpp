#ifndef GROUPE_HPP
#define GROUPE_HPP

#include <list>
#include <string>
#include <iostream>
#include <memory>
#include "Multimedia.h"

class Groupe : public std::list<std::shared_ptr<Multimedia> > {
private:
    std::string groupName;

public:
    Groupe(const std::string& name) : groupName(name) {}

    std::string getName() const {
        return groupName;
    }

    void display(std::ostream& os) const {
        os << "--------------------------------" << std::endl;
        os << "Groupe : " << groupName << std::endl;
        for (const auto& media : *this) {
            os << "----------------" << std::endl;
            if (media) {
                media->display(os);
            }
        }
    }
};

#endif
