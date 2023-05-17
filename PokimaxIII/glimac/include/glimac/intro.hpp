#ifndef INTRO
#define INTRO
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

namespace glimac {

    void lireLigne(std::string L) {
        for (int i = 0; i < L.length(); i++) {
            std::cout << L[i]; // on affiche un par un chaque caractère de la ligne
            std::this_thread::sleep_for(std::chrono::milliseconds(50)); // on attent 50ms entre chaque caractère
        }
        std::cout << std::endl;
    }

    void entreLigne() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // on attent 1500ms puis
        std::cout << "\x1B[2J\x1B[H"; // on efface le contenu de la console
    }

    void intro() {
        
        entreLigne();

        lireLigne("...\n...");
        entreLigne();

        lireLigne("... (baillement) ...");
        entreLigne();

        lireLigne("Hein ? Quoi ? Deja ?\nNoooon ! J'ai rate l'heure !");
        entreLigne();

        lireLigne("Desole de t'avoir fait attendre !");
        entreLigne();

        lireLigne("Bienvenue dans le monde de Pokemon !");
        entreLigne();

        lireLigne("Mon nom est Chen.");
        entreLigne();

        lireLigne("Mais tout le monde m'appelle\nle Professeur Pokemon");
        entreLigne();

        lireLigne("Tu debutes tout juste ton aventure,\nje me trompe ?");
        entreLigne();

        lireLigne("Laisse-moi tout d'abord t'enseigner\nles bases de ce monde !");
        entreLigne();

        lireLigne("Ce monde est peuple de creatures\nappelees Pokemon.");
        entreLigne();

        lireLigne("Nous les humains, vivons avec les\nPokemon.");
        entreLigne();

        lireLigne("Il nous arrive de jouer\nou de travailler ensemble.");
        entreLigne();

        lireLigne("Certaines personnes utilisent les\nPokemon pour combattre et creent\nun lien tres fort avec eux.");
        entreLigne();

        lireLigne("Moi ?");
        entreLigne();

        lireLigne("Je me contente de faire des\nrecherches, pour que nous en\nsachions plus sur les Pokémon.");
        entreLigne();

        lireLigne("Mais avant tout, parle-moi\nun peu de toi.");
        entreLigne();

        lireLigne("Comment t'appelles-tu ? \nVotre Nom ? : ");

        std::string playerName;
        std::cin >> playerName;

        entreLigne();

        lireLigne("Alors tu t'appelles "+playerName+" ?\nTres bien !");
        entreLigne();

        lireLigne("Et ton equipe, comment s'appelle-t-elle ? \nVotre Equipe ? : ");

        std::string teamName;
        std::cin >> teamName;

        entreLigne();

        lireLigne("Le moment est venu, "+playerName+" !\nTout est pret ?");
        entreLigne();

        lireLigne("Ah ! J'ai failli oublier !");
        entreLigne();

        lireLigne("Deplace toi avec les touches\nZ, Q, S et D. Appuie sur la touche T\npour gerer ton équipe.\nPour les actions en combat utilise\nles touches R, T, F et G.");
        entreLigne();

        lireLigne("tu peux appuyer sur ECHAP pour\nquitter le jeu");
        entreLigne();

        lireLigne("Allez, plonge dans le monde des\nPokemon !");
        entreLigne();
    }
}

#endif