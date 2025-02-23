#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Gestionnaire.hpp"


#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"
#include "Groupe.hpp"


/*

const int PORT = 3331;

enum command {
    PLAY,
    SEARCHMULTIMEDIA,
    SEARCHGROUP,
    NONE
};

command getCommand(std::string const& command) {
    if (command == "play") {
        return PLAY;
    } else if (command == "searchmultimedia") {
        return SEARCHMULTIMEDIA;
    } else if (command == "searchgroup") {
        return SEARCHGROUP;
    }
    return NONE;
}

int main(int argc, char* argv[])
{
    Gestionnaire gestionnaire;

    // Création d'objets et groupes
    gestionnaire.createPhoto("Photo1", "./media/photo1.png", 48, 2);
    gestionnaire.createVideo("Video1", "./media/video1.mov", 120);
    auto group1 = gestionnaire.createGroup("Groupe1");

    // Ajout des objets dans le groupe
    group1->push_back(gestionnaire.createPhoto("Photo2", "./media/photo2.png", 50, 4));
    group1->push_back(gestionnaire.createVideo("Video2", "./media/video2.mov", 150));

    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        std::istringstream iss(request);
        std::string command, name;
        iss >> command >> name; 

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;


        std::ostringstream oss;
        switch (getCommand(command)) {
            case PLAY:
                //gestionnaire.playMultimedia(name);
                response = "Playing multimedia";
                break;
            case SEARCHMULTIMEDIA:
                gestionnaire.displayMultimedia(name, oss);
                response = oss.str();
                break;
            case SEARCHGROUP:
                gestionnaire.displayGroup(name, oss);
                response = oss.str();
                break;
            case NONE:
                response = "Command not found";
                break;
        }

        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}

*/

int main() {
    Gestionnaire gestionnaire;

    // Création d'objets et groupes
    gestionnaire.createPhoto("Photo1", "./media/photo1.png", 48, 2);
    gestionnaire.createVideo("Video1", "./media/video1.mov", 120);
    auto group1 = gestionnaire.createGroup("Groupe1");

    // Ajout des objets dans le groupe
    group1->push_back(gestionnaire.createPhoto("Photo2", "./media/photo2.png", 50, 4));
    group1->push_back(gestionnaire.createVideo("Video2", "./media/video2.mov", 150));

    // Affichage des groupes et objets
    std::cout << "Avant suppression :" << std::endl;
    gestionnaire.displayGroup("Groupe1", std::cout);
    gestionnaire.displayMultimedia("Video1", std::cout);

    //gestionnaire.playMultimedia("Video1");

    // Suppression d'un objet multimedia
    gestionnaire.removeMultimedia("Video2");

    // Vérification après suppression
    std::cout << "\nAprès suppression de Video2 :" << std::endl;
    gestionnaire.displayGroup("Groupe1", std::cout);

    // Suppression d'un groupe
    gestionnaire.removeGroup("Groupe1");

    // Vérification après suppression du groupe
    std::cout << "\nAprès suppression de Groupe1 :" << std::endl;
    gestionnaire.displayGroup("Groupe1", std::cout);


    //test de write puis de read

    // 1) Création d'une Photo
    Photo original("Photo3", "./media/photo3.png", 60, 3);

    // 2) Écriture dans un flux en mémoire (stringstream)
    std::stringstream ss;
    original.write(ss);

    // 3) Création d'un nouvel objet "vide"
    Photo copie;
    copie.read(ss);

    // 4) Affichage pour vérifier
    std::cout << "=== Original ===" << std::endl;
    original.display(std::cout);

    std::cout << "\n=== Copie ===" << std::endl;
    copie.display(std::cout);

    //test de write puis de read video

    // 1) Création d'une Video
    Video originalV("Video3", "./media/video3.mov", 180);

    // 2) Écriture dans un flux en mémoire (stringstream)
    std::stringstream ssV;
    originalV.write(ssV);

    // 3) Création d'un nouvel objet "vide"
    Video copieV;
    copieV.read(ssV);

    // 4) Affichage pour vérifier
    std::cout << "=== Original ===" << std::endl;
    originalV.display(std::cout);

    std::cout << "\n=== Copie ===" << std::endl;
    copieV.display(std::cout);

    //test de write puis de read film

    // 1) Création d'un Film
    int chapterDurations[] = { 10, 20, 30, 40 };
    Film originalF("Film1", "./media/film1.mov", 120, chapterDurations, 4);

    // 2) Écriture dans un flux en mémoire (stringstream)
    std::stringstream ssF;
    originalF.write(ssF);

    // 3) Création d'un nouvel objet "vide"
    Film copieF;
    copieF.read(ssF);

    // 4) Affichage pour vérifier
    std::cout << "=== Original ===" << std::endl;
    originalF.display(std::cout);

    std::cout << "\n=== Copie ===" << std::endl;
    copieF.display(std::cout);

    return 0;
}