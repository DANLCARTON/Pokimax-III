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

    // Changer la fonction de placement des points genre chaque point à un pokémon prédéfini
    // Utiliser la loi Hypergéométrique pour évaluer le nombre de pokémon rares sur la map ????
    // 62 pokemon rares parmi 286 pokemon. 

    // UNIFORME
    // -> un peu tout
    float uniforme() {
        return static_cast<float>(rand())/RAND_MAX; // nombre aléatoire entre 0 et 1 distribué de manière uniforme.
    }

    // GEOMETRIQUE
    // -> sert pour les estimations
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

    // BERNOULLI
    // -> est-ce que l'attaque touche ou pas
    bool bernouilli(float p) {
        float val = uniforme();
        return val < p ? true : false;
    }

    // BINOMIALE
    // -> capture de pokémon
    float binomiale(int id, int k, int n) {
        float p = getPFromId(id);
        float Cnk = (float)fact(n)/((float)fact(k)*(float)fact(n-k));
        float Pk = Cnk*std::pow(p, k)*std::pow(1-p, n-k);
        return Pk;
    }

    // POISSON
    // -> génération du nombre de pokémon sur la map
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

    // HYPERGEOMETRIQUE
    // -> estimation du nombre de pokémon rares au lancement du jeu. 
    // -> parmi les 286 pokémon -pokemon * rareté- 62 sont rares. 
    int hypergeometrique(int n, int m, int x, int iter) {
        int mTotal = 0;

        for (int i = 0; i < iter; ++i) {
            int xSample = 0;

            for (int j = 0; j < x; ++j) {
                // Générer un nombre aléatoire entre 0 et la taille de la population
                int val = uniforme()*n;

                // Si le nombre aléatoire est inférieur au nombre d'éléments rares dans la population,
                // alors on compte cet élément rare dans l'échantillon
                if (val < m) {
                    xSample++;
                }
            }

            mTotal += xSample;
        }

        return mTotal / iter;
    }

    // - - - - - - A L E A T O I R E   A   D E N S I T E - - - - - - 
    // - - - - - - O U   U N   T R U C   D U   G E N R E - - - - - -  

    float gauss(float val) {
        return (1/(std::sqrt(2*M_PI)))*std::exp(-2.0*val*val);
    }

    float triangulaire(float mode) {
        float val = uniforme();
        if (val < mode) {
            return sqrt(val*mode);
        } else {
            return 1-sqrt((1-val)*(1-mode));
        }
    }


    // UNIFORME A DENSITE je crois
    // surement oui
    // -> emplacement des pokémon sur la map.
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
            val = triangulaire(1);

        }
        return val;
    }

}

#endif