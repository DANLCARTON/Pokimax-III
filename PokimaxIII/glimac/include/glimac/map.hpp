#ifndef MAP
#define MAP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <conio.h>  
#include <glimac/SDLWindowManager.hpp>
#include <random>
#include <glimac/intro.hpp>
#include <glimac/pokemon.hpp>
#include <glimac/battle.hpp>
#include <glimac/verifStop.hpp>

namespace glimac {

    void displayMap(std::string map[], int haut) {
        std::cout << "\x1B[2J\x1B[H"; // permet d'effacer le contenu de la console.
        std::cout << map[0] << std::endl;  // affiche la première ligne
        for (int i = 1; i <= haut-2; i++) {
            std::cout << map[i] << std::endl; // affiche les lignes intermédiaires
        }
        std::cout << map[haut-1] << std::endl; // affiche la dernière ligne
    }

    void apparenceMap (std::string map[], int larg, int haut) {
        for (int i = 0; i <= larg; i++) {
            map[0]+="-"; // première ligne de la map -----------
        }
        for (int i = 1; i <= haut-2; i++) {
            map[i] = "|"; // premiers caractères à gauche de la map |
            for (int j = 0; j <= larg-2; j++) {
                map[i]+=" "; // espaces à l'intérieur de la map;
            }
            map[i]+="|"; // dernièrs caractères à droite de la map |
        }
        for (int i = 0; i <= larg; i++) {
            map[haut-1]+="-"; // dernière ligne de la map ------------
        }

        // displayMap(map, haut);

        /* SCHEMA DES COORDONNEES SUR LA MAP

        0123456789
        0 ----------
        1 |        |    du coup sur l'axe Y, - = ↑ et + = ↓
        2 |        |    et sur l'axe X, - = ← et + = →
        3 |        |
        4 |        |
        5 |        |
        6 |        |
        7 |        |
        8 |        |
        9 ----------


        */
    }

    void genererPoints (std::string map[], int larg, int haut) {
        for (int i = 0; i <= (larg/10)*(haut/10)*2; i++) { // on génerera un nombre de points égal à ((larg/10)*(haut/10))*2
            int randomCoordY = rand() % (haut-2) + 1; // nombre aléatoire entre 1 et 1+(haut-2)
            int randomCoordX = rand() % (larg-2) + 1; // nombre aléatoire entre 1 et 1+(larg-2)
            map[randomCoordY][randomCoordX] = 'x';
        }
    }

