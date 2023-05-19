#ifndef ALEATOIRE
#define ALEATOIRE

#include <stdlib.h>
#include <math.h>

namespace glimac {

    int fact(int n) {
        long int res = 1;
        for (int i = 2; i <= n; ++i) res*=i;
        return res;
    }

    float getPFromId(int id) {
        float p = (float)id/100;
        while (p > 1) --p;
        return p;
    }

    // - - - - - - A L E A T O I R E   C L A S S I Q U E S - - - - - - 

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

    int essaisGeometrique(float p) {
        int k = 1;
        float Px = std::pow(1-p, k-1)*p;
        while(Px < 0.95) {
            ++k;
            Px += std::pow(1-p, k-1)*p;
        }
        return k;
    }

    bool bernouilli(float p) {
        float val = uniforme();
        return val < p ? true : false;
    }

    float binomiale(int id, int k, int n) {
        float p = getPFromId(id);
        float Cnk = (float)fact(n)/((float)fact(k)*(float)fact(n-k));
        float Pk = Cnk*std::pow(p, k)*std::pow(1-p, n-k);
        return Pk;
    }

    int poisson(float lambda) {
        float L = std::exp(-lambda);
        float p = 1.0;
        int k = 0;

        while (p > L) {
            ++k;
            p *= uniforme();
        }

        return k-1;
    }

    // - - - - - - A L E A T O I R E   A   D E N S I T E - - - - - - 
    // - - - - - - O U   U N   T R U C   D U   G E N R E - - - - - -  

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