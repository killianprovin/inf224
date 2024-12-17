#include "Gestionnaire.hpp"

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
    gestionnaire.displayGroup("Groupe1");
    gestionnaire.displayMultimedia("Video1");

    // Suppression d'un objet multimedia
    gestionnaire.removeMultimedia("Video2");

    // Vérification après suppression
    std::cout << "\nAprès suppression de Video2 :" << std::endl;
    gestionnaire.displayGroup("Groupe1");

    // Suppression d'un groupe
    gestionnaire.removeGroup("Groupe1");

    // Vérification après suppression du groupe
    std::cout << "\nAprès suppression de Groupe1 :" << std::endl;
    gestionnaire.displayGroup("Groupe1");

    return 0;
}