    void mapStart() {

        // On définit tous les pokémon

        pokemon Pikachu = definePikachu();
        pokemon Canarticho = defineCanarticho();
        pokemon Insolourdo = defineInsolourdo();
        pokemon Qwilfish = defineQwilfish();
        pokemon Caratroc = defineCaratroc();
        pokemon Corayon = defineCorayon();
        pokemon Cadoizo = defineCadoizo();
        pokemon Airmure = defineAirmure();
        pokemon Ecremeuh = defineEcremeuh();
        pokemon Posipi = definePosipi();
        pokemon Negapi = defineNegapi();
        pokemon Muciole = defineMuciole();
        pokemon Lumivole = defineLumivole();
        pokemon Chartor = defineChartor();
        pokemon Spinda = defineSpinda();
        pokemon Mangriff = defineMangriff();
        pokemon Seviper = defineSeviper();
        pokemon Seleroc = defineSeleroc();
        pokemon Solaroc = defineSolaroc();
        pokemon Kecleon = defineKecleon();
        pokemon Pachirisu = definePachirisu();
        pokemon Pijako = definePijako();
        pokemon Motisma = defineMotisma();
        pokemon Nanmeouie = defineNanmeouie();
        pokemon Bargantua = defineBargantua();
        pokemon Maracachi = defineMaracachi();
        pokemon Emolga = defineEmolga();
        pokemon Mamambo = defineMamambo();
        pokemon Hexagel = defineHexagel();
        pokemon Limonde = defineLimonde();
        pokemon Aflamanoir = defineAflamanoir();
        pokemon Fermite = defineFermite();
        pokemon Dedenne = defineDedenne();
        pokemon Strassie = defineStrassie();
        pokemon Brocelome = defineBrocelome();
        pokemon Plumeline = definePlumeline();
        pokemon Froussardine = defineFroussardine();
        pokemon Concombaffe = defineConcombaffe();
        pokemon Meteno = defineMeteno();
        pokemon Dodoala = defineDodoala();
        pokemon Boumata = defineBoumata();
        pokemon Togedemaru = defineTogedemaru();
        pokemon Mimiqui = defineMimiqui();
        pokemon Denticrisse = defineDenticrisse();
        pokemon Draieul = defineDraieul();
        pokemon Sinistrail = defineSinistrail();
        pokemon Katagami = defineKatagami();
        pokemon Wattapik = defineWattapik();
        pokemon Dolman = defineDolman();
        pokemon Bekaglacon = defineBekaglacon();
        pokemon Morpeko = defineMorpeko();

        // On les met dans une liste, cela permettra de tirer un pokémon aléatoire plus facilement pour les rencontres

        pokemon listeDesPokemon[51] = {Pikachu, Canarticho, Insolourdo, Qwilfish, Caratroc, Corayon, Cadoizo, Airmure, Ecremeuh, Posipi, Negapi, Muciole, Lumivole, Chartor, Spinda, Mangriff, Seviper, Seleroc, Solaroc, Kecleon, Pachirisu, Pijako, Motisma, Nanmeouie, Bargantua, Maracachi, Emolga, Mamambo, Hexagel, Limonde, Aflamanoir, Fermite, Dedenne, Strassie, Brocelome, Plumeline, Froussardine, Concombaffe, Meteno, Dodoala, Boumata, Togedemaru, Mimiqui, Denticrisse, Draieul, Sinistrail, Katagami, Wattapik, Dolman, Bekaglacon, Morpeko};

        // Une liste pour l'équipe du joueur

        pokemon playerTeam[6] = {Pikachu, Canarticho, Insolourdo, Qwilfish, Caratroc, Corayon};

        int haut;
        std::cout << "hauteur de la map (conseillee : 25) : ";
        std::cin >> haut; // hauteur de la map
        const int hauteurMax = haut; // il faut absolument que ce soit une const pour les tailles de tableau
        std::string* map = new std::string[hauteurMax]; // tableau de strings map = ["#######", "#     #", "#     #", "#######"] en gros
        int larg;
        std::cout << "largeur de la map (conseillee : 50): ";
        std::cin >> larg; // largeur de la map

        apparenceMap(map, larg, haut); // on génère l'apparence de la map

        genererPoints(map, larg, haut); // on génère l'emplacement des points

        int coordX = 1; // coordonnée sur l'axe X du Personnage
        int coordY = 1; // coordonnée sur l'axe Y du Personnage

        map[coordY][coordX] = '#'; // on remplace le point 1,1 par le personnage (le point de repère est en haut à gauche)

        displayMap(map, haut); // on affiche la map

        bool KILL = false; // boolééen qui permettra de fermer le programme quand il sera sur true
        char dir; // on définit dir qui permettra de capter les inputs

        while(!KILL) { // tant que NOT KILL ou (KILL == false)
            if (kbhit() != 0) { // si kbhit (KeyBoard Hit), une touche du clavier est préssée
                dir = getch(); // on stocke dans dir la touche qui a été appuyée
                if (dir == 'z' && coordY > 1) { // si c'est Z et qu'on est pas collé au bord du haut
                    map[coordY][coordX] = ' '; // on remplace l'emplacement ou on est par du vide
                    coordY--; // on monte d'un cran sur l'axe Y
                    if (map[coordY][coordX] == 'x') { // on vérifie si la case de destination est occupée par un x
                        std::random_device rd; //                           ╗
                        std::mt19937 gen(rd()); //                          ║ Permet de tirer un nombre aléatoire entre 0 et 50
                        std::uniform_int_distribution<> distrib(0, 50);//   ╝
                        battleStart(playerTeam, listeDesPokemon[distrib(gen)]);
                    }
                    map[coordY][coordX] = '#'; // on remplace la nouvelle coordonnée par notre personnage
                    bool NOKO = verifDefaite(playerTeam); // NOKO est true si au moins un des pokémon est en état de se battre
                    if (!NOKO) { // si NOKO est false
                        entreLigne();
                        lireLigne("Tous vos Pokemon sont KO...\n\n     - G A M E   O V E R -    \n"); // GAME OVER
                        KILL = true; // on sort de la boucle
                    } else { // si NOKO est vrai (ne pas vérifier la victoire si NOKO est faux sinon on pourrait gagner et perdre en même temps)
                        bool VICTOIRE = verifVictoire(map, larg, haut); // VICTOIRE est true s'il n'y a plus de x sur la map.
                        if (VICTOIRE) { // si VICTOIRE est true
                            entreLigne();
                            lireLigne("Bravo ! Vous avez rencontre \ntous les Pokemon de la region !!\n\n      - F I N -      \n"); // GG MEK
                            KILL = true; // on sort de la boucle
                        }
                    }
                } else if (dir == 's' && coordY < haut-2) { // touche S et pas collé au bord du bas
                    map[coordY][coordX] = ' ';
                    coordY++; // on descend d'un cran sur l'axe Y
                    if (map[coordY][coordX] == 'x') {
                        std::random_device rd; 
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<> distrib(0, 50);
                        battleStart(playerTeam, listeDesPokemon[distrib(gen)]);
                    }
                    map[coordY][coordX] = '#';
                    bool NOKO = verifDefaite(playerTeam);
                    if (!NOKO) {
                        entreLigne();
                        lireLigne("Tous vos Pokemon sont KO...\n\n     - G A M E   O V E R -    \n");
                        KILL = true;
                    } else {
                        bool VICTOIRE = verifVictoire(map, larg, haut);
                        if (VICTOIRE) {
                            entreLigne();
                            lireLigne("Bravo ! Vous avez rencontre \ntous les Pokemon de la region !!\n\n      - F I N -      \n");
                            KILL = true;
                        }
                    }
                } else if (dir == 'q' && coordX > 1) { // Si c'est Q et qu'on est pas collé au bord de gauche
                    map[coordY][coordX] = ' ';
                    coordX--;
                    if (map[coordY][coordX] == 'x') {
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<> distrib(0, 50);
                        battleStart(playerTeam, listeDesPokemon[distrib(gen)]);
                    }
                    map[coordY][coordX] = '#';
                    bool NOKO = verifDefaite(playerTeam);
                    if (!NOKO) {
                        entreLigne();
                        lireLigne("Tous vos Pokemon sont KO...\n\n     - G A M E   O V E R -    \n");
                        KILL = true;
                    } else {
                        bool VICTOIRE = verifVictoire(map, larg, haut);
                        if (VICTOIRE) {
                            entreLigne();
                            lireLigne("Bravo ! Vous avez rencontre \ntous les Pokemon de la region !!\n\n      - F I N -      \n");
                            KILL = true;
                        }
                    }
                } else if (dir == 'd' && coordX < larg-1) { // Si c'est D et qu'on est pas collé au bord de droite
                    map[coordY][coordX] = ' ';
                    coordX++;
                    if (map[coordY][coordX] == 'x') {
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<> distrib(0, 50);
                        battleStart(playerTeam, listeDesPokemon[distrib(gen)]);
                    }
                    map[coordY][coordX] = '#';
                    bool NOKO = verifDefaite(playerTeam);
                    if (!NOKO) {
                        entreLigne();
                        lireLigne("Tous vos Pokemon sont KO...\n\n     - G A M E   O V E R -    \n");
                        KILL = true;
                    } else {
                        bool VICTOIRE = verifVictoire(map, larg, haut);
                        if (VICTOIRE) {
                            entreLigne();
                            lireLigne("Bravo ! Vous avez rencontre \ntous les Pokemon de la region !!\n\n      - F I N -      \n");
                            KILL = true;
                        }
                    }
                } else if (dir == 't'){ // Si on appuie sur la touche T
                    std::cout << "\x1B[2J\x1B[H"; // on efface la console
                    battleChangePokemon(playerTeam); // on lance la fonction pour changer de pokémon (c'est la même que pour les combats)
                } else if (int(dir) == 27) { // si la touche echap est appuyée (corrsespond à 27 en ACSII)
                    std::cout << "ECHAP APPUYEE"; // on affiche cette phrase là
                    KILL = true; // on passe KILL à TRUE ce qui aura pour effet de sortir de la boucle while
                }
                if (!KILL) {
                    displayMap(map, haut); // après tous les if on affiche la map avant de relancer la boucle
                }
                
            }
        }
    }

}

#endif