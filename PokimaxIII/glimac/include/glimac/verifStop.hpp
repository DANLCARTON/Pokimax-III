#ifndef VERIF_STOP
#define VERIF_STOP

#include <iostream>
#include <string>
#include <glimac/map.hpp>
#include <glimac/pokemon.hpp>

namespace glimac {

    bool verifDefaite(pokemon* Team) { // voir battleStart()
        bool NOKO;
        for (int i=0; i<=5; i++) {
            if (Team[i].pvNow > 0) {
                NOKO = true;
                i = 5;
            } else if (Team[i].pvNow <= 0) {
                NOKO = false;
            }
        }
        return NOKO;
    }

    bool verifVictoire(std::string* map, int larg, int haut) {
        bool VICTOIRE = true; // on initie VICTOIRE à vrai
        for (int i=0; i<=haut-1; i++) { //   ╗
            for (int j=0; j<=larg; j++) { // ╝ On défile case par case.
                if (map[i][j] == '?') { // si il y a un "x"
                    VICTOIRE = false; // VICTOIRE est donc faux.
                }
            }
        } // Si il a pas vu de "x", VICTOIRE reste vrai
        return VICTOIRE;
    }

}

#endif