#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "tcpserver.h"
#include "Gestionnaire.hpp"

#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"
#include "Groupe.hpp"


const int PORT = 3331;

//Liste des commandes possibles
enum command {
    PLAY,
    SEARCHMULTIMEDIA,
    SEARCHGROUP,
    GETALLMULTIMEDIA,
    GETALLGROUP,
    NONE
};

command getCommand(std::string const& command) {
    if (command == "play") {
        return PLAY;
    } else if (command == "searchmultimedia") {
        return SEARCHMULTIMEDIA;
    } else if (command == "searchgroup") {
        return SEARCHGROUP;
    } else if (command == "getallmultimedia") {
        return GETALLMULTIMEDIA;
    } else if (command == "getallgroup") {
        return GETALLGROUP;
    }
    return NONE;
}

int main(int argc, char* argv[])
{
    Gestionnaire gestionnaire;

    // Création d'objets et groupes
    gestionnaire.createPhoto("Photo1", "./media/photo1.png", 100, 100);
    gestionnaire.createVideo("Video1", "./media/video1.mp4", 120);
    auto group1 = gestionnaire.createGroup("Groupe1");
    auto group2 = gestionnaire.createGroup("Groupe2");

    // Ajout des objets dans le groupe
    group1->push_back(gestionnaire.createPhoto("Photo2", "./media/photo2.png", 400, 300));
    group1->push_back(gestionnaire.createVideo("Video2", "./media/video2.mp4", 150));

    group2->push_back(gestionnaire.createPhoto("Photo3", "./media/photo3.png", 1920, 1080));

    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        std::istringstream iss(request);
        std::string command, name;
        iss >> command >> name; 

        std::cout << "request: " << request << std::endl;

        std::ostringstream oss;
        switch (getCommand(command)) {
            case PLAY:
                gestionnaire.playMultimedia(name, oss);
                response = oss.str();
                break;
            case SEARCHMULTIMEDIA:
                gestionnaire.displayMultimedia(name, oss);
                response = oss.str();
                break;
            case SEARCHGROUP:
                gestionnaire.displayGroup(name, oss);
                response = oss.str();
                break;
            case GETALLMULTIMEDIA:
                gestionnaire.getAllMultimedia(oss);
                response = oss.str();
                break;
            case GETALLGROUP:
                gestionnaire.getAllGroup(oss);
                response = oss.str();
                break;
            case NONE:
                response = "Command not found";
                break;
        }

        std::replace(response.begin(), response.end(), '\n', ';');

        return true;
    });


    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}