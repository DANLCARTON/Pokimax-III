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

    // - - - - - - A L E A T O I R E   U N I F O R M E S - - - - - - 

    float uniforme() {
        return static_cast<float>(rand())/RAND_MAX; // nombre aléatoire entre 0 et 1 distribué de manière uniforme.
    }

    float probaGeometrique(int id, int k) {
        float p = getPFromId(id);
        return std::pow(1-p, k-1)*p;
    }

    float geometrique(int id) {
        int tries = 1;
        float p = getPFromId(id);
        float pick = uniforme();
        while (pick > p) {
            ++tries;
            pick = uniforme();
        }
        return probaGeometrique(id, tries);
    }

    // - - - - - - A L E A T O I R E   A   D E N S I T E - - - - - - 

    float gauss(float val) {
        return (1/(std::sqrt(2*M_PI)))*std::exp(-2.0*val*val);
    }

    float x2(float val) {
        return 2*val;
    }

    float densite(int id, int courbe) {
        float val = uniforme();
        if (courbe == 1) {
            val = uniforme()*3-1.5;
            float image = uniforme()*.38;
            float obj = gauss(val);
            while (image > obj) {
                val = uniforme()*3-1.5;
                obj = gauss(val);
            }
            val = (val+1.5)/3;
        } else if (courbe == 2) {
            float image = uniforme()*2;
            float obj = x2(val);
            while (image > obj) {
                val = uniforme();
                obj = x2(val);
            }
        }
        return val;
    }

}

#endif