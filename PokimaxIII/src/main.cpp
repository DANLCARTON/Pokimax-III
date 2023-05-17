#include <iostream>
#include <string.h> // permet d'utiliser des strings
#include <chrono>
#include <thread>
#include <cstdlib> // permet d'utilser rand()
#include <random>
#include <glimac/pokemon.hpp>
#include <glimac/intro.hpp>
#include <glimac/map.hpp>
#include <glimac/battle.hpp>
#include <glimac/verifStop.hpp>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - F O N C T I O N   M A I N - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main() {
    char passIntro;
    std::cout << "Regarder l'introduction ? (Y/N) : ";
    std::cin >> passIntro; // on demande si on veut regarder l'intro
    bool KILLMAIN = false;
    while (!KILLMAIN) {
        if (passIntro == 'Y' || passIntro == 'y') { // si oui
            glimac::intro(); // on la regarde
            glimac::mapStart(); // puis on lance le jeu
            KILLMAIN = true; // si on quite le jeu on sort du while pour bien fermer le jeu
        } else if (passIntro == 'N' || passIntro == 'n') { // si non
            glimac::mapStart(); // on lance directement le ju
            KILLMAIN = true; // si on quite le jeu on sort du while pour bien fermer le jeu
        } else { // si on donne une réponse invalide
            std::cout << "Regarder l'introduction ? (Y/N) : ";
            std::cin >> passIntro; // on redemande
        }
    }
}