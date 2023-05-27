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
#include <glimac/aleatoire.hpp>

namespace glimac {

    class Point {
        public:
            Point(int x, int y, pokemon Poke) {this->x = x; this->y = y; this->Poke = Poke;};
            ~Point() = default;
            int x;
            int y;
            pokemon Poke;
    };

    std::vector<pokemon> pokemonVector(pokemon list[]) {
        std::vector<pokemon> pokeVec;
        for (int i = 0; i <= 95; ++i) {
            for (int j = 0; j <= list[i].rare; ++j) {
                pokeVec.push_back(list[i]);
            }
        }
        return pokeVec;
    }

    pokemon randomPokemon(std::vector<pokemon> &list) {
        int nb = uniforme() * list.size();
        return list[nb];
    }

    pokemon getPokemon(int x, int y, std::vector<Point> &points) {
        for (Point &point : points) {
            if (point.x == x && point.y == y) {
                return point.Poke;
            }
        }
        return points[(int)(uniforme()*points.size())].Poke;
    }

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

    std::vector<Point> genererPoints (std::string map[], int larg, int haut, int shape, int id, std::vector<pokemon> pokeVec) {
        std::vector<Point> points;
        float lambda = getPFromId(id)*(haut/3)*(larg/3);
        int nbPoke = poisson(lambda);
        //lireLigne("- d'après votre id et les paramètres que vous avez rentré, le nombre de pokémon qui apparaîtront sur la map sera calculé par une loi de Poisson de paramètre lambda = "+std::to_string(lambda)+".");
        lireLigne("- "+std::to_string(nbPoke)+" Pokémon apparaîtront sur la map.");
        switch(shape) {
            case(0):
                lireLigne("- Ils seront distribués de manière uniforme sur toute la surface de la map.");
                break;
            case(1):
                lireLigne("- Ils seront distribués suivant une courbe en forme de cloche de Gauss.");
                break;
            case(2):
                lireLigne("- Ils seront distribués suivant une loi triangulaire de support ]0, 1[ et de mode 1");
                break;
            break;
        }

        int nbPokeRareEstimation = hypergeometrique(286, 62, nbPoke, 1000);

        //lireLigne("- D'après une estimation réalisée selon une loi hypergeometrique, "+std::to_string(nbPokeRareEstimation)+" pokémon rares devraient apparaître !");
        lireLigne("- "+std::to_string(nbPokeRareEstimation)+" pokémon rares devraient apparaître !");

        wait(3000);
        for (int i = 0; i <= nbPoke; i++) { // on génerera un nombre de points égal à ((larg/10)*(haut/10))*2
            int coordY = floor(densite(0, shape) * (haut-2))+1;
            int coordX = floor(densite(0, shape) * (larg-2))+1;
            points.push_back(Point(coordX, coordY, randomPokemon(pokeVec)));
            map[coordY][coordX] = '?';
        }
        return points;
    }

