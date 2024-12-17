#include "Photo.hpp"
#include "Video.hpp"
#include "Film.hpp"
#include "Groupe.hpp"

int main() {
    Photo* photo1 = new Photo("Photo1", "./media/photo1.png", 48, 2);
    Photo* photo2 = new Photo("Photo2", "./media/photo2.png", 40, 10);
    Video* video1 = new Video("Video1", "./media/video1.mov", 120);
    int durations[] = {10, 20, 30};
    Film* film1 = new Film("Film1", "./media/film1.mov", 60, durations, 3);

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

    delete photo1;
    delete photo2;
    delete video1;
    delete film1;

    return 0;
}
