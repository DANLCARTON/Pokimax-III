#ifndef BATTLE
#define BATTLE

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <conio.h> 
#include <random>
#include <glimac/intro.hpp>
#include <glimac/pokemon.hpp>


namespace glimac {

    void displayBattle(pokemon Pokemon1, pokemon Pokemon2) {
    std::cout << "\x1B[2J\x1B[H"; // permet d'effacer le contenu de la console.

    //                   FROUSSARDINE
    //                   ###/100
    //   PIKACHU
    //   ###/100
    //
    // Un FROUSSARDINE sauvage apparait !
    //
    // R - ATTAQUE   T - POKEMON
    // F - CAPTURE   G - FUITE

    std::cout << "                  " << Pokemon2.nom << std::endl;
    std::cout << "                  " << Pokemon2.pvNow << "/" << Pokemon2.pvMax << std::endl;
    std::cout << "   " << Pokemon1.nom << std::endl;
    std::cout << "   " << Pokemon1.pvNow << "/" << Pokemon1.pvMax << std::endl << std::endl;
    std::cout << "Un " << Pokemon2.nom << " sauvage apparait !" << std::endl << std::endl;
    std::cout << "R - ATTAQUE   T - POKEMON" << std::endl;
    std::cout << "F - CAPTURE   G - FUITE";
}

float calculSensibilite(pokemon atk, pokemon def) {

    // N = Normal
    // W = Eau
    // F = Feu
    // G = Plante
    // E = Electrik
    // R = Roche

    //   TABLEAU DE TYPES :

    //                  D E F
    //   +----+----+----+----+----+----+----+
    //   |    |  N |  W |  F |  G |  E |  R |
    //   +----+----+----+----+----+----+----+
    //   |  N |  1 |  1 |  1 |  1 |  1 |  1 |
    //   +----+----+----+----+----+----+----+
    //   |  W |  1 |  1 |  2 | .5 | .5 |  2 |
    // A +----+----+----+----+----+----+----+
    // T |  F |  1 | .5 |  1 |  2 |  1 | .5 |
    // K +----+----+----+----+----+----+----+
    //   |  G |  1 |  2 | .5 |  1 | .5 |  2 |
    //   +----+----+----+----+----+----+----+
    //   |  E |  1 |  2 |  1 |  2 |  1 | .5 |
    //   +----+----+----+----+----+----+----+
    //   |  R |  1 |  2 |  2 | .5 |  2 |  1 |
    //   +----+----+----+----+----+----+----+

    float sensi = 1;

    if (atk.type == 'W') { // Pokemon de type Eeu
        if (def.type == 'F' || def.type == 'R') { 
            sensi = 2; // Super efficace sur les types Feu et Roche
        } else if (def.type == 'G' || def.type == 'E') { 
            sensi = 0.5; // Pas très efficace sur les types Plante et Eau
        }
    } else if (atk.type == 'F') { // Pokemon de type Feu
        if (def.type == 'G') {
            sensi = 2; // Super efficace sur le type Plante
        } else if (def.type == 'W' || def.type == 'R') {
            sensi = 0.5; // Pas très efficace sur les types Eau et Roche
        }
    } else if (atk.type == 'G') { // Pokemon de type Plante
        if (def.type == 'W' || def.type == 'R') {
            sensi = 2; // Super efficace sur les types Eau et Roche
        } else if (def.type == 'F' || def.type == 'E') {
            sensi = 0.5; // Pas très efficace sur les types Feu et Electrik
        }
    } else if (atk.type == 'E') { // Pokemon de type Electrik
        if (def.type == 'W' || def.type == 'G') {
            sensi = 2; // Super efficace sur les types Eau et Plante
        } else if (def.type == 'R') {
            sensi = 0.5; // Pas très efficace sur le type Roche
        }
    } else if (atk.type == 'R') { // Pokemon de type Roche
        if (def.type == 'W' || def.type == 'F' || def.type == 'E') {
            sensi = 2; // Super efficace sur les types Eau, Feu et Electrik
        } else if (def.type == 'G') {
            sensi = 0.5; // Pas très efficace sur le type Plante
        }
    }

    return sensi;
}

int battleAttaque(pokemon Pokemon, pokemon Foe) {
    float sensi = calculSensibilite(Pokemon, Foe); // On commence par calculer la sensibilité des types
    float pvARetirer = ((27*Pokemon.atk)/Foe.def)*sensi; // On calcule les dégâts

    std::string efficacite;
    if (sensi == 2) {
        efficacite = "C'est super efficace !";
    } else if (sensi == .5) {
        efficacite = "Ce n'est pas tres efficace...";
    }
    std::string ligne = "\n\n"+Pokemon.nom+" attaque !\n"+efficacite+"\n"+Foe.nom+" perd "+to_string((int)pvARetirer)+" PV";
    lireLigne(ligne);

    // PIKACHU attaque !
    // C'est super effficace !
    // FROUSSARDINE perd ### PV

    Foe.pvNow -= pvARetirer;

    return Foe.pvNow;
}

void battleChangePokemon(pokemon* Pokemon) { 
    lireLigne("\n\nQuel Pokemon doit remplacer "+Pokemon[0].nom+" ?");
    for (int i=0; i<=5; i++) {
        cout << to_string(i+1)+" - "+Pokemon[i].nom << endl;
    }

    int choixPokemon;
    pokemon slotReserve; // Permettra de mettre de côté le pokémon a changer de place
    bool CHOIXVALIDE = false; // permettra de sortir de la boucle
    while (!CHOIXVALIDE) { // Tant que CHOIXVALIDE est faux
        cin >> choixPokemon; // On demande lequel on veut
        if (choixPokemon > 6) { // si le choix est supérieur à 6
            ; // on fait rien
        } else if (choixPokemon <= 6 && choixPokemon != 1 && Pokemon[choixPokemon-1].nom != "" && Pokemon[choixPokemon-1].pvNow > 0) { // si le choix est inférieur à 6, différent de 1, qu'il ne donne pas sur un emplacement vide et que le pokémon n'est pas KO
            slotReserve = Pokemon[0]; // on met en réserve le premier pokémon de l'équipe
            Pokemon[0] = Pokemon[choixPokemon-1]; // on met en premier le pokémon choisi (on fait -1 parce que les choix vont de 1 à 6 et les pokémon sont indexés de 0 à 5)
            Pokemon[choixPokemon-1] = slotReserve; // on remplace l'emplacement du pokémon choisi par celui qui était en réserve.
            CHOIXVALIDE = true; // le choix est valide
        } else if (choixPokemon == 1) { // Si le choix est 1
            CHOIXVALIDE = true; // Le choix est valide mais rien ne change
        }
    }
}

void battleCaptureChangePokemon(pokemon* Pokemon, pokemon Foe) { // Fonction basée sur battleChangePokemon() au fonctionnement à peu près similaire
    lireLigne("\n\nVous avez capture "+Foe.nom+" !\nseulement votre equipe ne peux pas contenir\nplus de 6 pokemon.\n\nQuel pokemon voulez-vous relacher ?");
    for (int i=0; i<=5; i++) {
        std::cout << to_string(i+1)+" - "+Pokemon[i].nom << std::endl;
    }
    std::cout << "7 - "+Foe.nom << std::endl;

    // Vous avez capturé FROUSSARDINE !
    // seulement votre équipe ne peux pas contenir
    // plus de 6 pokémon.
    //
    // Quel pokémon voulez-vous relâcher ?
    // 1 - PIKACHU
    // 2 - CANARTICHO
    // 3 - INSOLOURDO
    // 4 - QWILFISH
    // 5 - CARATROC
    // 6 - CORAYON
    // 7 - FROUSSARDINE

    int choixPokemon;
    bool CHOIXVALIDE = false;
    while (!CHOIXVALIDE) {
        cin >> choixPokemon;
        if (choixPokemon > 7) {
            ;
        } else if (choixPokemon <= 6) {
            Pokemon[choixPokemon-1] = Foe;
            CHOIXVALIDE = true;
        } else if (choixPokemon == 7) {
            CHOIXVALIDE = true;
        }
    }
}

void battleKOChangePokemon(pokemon* Pokemon) { // Fonction basée sur battleChangePokemon() au fonctionnement à peu près similaire
    lireLigne("\n"+Pokemon[0].nom+" est KO !\nQuel pokemon doit le remplacer ?");
    for (int i=1; i<=5; i++) {
        std::cout << to_string(i+1)+" - "+Pokemon[i].nom << std::endl;
    }
    int choixPokemon;
    pokemon slotReserve;
    bool CHOIXVALIDE = false; 
    while (!CHOIXVALIDE) { 
        cin >> choixPokemon; 
        if (choixPokemon > 6) { 
            ; 
        } else if (choixPokemon <= 6 && choixPokemon != 1 && Pokemon[choixPokemon-1].nom != "" && Pokemon[choixPokemon-1].pvNow > 0) { 
            slotReserve = Pokemon[0]; 
            Pokemon[0] = Pokemon[choixPokemon-1]; 
            Pokemon[choixPokemon-1] = slotReserve; 
            CHOIXVALIDE = true; 
        } else if (choixPokemon == 1) { 
            lireLigne(Pokemon[0].nom+" ne peut plus se battre !");
        }
    }
}

bool battleCapture(pokemon* Pokemon, pokemon Foe) {
    float a = (1-((2*Foe.pvNow)/300))*Foe.taux; // a sera compris entre 3 et 100. 
    lireLigne("\n\nLa capture a "+to_string((int)a)+"% de chances de reussir"); // on affiche le %age de chances de réussir (a)
    std::random_device rd; //                           ╗
    std::mt19937 gen(rd()); //                          ║ Permet de tirer un nombre aléatoire entre 1 et 100
    std::uniform_int_distribution<> distrib(1, 100);//  ╝
    bool CAPTURE = false; // Pour l'instant rien n'est joué
    if (distrib(gen) <= 100) {
        lireLigne("............            "); // La Poké Ball tremble 1 fois
    } 
    if (distrib(gen) <= (((100-a)/3)*2)+a) {
        lireLigne("............            "); // La Poké Ball tremble 2 fois
    }
    if (distrib(gen) <= ((100-a)/3)+a) {
        lireLigne("............            "); // La Poké Ball tremble 3 fois
    }
    if (distrib(gen) <= a) { // Si le nombre aléatoire tiré est inférieur ou égal à a
        lireLigne("\nBRAVO ! "+Foe.nom+" a ete capture !!"); // La Capture est réussie
        int i = 1; // i permettra de défiler dans l'équipe pour voir où ajouter le pokémon capturé
        while (!CAPTURE) { // Tant que la capture sera considérée comme fausse
            if (i > 5) { // Si i passe au dessus de 5, c'est que l'équipe est pleine.
                battleCaptureChangePokemon(Pokemon, Foe); // un fonction pour ce cas là se lance, permettant de faire une place dans l'équipe
                CAPTURE = true; // on indique que la capture a été effectuée
            } else if (Pokemon[i].nom == "") { // Si il y a un emplacement vide
                Pokemon[i] = Foe; // Cet emplacement est remplacé par le pokémon capturé
                CAPTURE = true; // on indique que la capture a été effectuée
            }
            i++; // On passe a l'emplacement suivant 
        }
    } else { // Si le nombre aléatoire tiré est supérieur à a
        lireLigne ("\nAAAARG ! La capture a echoue !"); // voilà
    }
    return CAPTURE; // Pour savoir si le pokémon sauvage pourra attaquer ensuite ou pas.
}

void battleStart(pokemon* Pokemon, pokemon Foe) {

    displayBattle(Pokemon[0], Foe); // On affiche l'écran de combat

    bool ACTION = true; // ACTION permettra d'arrêter le combat au moment voulu
    bool CAPTURE = false; // CAPTURE permettra de savoir si le pokémon sauvage est capturé
    bool NOKO = true; // (no KO) permettra de savoir si toute l'équipe est KO

    while(ACTION && NOKO) { // Tant que ACTION est vrai et que l'équipe est pas KO
        if (kbhit) { // Si on appuie sur une touche
            char act = getch(); // on récupère la touche sur laquelle on appuyé
            if (act == 'r') { // si c'est R
                Foe.pvNow = battleAttaque(Pokemon[0], Foe); // On lance la fonction ATTAQUE avec notre pokémon à l'attaque et le pokémon sauvage en défense
                if (Foe.pvNow <= 0) { // Si le pokémon sauvage a 0PV ou des PV négatifs
                    lireLigne(Foe.nom+" est KO !"); // il est KO
                    ACTION = false; // ACTION devient Faux, le combat s'arrête, retour à la map
                }
                if (ACTION) { // Se le combat ne s'est pas arrêté avant
                    Pokemon[0].pvNow = battleAttaque(Foe, Pokemon[0]); // ATTAQUE avec le pokémon sauvage à l'attaque et le nôtre en défense
                    if (Pokemon[0].pvNow <= 0) { // Si notre pokémon a 0PV ou des PV négatifs
                        for (int i=0; i<=5; i++) { // on défile dans l'équipe
                            if (Pokemon[i].pvNow > 0) { // Si ne serai-ce qu'un seul pokémon dans l'équipe n'est pas KO
                                NOKO = true; // NOKO reste ou redevient vrai
                                i = 5; // on passe i a 5 pour sortir tout de suite de la boucle for
                            } else if (Pokemon[i].pvNow <= 0) { // Si un pokémon est KO
                                NOKO = false; // NOKO devient faux, si tous les pokémon après ça sont KO, NOKO restera faux
                            }
                        }
                        if (NOKO) { // Si NOKO est vrai
                            battleKOChangePokemon(Pokemon); // Le joueur doit changer de pokémon
                        } else { // Sinon
                            ACTION = false; // on arrête le combat
                        }
                    }
                }
            } else if (act == 't') { // si c'est T
                battleChangePokemon(Pokemon); // on lance la fonction pour changer de pokémon
                Pokemon[0].pvNow = battleAttaque(Foe, Pokemon[0]); // ATTAQUE avec le pokémon sauvage à l'attaque et le nôtre en défense
                if (Pokemon[0].pvNow <= 0) { // Si notre pokémon a 0PV ou des PV négatifs
                    for (int i=0; i<=5; i++) {
                        if (Pokemon[i].pvNow > 0) {
                            NOKO = true;
                            i = 5;
                        } else if (Pokemon[i].pvNow <= 0) {
                            NOKO = false;
                        }
                    }
                    if (NOKO) {
                        battleKOChangePokemon(Pokemon);
                    } else {
                        ACTION = false;
                    }
                }
            } else if (act == 'f') {
                CAPTURE = battleCapture(Pokemon, Foe);
                if (CAPTURE) {
                    ACTION = false;
                }
                if (ACTION) { // Se le combat ne s'est pas arrêté avant
                    Pokemon[0].pvNow = battleAttaque(Foe, Pokemon[0]); // ATTAQUE avec le pokémon sauvage à l'attaque et le nôtre en défense
                    if (Pokemon[0].pvNow <= 0) { // Si notre pokémon a 0PV ou des PV négatifs
                        for (int i=0; i<=5; i++) {
                            if (Pokemon[i].pvNow > 0) {
                                NOKO = true;
                                i = 5;
                            } else if (Pokemon[i].pvNow <= 0) {
                                NOKO = false;
                            }
                        }
                        if (NOKO) {
                            battleKOChangePokemon(Pokemon);
                        } else {
                            ACTION = false;
                        }
                    }
                }
            } else if (act == 'g' || (int)act == 27) { // Si c'est R ou ECHAP
                ACTION = false; // ACTION devient Faux, le combat s'arrête, retour à la map
            } else { // Si c'est n'importe quelle autre touche
                std::cout << std::endl; // en gros rien
            }
            displayBattle(Pokemon[0], Foe); // On actualiste l'écran de combat
        }
    }
}

}

#endif