    void mapStart(int id) {

        srand(id);

        std::cout << "id : " <<  id << std::endl;

        // On définit tous les pokémon
        


        pokemon Pikachu = definePikachu();
        pokemon Canarticho = defineCanarticho();
        pokemon Kangourex = defineKangourex();
        pokemon Scarabrute = defineScarabrute();
        pokemon Tauros = defineTauros();
        pokemon Locklass = defineLocklass();
        pokemon Insolourdo = defineInsolourdo();
        pokemon Qwilfish = defineQwilfish();
        pokemon Caratroc = defineCaratroc();
        pokemon Scarinho = defineScarinho();
        pokemon Corayon = defineCorayon();
        pokemon Cadoizo = defineCadoizo();
        pokemon Airmure = defineAirmure();
        pokemon Queulorior = defineQueulorior();
        pokemon Ecremeuh = defineEcremeuh();
        pokemon Tenefix = defineTenefix();
        pokemon Mysdibule = defineMysdibule();
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
        pokemon Morpheo = defineMorpheo();
        pokemon Kecleon = defineKecleon();
        pokemon Tropius = defineTropius();
        pokemon Absol = defineAbsol();
        pokemon Relicanth = defineRelicanth();
        pokemon Lovdisc = defineLovdisc();
        pokemon Pachirisu = definePachirisu();
        pokemon Pijako = definePijako();
        pokemon Spiritomb = defineSpiritomb();
        pokemon Vortente = defineVortente();
        pokemon Motisma = defineMotisma();
        pokemon Nanmeouie = defineNanmeouie();
        pokemon Judokrak = defineJudokrak();
        pokemon Karaclee = defineKaraclee();
        pokemon Bargantua = defineBargantua();
        pokemon Maracachi = defineMaracachi();
        pokemon Cryptero = defineCryptero();
        pokemon Emolga = defineEmolga();
        pokemon Mamanbo = defineMamanbo();
        pokemon Hexagel = defineHexagel();
        pokemon Limonde = defineLimonde();
        pokemon Drakkarmin = defineDrakkarmin();
        pokemon Frison = defineFrison();
        pokemon Aflamanoir = defineAflamanoir();
        pokemon Fermite = defineFermite();
        pokemon Couafarel = defineCouafarel();
        pokemon Brutalibre = defineBrutalibre();
        pokemon Dedenne = defineDedenne();
        pokemon Strassie = defineStrassie();
        pokemon Trousselin = defineTrousselin();
        pokemon Brocelome = defineBrocelome();
        pokemon Plumeline = definePlumeline();
        pokemon Froussardine = defineFroussardine();
        pokemon Guerilande = defineGuerilande();
        pokemon Gouroutan = defineGouroutan();
        pokemon Quartermac = defineQuartermac();
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
        pokemon Nigosier = defineNigosier();
        pokemon Hexadron = defineHexadron();
        pokemon Wimessir = defineWimessir();
        pokemon Duralugon = defineDuralugon();
        pokemon Wattapik = defineWattapik();
        pokemon Dolman = defineDolman();
        pokemon Bekaglacon = defineBekaglacon();
        pokemon Morpeko = defineMorpeko();
        pokemon Tapatoes = defineTapatoes();
        pokemon Craparoi = defineCraparoi();
        pokemon Lestombaile = defineLestombaile();
        pokemon Ferdeter = defineFerdeter();
        pokemon Flamenroule = defineFlamenroule();
        pokemon Delestin = defineDelestin();
        pokemon Oyacata = defineOyacata();
        pokemon Nigirigon = defineNigirigon();
        pokemon Motorizard = defineMotorizard();
        pokemon Chongjian = defineChongjian();
        pokemon Baojian = defineBaojian();
        pokemon Dinglu = defineDinglu();
        pokemon Yuyu = defineYuyu();
        pokemon RugitLune = defineRugitLune();
        pokemon GardeDeFer = defineGardeDeFer();

        // On les met dans une liste, cela permettra de tirer un pokémon aléatoire plus facilement pour les rencontres

        pokemon listeDesPokemon[96] = {Pikachu, Canarticho, Kangourex, Scarabrute, Tauros, Locklass, Insolourdo, Qwilfish, Caratroc, Scarinho, Corayon, Cadoizo, Airmure, Queulorior, Ecremeuh, Tenefix, Mysdibule, Posipi, Negapi, Muciole, Lumivole, Chartor, Spinda, Mangriff, Seviper, Seleroc, Solaroc, Morpheo, Kecleon, Tropius, Absol, Relicanth, Lovdisc, Pachirisu, Pijako, Spiritomb, Vortente, Motisma, Nanmeouie, Judokrak, Karaclee, Bargantua, Maracachi, Cryptero, Emolga, Mamanbo, Hexagel, Limonde, Drakkarmin, Frison, Aflamanoir, Fermite, Couafarel, Brutalibre, Dedenne, Strassie, Trousselin, Brocelome, Plumeline, Froussardine, Guerilande, Gouroutan, Quartermac, Concombaffe, Meteno, Dodoala, Boumata, Togedemaru, Mimiqui, Denticrisse, Draieul, Sinistrail, Katagami, Nigosier, Hexadron, Wimessir, Duralugon, Wattapik, Dolman, Bekaglacon, Morpeko, Tapatoes, Craparoi, Lestombaile, Ferdeter, Flamenroule, Delestin, Oyacata, Nigirigon, Motorizard, Chongjian, Baojian, Dinglu, Yuyu, RugitLune, GardeDeFer};

        int haut;
        std::cout << "hauteur de la map (conseillee : 25) : ";
        std::cin >> haut; // hauteur de la map
        const int hauteurMax = haut; // il faut absolument que ce soit une const pour les tailles de tableau
        std::string* map = new std::string[hauteurMax]; // tableau de strings map = ["#######", "#     #", "#     #", "#######"] en gros
        int larg;
        std::cout << "largeur de la map (conseillee : 50) : ";
        std::cin >> larg; // largeur de la map
        int shape;
        std::cout << "forme de la map (0 = normal, 1 = Gauss, 2 = Triangulaire) : ";
        std::cin >> shape;

        apparenceMap(map, larg, haut); // on génère l'apparence de la map

        std::vector<pokemon> pokeVec = pokemonVector(listeDesPokemon);

        pokemon playerTeam[6] = {Pikachu};

        std::vector<Point> points = genererPoints(map, larg, haut, shape, id, pokeVec); // on génère l'emplacement des points

        /*for (Point &p : points) {
            std::cout << p.x << " " << p.y << " " << p.Poke.nom << std::endl;
        }
        wait(5000);*/

        int coordX = 1; // coordonnée sur l'axe X du Personnage
        int coordY = 1; // coordonnée sur l'axe Y du Personnage

        map[coordY][coordX] = '0'; // on remplace le point 1,1 par le personnage (le point de repère est en haut à gauche)

        displayMap(map, haut); // on affiche la map

        bool KILL = false; // boolééen qui permettra de fermer le programme quand il sera sur true
        char dir; // on définit dir qui permettra de capter les inputs

        while(!KILL) { // tant que NOT KILL ou (KILL == false)
            if (kbhit() != 0) { // si kbhit (KeyBoard Hit), une touche du clavier est préssée
                dir = getch(); // on stocke dans dir la touche qui a été appuyée
                if (dir == 'z' && coordY > 1) { // si c'est Z et qu'on est pas collé au bord du haut
                    map[coordY][coordX] = ' '; // on remplace l'emplacement ou on est par du vide
                    coordY--; // on monte d'un cran sur l'axe Y
                    if (map[coordY][coordX] == '?') { // on vérifie si la case de destination est occupée par un x
                        pokemon poke = getPokemon(coordX, coordY, points);
                        battleStart(playerTeam, poke, id);
                    }
                    map[coordY][coordX] = '0'; // on remplace la nouvelle coordonnée par notre personnage
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
                    if (map[coordY][coordX] == '?') {
                        pokemon poke = getPokemon(coordX, coordY, points);
                        battleStart(playerTeam, poke, id);
                    }
                    map[coordY][coordX] = '0';
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
                    if (map[coordY][coordX] == '?') {
                        pokemon poke = getPokemon(coordX, coordY, points);
                        battleStart(playerTeam, poke, id);
                    }
                    map[coordY][coordX] = '0';
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
                    if (map[coordY][coordX] == '?') {
                        pokemon poke = getPokemon(coordX, coordY, points);
                        battleStart(playerTeam, poke, id);
                    }
                    map[coordY][coordX] = '0';
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