#ifndef ALEATOIRE
#define ALEATOIRE

#include <stdlib.h>
#include <math.h>

namespace glimac {

    float getPFromId(int id) {
        float p = (float)id/100;
        while (p > 1) --p;
        return p;
    }

    float uniforme() {
        return rand()/RAND_MAX; // nombre aléatoire entre 0 et 1 distribué de manière uniforme.
    }

    float geometrique(int id) {
        int tries = 1;
        float p = getPFromId(id);
        float pick = uniforme();
        while (pick > p) {
            ++tries;
            pick = uniforme();
        }
        return tries;
    }

    float probaGeometrique(int id, int k) {
        float p = getPFromId(id);
        return std::pow(1-p, k-1)*p;
    }

}

#endif