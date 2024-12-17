#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"
#include "Groupe.hpp"
#include <memory> 

int main() {
    auto photo1 = std::make_shared<Photo>("Photo1", "./media/photo1.png", 48, 2);
    auto photo2 = std::make_shared<Photo>("Photo2", "./media/photo2.png", 40, 10);
    auto video1 = std::make_shared<Video>("Video1", "./media/video1.mov", 120);
    auto film1 = std::make_shared<Film>("Film1", "./media/film1.mov", 60, new int[3]{10, 20, 30}, 3);

    Groupe groupePhotos("Groupe de Photos");
    Groupe groupeVideos("Groupe de Videos");
    Groupe groupeMixte("Groupe Mixte");

    groupePhotos.push_back(photo1);
    groupePhotos.push_back(photo2);

    groupeVideos.push_back(video1);

    groupeMixte.push_back(photo1);
    groupeMixte.push_back(video1);
    groupeMixte.push_back(film1);

    std::cout << "===== Affichage des groupes =====" << std::endl;

    groupePhotos.display(std::cout);
    std::cout << std::endl;

    groupeVideos.display(std::cout);
    std::cout << std::endl;

    groupeMixte.display(std::cout);

    std::cout << "\nSuppression des objets du groupe mixte..." << std::endl;
    groupeMixte.clear();

    std::cout << "Affichage après suppression du groupe mixte :" << std::endl;
    groupePhotos.display(std::cout);
    groupeVideos.display(std::cout);

    return 0;
}
