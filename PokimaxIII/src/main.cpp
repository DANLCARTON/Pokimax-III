/*

 - P R O J E T   :   P O K I M A X - 
 - R E A L I S E   P A R   :   M A X I M E   M A T H E V E T   E T   E R I C   T H I B E R G E -
 - A V E C   L ' A I D E   D E   :   J U L E S   F O U C H Y -
 - D E R N I E R E   V E R S I O N   :   2 4 / 0 1 / 2 0 2 2   1 9 : 3 2 -

*/

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
            intro(); // on la regarde
            mapStart(); // puis on lance le jeu
            KILLMAIN = true; // si on quite le jeu on sort du while pour bien fermer le jeu
        } else if (passIntro == 'N' || passIntro == 'n') { // si non
            mapStart(); // on lance directement le ju
            KILLMAIN = true; // si on quite le jeu on sort du while pour bien fermer le jeu
        } else { // si on donne une réponse invalide
            std::cout << "Regarder l'introduction ? (Y/N) : ";
            std::cin >> passIntro; // on redemande
        }
    }
}