#ifndef POKEMON
#define POKEMON
#include <string>

namespace glimac {

    typedef struct {
        std::string nom;
        char type; // N(78) = normal | W(87) = eau | F(70) = feu | G(71) = plante | E(69) = électrik | R(82) = roche
        int pvMax; // 100% des points de vie des poékmon
        int pvNow; // points de vie actuels des pokémon (après s'être pris un coup)
        int atk; // stat d'attaque
        int def; // stat de défence
        int taux; // taux de capture (100 = égal facile à capturer, 0 = impossible (littéralement) à capturer)
        int prc;
        int rare;
        std::string getTypeName();
    }pokemon;

    std::string pokemon::getTypeName() {
        switch(this->type) {
            case ('E'):
                return "Electrik";
                break;
            case ('N'):
                return "Normal";
                break;
            case ('W'):
                return "Eau";
                break;
            case ('R'):
                return "Roche";
                break;
            case ('F'):
                return "Feu";
                break;
            case('G'):
                return "Plante";
                break;
        }
        return "none";
    }

    pokemon definePikachu() {
        pokemon Pikachu;

        Pikachu.nom = "PIKACHU";
        Pikachu.type = 'E';
        Pikachu.pvMax = 100;
        Pikachu.pvNow = 100;
        Pikachu.atk = 70;
        Pikachu.def = 70;
        Pikachu.taux = 80;
        Pikachu.prc = 120;
        Pikachu.rare = 1;

        return Pikachu;
    }

    pokemon defineCanarticho() {
        pokemon Canarticho;

        Canarticho.nom = "CANARTICHO";
        Canarticho.type = 'N';
        Canarticho.pvMax = 52;
        Canarticho.pvNow = 52;
        Canarticho.atk = 90;
        Canarticho.def = 55;
        Canarticho.taux = 75;
        Canarticho.prc = 60;
        Canarticho.rare = 2;

        return Canarticho;
    }

    pokemon defineKangourex() {
        pokemon Kangourex;

        Kangourex.nom = "KANGOUREX";
        Kangourex.type = 'R';
        Kangourex.pvMax = 105;
        Kangourex.pvNow = 105;
        Kangourex.atk = 95;
        Kangourex.def = 80;
        Kangourex.taux = 18;
        Kangourex.prc = 90;
        Kangourex.rare = 2;

        return Kangourex;
    }

    pokemon defineScarabrute() {
        pokemon Scarabrute;

        Scarabrute.nom = "SCARABRUTE";
        Scarabrute.type = 'G';
        Scarabrute.pvMax = 65;
        Scarabrute.pvNow = 65;
        Scarabrute.atk = 125;
        Scarabrute.def = 100;
        Scarabrute.taux = 18;
        Scarabrute.prc = 85;
        Scarabrute.rare = 2;

        return Scarabrute;
    }

    pokemon defineTauros() {
        pokemon Tauros;

        Tauros.nom = "TAUROS";
        Tauros.type = 'N';
        Tauros.pvMax = 75;
        Tauros.pvNow = 75;
        Tauros.atk = 100;
        Tauros.def = 95;
        Tauros.taux = 18;
        Tauros.prc = 110;
        Tauros.rare = 2;

        return Tauros;
    }

    pokemon defineLocklass() {
        pokemon Locklass;

        Locklass.nom = "LOCKLASS";
        Locklass.type = 'W';
        Locklass.pvMax = 130;
        Locklass.pvNow = 130;
        Locklass.atk = 85;
        Locklass.def = 80;
        Locklass.taux = 18;
        Locklass.prc = 60;
        Locklass.rare = 3;

        return Locklass;
    }

    pokemon defineInsolourdo() {
        pokemon Insolourdo;

        Insolourdo.nom = "INSOLOURDO";
        Insolourdo.type = 'R';
        Insolourdo.pvMax = 100;
        Insolourdo.pvNow = 100;
        Insolourdo.atk = 70;
        Insolourdo.def = 70;
        Insolourdo.taux = 75;
        Insolourdo.prc = 45;
        Insolourdo.rare = 3;

        return Insolourdo;
    }

    pokemon defineQwilfish() {
        pokemon Qwilfish;

        Qwilfish.nom = "QWILFISH";
        Qwilfish.type = 'W';
        Qwilfish.pvMax = 65;
        Qwilfish.pvNow = 65;
        Qwilfish.atk = 95;
        Qwilfish.def = 85;
        Qwilfish.taux = 15;
        Qwilfish.prc = 95;
        Qwilfish.rare = 2;

        return Qwilfish;
    }

    pokemon defineCaratroc() {
        pokemon Caratroc;

        Caratroc.nom = "CARATROC";
        Caratroc.type = 'R';
        Caratroc.pvMax = 20;
        Caratroc.pvNow = 20;
        Caratroc.atk = 10;
        Caratroc.def = 230;
        Caratroc.taux = 75;
        Caratroc.prc = 5;
        Caratroc.rare = 2;

        return Caratroc;
    }

    pokemon defineScarinho() {
        pokemon Scarinho;

        Scarinho.nom = "SCARINHO";
        Scarinho.type = 'G';
        Scarinho.pvMax = 80;
        Scarinho.pvNow = 80;
        Scarinho.atk = 125;
        Scarinho.def = 75;
        Scarinho.taux = 18;
        Scarinho.prc = 85;
        Scarinho.rare = 2;

        return Scarinho;
    }

    pokemon defineCorayon() {
        pokemon Corayon;

        Corayon.nom = "CORAYON";
        Corayon.type = 'W';
        Corayon.pvMax = 65;
        Corayon.pvNow = 65;
        Corayon.atk = 55;
        Corayon.def = 95;
        Corayon.taux = 25;
        Corayon.prc = 35;
        Corayon.rare = 4;

        return Corayon;
    }

    pokemon defineCadoizo() {
        pokemon Cadoizo;

        Cadoizo.nom = "CADOIZO";
        Cadoizo.type = 'W';
        Cadoizo.pvMax = 45;
        Cadoizo.pvNow = 45;
        Cadoizo.atk = 55;
        Cadoizo.def = 45;
        Cadoizo.taux = 15;
        Cadoizo.prc = 75;
        Cadoizo.rare = 4;

        return Cadoizo;
    }

    pokemon defineAirmure() {
        pokemon Airmure;

        Airmure.nom = "AIRMURE";
        Airmure.type = 'R';
        Airmure.pvMax = 65;
        Airmure.pvNow = 65;
        Airmure.atk = 80;
        Airmure.def = 140;
        Airmure.taux = 10;
        Airmure.prc = 70;
        Airmure.rare = 2;

        return Airmure;
    }

    pokemon defineQueulorior() {
        pokemon Queulorior;

        Queulorior.nom = "QUEULORIOR";
        Queulorior.type = 'N';
        Queulorior.pvMax = 55;
        Queulorior.pvNow = 55;
        Queulorior.atk = 20;
        Queulorior.def = 35;
        Queulorior.taux = 18;
        Queulorior.prc = 75;
        Queulorior.rare = 5;

        return Queulorior;
    }

    pokemon defineEcremeuh() {
        pokemon Ecremeuh;

        Ecremeuh.nom = "ECREMEUH";
        Ecremeuh.type = 'N';
        Ecremeuh.pvMax = 95;
        Ecremeuh.pvNow = 95;
        Ecremeuh.atk = 80;
        Ecremeuh.def = 100;
        Ecremeuh.taux = 15;
        Ecremeuh.prc = 100;
        Ecremeuh.rare = 2;

        return Ecremeuh;
    }

    pokemon defineTenefix() {
        pokemon Tenefix;

        Tenefix.nom = "TENEFIX";
        Tenefix.type = 'R';
        Tenefix.pvMax = 50;
        Tenefix.pvNow = 50;
        Tenefix.atk = 75;
        Tenefix.def = 75;
        Tenefix.taux = 18;
        Tenefix.prc = 50;
        Tenefix.rare = 4;

        return Tenefix;
    }

    pokemon defineMysdibule() {
        pokemon Mysdibule;

        Mysdibule.nom = "MYSDIBULE";
        Mysdibule.type = 'N';
        Mysdibule.pvMax = 50;
        Mysdibule.pvNow = 50;
        Mysdibule.atk = 85;
        Mysdibule.def = 85;
        Mysdibule.taux = 18;
        Mysdibule.prc = 50;
        Mysdibule.rare = 3;

        return Mysdibule;
    }

    pokemon definePosipi() {
        pokemon Posipi;

        Posipi.nom = "POSIPI";
        Posipi.type = 'E';
        Posipi.pvMax = 60;
        Posipi.pvNow = 60;
        Posipi.atk = 50;
        Posipi.def = 40;
        Posipi.taux = 80;
        Posipi.prc = 95;
        Posipi.rare = 3;

        return Posipi;
    }

    pokemon defineNegapi() {
        pokemon Negapi;

        Negapi.nom = "NEGAPI";
        Negapi.type = 'E';
        Negapi.pvMax = 60;
        Negapi.pvNow = 60;
        Negapi.atk = 50;
        Negapi.def = 40;
        Negapi.taux = 80;
        Negapi.prc = 95;
        Negapi.rare = 3;

        return Negapi;
    }

    pokemon defineMuciole() {
        pokemon Muciole;

        Muciole.nom = "MUCIOLE";
        Muciole.type = 'G';
        Muciole.pvMax = 65;
        Muciole.pvNow = 65;
        Muciole.atk = 75;
        Muciole.def = 75;
        Muciole.taux = 60;
        Muciole.prc = 85;
        Muciole.rare = 2;

        return Muciole;
    }

    pokemon defineLumivole() {
        pokemon Lumivole;

        Lumivole.nom = "LUMIVOLE";
        Lumivole.type = 'G';
        Lumivole.pvMax = 65;
        Lumivole.pvNow = 65;
        Lumivole.atk = 75;
        Lumivole.def = 75;
        Lumivole.taux = 60;
        Lumivole.prc = 85;
        Lumivole.rare = 2;

        return Lumivole;
    }

    pokemon defineChartor() {
        pokemon Chartor;

        Chartor.nom = "CHARTOR";
        Chartor.type = 'F';
        Chartor.pvMax = 70;
        Chartor.pvNow = 70;
        Chartor.atk = 85;
        Chartor.def = 140;
        Chartor.taux = 35;
        Chartor.prc = 20;
        Chartor.rare = 2;

        return Chartor;
    }


    pokemon defineSpinda() {
        pokemon Spinda;

        Spinda.nom = "SPINDA";
        Spinda.type = 'N';
        Spinda.pvMax = 60;
        Spinda.pvNow = 60;
        Spinda.atk = 60;
        Spinda.def = 60;
        Spinda.taux = 60;
        Spinda.prc = 60;
        Spinda.rare = 3;

        return Spinda;
    }

    pokemon defineMangriff() {
        pokemon Mangriff;

        Mangriff.nom = "MANGRIFF";
        Mangriff.type = 'N';
        Mangriff.pvMax = 73;
        Mangriff.pvNow = 73;
        Mangriff.atk = 115;
        Mangriff.def = 60;
        Mangriff.taux = 35;
        Mangriff.prc = 90;
        Mangriff.rare = 2;

        return Mangriff;
    }

    pokemon defineSeviper() {
        pokemon Seviper;

        Seviper.nom = "SEVIPER";
        Seviper.type = 'N';
        Seviper.pvMax = 73;
        Seviper.pvNow = 73;
        Seviper.atk = 115;
        Seviper.def = 60;
        Seviper.taux = 35;
        Seviper.prc = 65;
        Seviper.rare = 3;

        return Seviper;
    }

    pokemon defineSeleroc() {
        pokemon Seleroc;

        Seleroc.nom = "SELEROC";
        Seleroc.type = 'R';
        Seleroc.pvMax = 90;
        Seleroc.pvNow = 90;
        Seleroc.atk = 55;
        Seleroc.def = 65;
        Seleroc.taux = 15;
        Seleroc.prc = 70;
        Seleroc.rare = 4;

        return Seleroc;
    }

    pokemon defineSolaroc() {
        pokemon Solaroc;

        Solaroc.nom = "SOLAROC";
        Solaroc.type = 'R';
        Solaroc.pvMax = 90;
        Solaroc.pvNow = 90;
        Solaroc.atk = 55;
        Solaroc.def = 65;
        Solaroc.taux = 15;
        Solaroc.prc = 70;
        Solaroc.rare = 2;

        return Solaroc;
    }

    pokemon defineMorpheo() {
        pokemon Morpheo;

        Morpheo.nom = "MORPHEO";
        Morpheo.type = 'N';
        Morpheo.pvMax = 70;
        Morpheo.pvNow = 70;
        Morpheo.atk = 70;
        Morpheo.def = 70;
        Morpheo.taux = 70;
        Morpheo.prc = 70;
        Morpheo.rare = 2;

        return Morpheo;
    }

    pokemon defineKecleon() {
        pokemon Kecleon;

        Kecleon.nom = "KECLEON";
        Kecleon.type = 'N';
        Kecleon.pvMax = 60;
        Kecleon.pvNow = 60;
        Kecleon.atk = 90;
        Kecleon.def = 70;
        Kecleon.taux = 80;
        Kecleon.prc = 40;
        Kecleon.rare = 2;

        return Kecleon;
    }

    pokemon defineTropius() {
        pokemon Tropius;

        Tropius.nom = "TROPIUS";
        Tropius.type = 'G';
        Tropius.pvMax = 99;
        Tropius.pvNow = 99;
        Tropius.atk = 58;
        Tropius.def = 83;
        Tropius.taux = 78;
        Tropius.prc = 51;
        Tropius.rare = 3;

        return Tropius;
    }

    pokemon defineAbsol() {
        pokemon Absol;

        Absol.nom = "ABSOL";
        Absol.type = 'N';
        Absol.pvMax = 65;
        Absol.pvNow = 65;
        Absol.atk = 130;
        Absol.def = 60;
        Absol.taux = 12;
        Absol.prc = 75;
        Absol.rare = 3;

        return Absol;
    }

    pokemon defineRelicanth() {
        pokemon Relicanth;

        Relicanth.nom = "RELICANTH";
        Relicanth.type = 'W';
        Relicanth.pvMax = 100;
        Relicanth.pvNow = 100;
        Relicanth.atk = 90;
        Relicanth.def = 100;
        Relicanth.taux = 10;
        Relicanth.prc = 55;
        Relicanth.rare = 3;

        return Relicanth;
    }

    pokemon defineLovdisc() {
        pokemon Lovdisc;

        Lovdisc.nom = "LOVDISC";
        Lovdisc.type = 'W';
        Lovdisc.pvMax = 43;
        Lovdisc.pvNow = 43;
        Lovdisc.atk = 30;
        Lovdisc.def = 55;
        Lovdisc.taux = 88;
        Lovdisc.prc = 97;
        Lovdisc.rare = 3;

        return Lovdisc;
    }


    pokemon definePachirisu() {
        pokemon Pachirisu;

        Pachirisu.nom = "PACHIRISU";
        Pachirisu.type = 'E';
        Pachirisu.pvMax = 60;
        Pachirisu.pvNow = 60;
        Pachirisu.atk = 90;
        Pachirisu.def = 70;
        Pachirisu.taux = 80;
        Pachirisu.prc = 95;
        Pachirisu.rare = 2;

        return Pachirisu;
    }

    pokemon definePijako() {
        pokemon Pijako;

        Pijako.nom = "PIJAKO";
        Pijako.type = 'N';
        Pijako.pvMax = 76;
        Pijako.pvNow = 76;
        Pijako.atk = 45;
        Pijako.def = 70;
        Pijako.taux = 75;
        Pijako.prc = 91;
        Pijako.rare = 2;

        return Pijako;
    }

    pokemon defineSpiritomb() {
        pokemon Spiritomb;

        Spiritomb.nom = "SPIRITOMB";
        Spiritomb.type = 'R';
        Spiritomb.pvMax = 108;
        Spiritomb.pvNow = 108;
        Spiritomb.atk = 92;
        Spiritomb.def = 108;
        Spiritomb.taux = 39;
        Spiritomb.prc = 35;
        Spiritomb.rare = 3;

        return Spiritomb;
    }

    pokemon defineVortente() {
        pokemon Vortente;

        Vortente.nom = "VORTENTE";
        Vortente.type = 'G';
        Vortente.pvMax = 74;
        Vortente.pvNow = 74;
        Vortente.atk = 100;
        Vortente.def = 72;
        Vortente.taux = 78;
        Vortente.prc = 46;
        Vortente.rare = 2;

        return Vortente;
    }

    pokemon defineMotisma() {
        pokemon Motisma;

        Motisma.nom = "MOTISMA";
        Motisma.type = 'N';
        Motisma.pvMax = 50;
        Motisma.pvNow = 50;
        Motisma.atk = 65;
        Motisma.def = 107;
        Motisma.taux = 15;
        Motisma.prc = 91;
        Motisma.rare = 3;

        return Motisma;
    }

    pokemon defineNanmeouie() {
        pokemon Nanmeouie;

        Nanmeouie.nom = "NANMEOUIE";
        Nanmeouie.type = 'N';
        Nanmeouie.pvMax = 103;
        Nanmeouie.pvNow = 103;
        Nanmeouie.atk = 60;
        Nanmeouie.def = 86;
        Nanmeouie.taux = 100;
        Nanmeouie.prc = 50;
        Nanmeouie.rare = 2;

        return Nanmeouie;
    }

    pokemon defineJudokrak() {
        pokemon Judokrak;

        Judokrak.nom = "JUDOKRAK";
        Judokrak.type = 'R';
        Judokrak.pvMax = 120;
        Judokrak.pvNow = 120;
        Judokrak.atk = 100;
        Judokrak.def = 85;
        Judokrak.taux = 18;
        Judokrak.prc = 45;
        Judokrak.rare = 2;

        return Judokrak;
    }

    pokemon defineKaraclee() {
        pokemon Karaclee;

        Karaclee.nom = "KARACLEE";
        Karaclee.type = 'R';
        Karaclee.pvMax = 75;
        Karaclee.pvNow = 75;
        Karaclee.atk = 125;
        Karaclee.def = 75;
        Karaclee.taux = 18;
        Karaclee.prc = 85;
        Karaclee.rare = 3;

        return Karaclee;
    }

    pokemon defineBargantua() {
        pokemon Bargantua;

        Bargantua.nom = "BARGANTUA";
        Bargantua.type = 'W';
        Bargantua.pvMax = 70;
        Bargantua.pvNow = 70;
        Bargantua.atk = 95;
        Bargantua.def = 65;
        Bargantua.taux = 25;
        Bargantua.prc = 98;
        Bargantua.rare = 3;

        return Bargantua;
    }

    pokemon defineMaracachi() {
        pokemon Maracachi;

        Maracachi.nom = "MARACACHI";
        Maracachi.type = 'G';
        Maracachi.pvMax = 75;
        Maracachi.pvNow = 75;
        Maracachi.atk = 60;
        Maracachi.def = 86;
        Maracachi.taux = 67;
        Maracachi.prc = 80;
        Maracachi.rare = 3;

        return Maracachi;
    }

    pokemon defineCryptero() {
        pokemon Cryptero;

        Cryptero.nom = "CRYPTERO";
        Cryptero.type = 'F';
        Cryptero.pvMax = 72;
        Cryptero.pvNow = 72;
        Cryptero.atk = 58;
        Cryptero.def = 80;
        Cryptero.taux = 18;
        Cryptero.prc = 97;
        Cryptero.rare = 4;

        return Cryptero;
    }

    pokemon defineEmolga() {
        pokemon Emolga;

        Emolga.nom = "EMOLGA";
        Emolga.type = 'E';
        Emolga.pvMax = 55;
        Emolga.pvNow = 55;
        Emolga.atk = 75;
        Emolga.def = 60;
        Emolga.taux = 80;
        Emolga.prc = 103;
        Emolga.rare = 3;

        return Emolga;
    }

    pokemon defineMamanbo() {
        pokemon Mamanbo;

        Mamanbo.nom = "MAMANBO";
        Mamanbo.type = 'W';
        Mamanbo.pvMax = 165;
        Mamanbo.pvNow = 165;
        Mamanbo.atk = 75;
        Mamanbo.def = 80;
        Mamanbo.taux = 30;
        Mamanbo.prc = 65;
        Mamanbo.rare = 1;

        return Mamanbo;
    }

    pokemon defineHexagel() {
        pokemon Hexagel;

        Hexagel.nom = "HEXAGEL";
        Hexagel.type = 'W';
        Hexagel.pvMax = 80;
        Hexagel.pvNow = 80;
        Hexagel.atk = 50;
        Hexagel.def = 30;
        Hexagel.taux = 10;
        Hexagel.prc = 105;
        Hexagel.rare = 5;

        return Hexagel;
    }

    pokemon defineLimonde() {
        pokemon Limonde;

        Limonde.nom = "LIMONDE";
        Limonde.type = 'R';
        Limonde.pvMax = 109;
        Limonde.pvNow = 109;
        Limonde.atk = 66;
        Limonde.def = 84;
        Limonde.taux = 30;
        Limonde.prc = 32;
        Limonde.rare = 3;

        return Limonde;
    }

    pokemon defineDrakkarmin() {
        pokemon Drakkarmin;

        Drakkarmin.nom = "DRAKKARMIN";
        Drakkarmin.type = 'R';
        Drakkarmin.pvMax = 77;
        Drakkarmin.pvNow = 77;
        Drakkarmin.atk = 120;
        Drakkarmin.def = 90;
        Drakkarmin.taux = 18;
        Drakkarmin.prc = 48;
        Drakkarmin.rare = 3;

        return Drakkarmin;
    }

    pokemon defineFrison() {
        pokemon Frison;

        Frison.nom = "FRISON";
        Frison.type = 'N';
        Frison.pvMax = 95;
        Frison.pvNow = 95;
        Frison.atk = 110;
        Frison.def = 95;
        Frison.taux = 18;
        Frison.prc = 55;
        Frison.rare = 3;

        return Frison;
    }

    pokemon defineAflamanoir() {
        pokemon Aflamanoir;

        Aflamanoir.nom = "AFLAMANOIR";
        Aflamanoir.type = 'F';
        Aflamanoir.pvMax = 85;
        Aflamanoir.pvNow = 85;
        Aflamanoir.atk = 97;
        Aflamanoir.def = 66;
        Aflamanoir.taux = 35;
        Aflamanoir.prc = 65;
        Aflamanoir.rare = 3;

        return Aflamanoir;
    }

    pokemon defineFermite() {
        pokemon Fermite;

        Fermite.nom = "FERMITE";
        Fermite.type = 'G';
        Fermite.pvMax = 58;
        Fermite.pvNow = 58;
        Fermite.atk = 109;
        Fermite.def = 112;
        Fermite.taux = 35;
        Fermite.prc = 109;
        Fermite.rare = 2;

        return Fermite;
    }

    pokemon defineCouafarel() {
        pokemon Couafarel;

        Couafarel.nom = "COUAFAREL";
        Couafarel.type = 'N';
        Couafarel.pvMax = 75;
        Couafarel.pvNow = 75;
        Couafarel.atk = 80;
        Couafarel.def = 60;
        Couafarel.taux = 47;
        Couafarel.prc = 102;
        Couafarel.rare = 3;

        return Couafarel;
    }

    pokemon defineBrutalibre() {
        pokemon Brutalibre;

        Brutalibre.nom = "BRUTALIBRE";
        Brutalibre.type = 'N';
        Brutalibre.pvMax = 78;
        Brutalibre.pvNow = 78;
        Brutalibre.atk = 92;
        Brutalibre.def = 75;
        Brutalibre.taux = 39;
        Brutalibre.prc = 115;
        Brutalibre.rare = 3;

        return Brutalibre;
    }

    pokemon defineDedenne() {
        pokemon Dedenne;

        Dedenne.nom = "DEDENNE";
        Dedenne.type = 'E';
        Dedenne.pvMax = 67;
        Dedenne.pvNow = 67;
        Dedenne.atk = 60;
        Dedenne.def = 60;
        Dedenne.taux = 75;
        Dedenne.prc = 101;
        Dedenne.rare = 3;

        return Dedenne;
    }

    pokemon defineStrassie() {
        pokemon Strassie;

        Strassie.nom = "STRASSIE";
        Strassie.type = 'R';
        Strassie.pvMax = 50;
        Strassie.pvNow = 50;
        Strassie.atk = 50;
        Strassie.def = 150;
        Strassie.taux = 15;
        Strassie.prc = 50;
        Strassie.rare = 4;

        return Strassie;
    }

    pokemon defineTrousselin() {
        pokemon Trousselin;

        Trousselin.nom = "TROUSSELIN";
        Trousselin.type = 'F';
        Trousselin.pvMax = 57;
        Trousselin.pvNow = 57;
        Trousselin.atk = 80;
        Trousselin.def = 91;
        Trousselin.taux = 29;
        Trousselin.prc = 75;
        Trousselin.rare = 4;

        return Trousselin;
    }

    pokemon defineBrocelome() {
        pokemon Brocelome;

        Brocelome.nom = "BROCELOME";
        Brocelome.type = 'G';
        Brocelome.pvMax = 43;
        Brocelome.pvNow = 43;
        Brocelome.atk = 70;
        Brocelome.def = 48;
        Brocelome.taux = 50;
        Brocelome.prc = 38;
        Brocelome.rare = 6;

        return Brocelome;
    }


    pokemon definePlumeline() {
        pokemon Plumeline;

        Plumeline.nom = "PLUMELINE";
        Plumeline.type = 'F';
        Plumeline.pvMax = 75;
        Plumeline.pvNow = 75;
        Plumeline.atk = 70;
        Plumeline.def = 70;
        Plumeline.taux = 20;
        Plumeline.prc = 93;
        Plumeline.rare = 4;

        return Plumeline;
    }

    pokemon defineFroussardine() {
        pokemon Froussardine;

        Froussardine.nom = "FROUSSARDINE";
        Froussardine.type = 'W';
        Froussardine.pvMax = 45;
        Froussardine.pvNow = 45;
        Froussardine.atk = 20;
        Froussardine.def = 20;
        Froussardine.taux = 60;
        Froussardine.prc = 40;
        Froussardine.rare = 7;

        return Froussardine;
    }

    pokemon defineGuerilande() {
        pokemon Guerilande;

        Guerilande.nom = "GUERILANDE";
        Guerilande.type = 'G';
        Guerilande.pvMax = 51;
        Guerilande.pvNow = 51;
        Guerilande.atk = 52;
        Guerilande.def = 90;
        Guerilande.taux = 24;
        Guerilande.prc = 100;
        Guerilande.rare = 4;

        return Guerilande;
    }

    pokemon defineGouroutan() {
        pokemon Gouroutan;

        Gouroutan.nom = "GOUROUTAN";
        Gouroutan.type = 'G';
        Gouroutan.pvMax = 90;
        Gouroutan.pvNow = 90;
        Gouroutan.atk = 60;
        Gouroutan.def = 80;
        Gouroutan.taux = 18;
        Gouroutan.prc = 60;
        Gouroutan.rare = 4;

        return Gouroutan;
    }

    pokemon defineQuartermac() {
        pokemon Quartermac;

        Quartermac.nom = "QUARTERMAC";
        Quartermac.type = 'G';
        Quartermac.pvMax = 100;
        Quartermac.pvNow = 100;
        Quartermac.atk = 120;
        Quartermac.def = 90;
        Quartermac.taux = 18;
        Quartermac.prc = 80;
        Quartermac.rare = 2;

        return Quartermac;
    }

    pokemon defineConcombaffe() {
        pokemon Concombaffe;

        Concombaffe.nom = "CONCOMBAFFE";
        Concombaffe.type = 'W';
        Concombaffe.pvMax = 55;
        Concombaffe.pvNow = 55;
        Concombaffe.atk = 60;
        Concombaffe.def = 130;
        Concombaffe.taux = 60;
        Concombaffe.prc = 5;
        Concombaffe.rare = 4;

        return Concombaffe;
    }

    pokemon defineMeteno() {
        pokemon Meteno;

        Meteno.nom = "METENO";
        Meteno.type = 'R';
        Meteno.pvMax = 60;
        Meteno.pvNow = 60;
        Meteno.atk = 100;
        Meteno.def = 60;
        Meteno.taux = 80;
        Meteno.prc = 120;
        Meteno.rare = 2;

        return Meteno;
    }


    pokemon defineDodoala() {
        pokemon Dodoala;

        Dodoala.nom = "DODOALA";
        Dodoala.type = 'N';
        Dodoala.pvMax = 65;
        Dodoala.pvNow = 65;
        Dodoala.atk = 115;
        Dodoala.def = 65;
        Dodoala.taux = 45;
        Dodoala.prc = 65;
        Dodoala.rare = 3;

        return Dodoala;
    }

    pokemon defineBoumata() {
        pokemon Boumata;

        Boumata.nom = "BOUMATA";
        Boumata.type = 'F';
        Boumata.pvMax = 60;
        Boumata.pvNow = 60;
        Boumata.atk = 78;
        Boumata.def = 135;
        Boumata.taux = 30;
        Boumata.prc = 36;
        Boumata.rare = 4;

        return Boumata;
    }

    pokemon defineTogedemaru() {
        pokemon Togedemaru;

        Togedemaru.nom = "TOGEDEMARU";
        Togedemaru.type = 'E';
        Togedemaru.pvMax = 65;
        Togedemaru.pvNow = 65;
        Togedemaru.atk = 98;
        Togedemaru.def = 63;
        Togedemaru.taux = 70;
        Togedemaru.prc = 96;
        Togedemaru.rare = 3;

        return Togedemaru;
    }

    pokemon defineMimiqui() {
        pokemon Mimiqui;

        Mimiqui.nom = "MIMIQUI";
        Mimiqui.type = 'N';
        Mimiqui.pvMax = 55;
        Mimiqui.pvNow = 55;
        Mimiqui.atk = 90;
        Mimiqui.def = 80;
        Mimiqui.taux = 17;
        Mimiqui.prc = 96;
        Mimiqui.rare = 4;

        return Mimiqui;
    }

    pokemon defineDenticrisse() {
        pokemon Denticrisse;

        Denticrisse.nom = "DENTICRISSE";
        Denticrisse.type = 'W';
        Denticrisse.pvMax = 68;
        Denticrisse.pvNow = 68;
        Denticrisse.atk = 105;
        Denticrisse.def = 70;
        Denticrisse.taux = 30;
        Denticrisse.prc = 92;
        Denticrisse.rare = 3;

        return Denticrisse;
    }

    pokemon defineDraieul() {
        pokemon Draieul;

        Draieul.nom = "DRAIEUL";
        Draieul.type = 'N';
        Draieul.pvMax = 78;
        Draieul.pvNow = 78;
        Draieul.atk = 60;
        Draieul.def = 85;
        Draieul.taux = 30;
        Draieul.prc = 36;
        Draieul.rare = 4;

        return Draieul;
    }

    pokemon defineSinistrail() {
        pokemon Sinistrail;

        Sinistrail.nom = "SINISTRAIL";
        Sinistrail.type = 'G';
        Sinistrail.pvMax = 70;
        Sinistrail.pvNow = 70;
        Sinistrail.atk = 131;
        Sinistrail.def = 100;
        Sinistrail.taux = 10;
        Sinistrail.prc = 40;
        Sinistrail.rare = 3;

        return Sinistrail;
    }

    pokemon defineKatagami() {
        pokemon Katagami;

        Katagami.nom = "KATAGAMI";
        Katagami.type = 'G';
        Katagami.pvMax = 59;
        Katagami.pvNow = 59;
        Katagami.atk = 181;
        Katagami.def = 131;
        Katagami.taux = 3;
        Katagami.prc = 109;
        Katagami.rare = 1;

        return Katagami;
    }

    pokemon defineNigosier() {
        pokemon Nigosier;

        Nigosier.nom = "NIGOSIER";
        Nigosier.type = 'W';
        Nigosier.pvMax = 70;
        Nigosier.pvNow = 70;
        Nigosier.atk = 85;
        Nigosier.def = 55;
        Nigosier.taux = 18;
        Nigosier.prc = 85;
        Nigosier.rare = 4;

        return Nigosier;
    }

    pokemon defineHexadron() {
        pokemon Hexadron;

        Hexadron.nom = "HEXADRON";
        Hexadron.type = 'R';
        Hexadron.pvMax = 65;
        Hexadron.pvNow = 65;
        Hexadron.atk = 100;
        Hexadron.def = 100;
        Hexadron.taux = 18;
        Hexadron.prc = 75;
        Hexadron.rare = 3;

        return Hexadron;
    }

    pokemon defineWimessir() {
        pokemon Wimessir;

        Wimessir.nom = "WIMESSIR";
        Wimessir.type = 'N';
        Wimessir.pvMax = 65;
        Wimessir.pvNow = 65;
        Wimessir.atk = 60;
        Wimessir.def = 60;
        Wimessir.taux = 12;
        Wimessir.prc = 90;
        Wimessir.rare = 5;

        return Wimessir;
    }

    pokemon defineDuralugon() {
        pokemon Duralugon;

        Duralugon.nom = "DURALUGON";
        Duralugon.type = 'R';
        Duralugon.pvMax = 70;
        Duralugon.pvNow = 70;
        Duralugon.atk = 95;
        Duralugon.def = 115;
        Duralugon.taux = 18;
        Duralugon.prc = 85;
        Duralugon.rare = 3;

        return Duralugon;
    }

    pokemon defineWattapik() {
        pokemon Wattapik;

        Wattapik.nom = "WATTAPIK";
        Wattapik.type = 'E';
        Wattapik.pvMax = 48;
        Wattapik.pvNow = 48;
        Wattapik.atk = 100;
        Wattapik.def = 95;
        Wattapik.taux = 75;
        Wattapik.prc = 15;
        Wattapik.rare = 4;

        return Wattapik;
    }

    pokemon defineDolman() {
        pokemon Dolman;

        Dolman.nom = "DOLMAN";
        Dolman.type = 'R';
        Dolman.pvMax = 100;
        Dolman.pvNow = 100;
        Dolman.atk = 20;
        Dolman.def = 20;
        Dolman.taux = 25;
        Dolman.prc = 70;
        Dolman.rare = 5;

        return Dolman;
    }

    pokemon defineBekaglacon() {
        pokemon Bekaglacon;

        Bekaglacon.nom = "BEKAGLACON";
        Bekaglacon.type = 'W';
        Bekaglacon.pvMax = 75;
        Bekaglacon.pvNow = 75;
        Bekaglacon.atk = 80;
        Bekaglacon.def = 110;
        Bekaglacon.taux = 60;
        Bekaglacon.prc = 130;
        Bekaglacon.rare = 2;

        return Bekaglacon;
    }

    pokemon defineMorpeko() {
        pokemon Morpeko;

        Morpeko.nom = "MORPEKO";
        Morpeko.type = 'E';
        Morpeko.pvMax = 58;
        Morpeko.pvNow = 58;
        Morpeko.atk = 95;
        Morpeko.def = 60;
        Morpeko.taux = 70;
        Morpeko.prc = 97;
        Morpeko.rare = 3;

        return Morpeko;
    }

    pokemon defineTapatoes() {
        pokemon Tapatoes;

        Tapatoes.nom = "TAPATOES";
        Tapatoes.type = 'N';
        Tapatoes.pvMax = 82;
        Tapatoes.pvNow = 82;
        Tapatoes.atk = 96;
        Tapatoes.def = 51;
        Tapatoes.taux = 74;
        Tapatoes.prc = 92;
        Tapatoes.rare = 3;

        return Tapatoes;
    }

    pokemon defineCraparoi() {
        pokemon Craparoi;

        Craparoi.nom = "CRAPAROI";
        Craparoi.type = 'R';
        Craparoi.pvMax = 70;
        Craparoi.pvNow = 70;
        Craparoi.atk = 100;
        Craparoi.def = 115;
        Craparoi.taux = 47;
        Craparoi.prc = 75;
        Craparoi.rare = 3;

        return Craparoi;
    }

    pokemon defineLestombaile() {
        pokemon Lestombaile;

        Lestombaile.nom = "LESTOMBAILE";
        Lestombaile.type = 'N';
        Lestombaile.pvMax = 70;
        Lestombaile.pvNow = 70;
        Lestombaile.atk = 103;
        Lestombaile.def = 85;
        Lestombaile.taux = 10;
        Lestombaile.prc = 82;
        Lestombaile.rare = 3;

        return Lestombaile;
    }

    pokemon defineFerdeter() {
        pokemon Ferdeter;

        Ferdeter.nom = "FERDETER";
        Ferdeter.type = 'R';
        Ferdeter.pvMax = 70;
        Ferdeter.pvNow = 70;
        Ferdeter.atk = 85;
        Ferdeter.def = 145;
        Ferdeter.taux = 10;
        Ferdeter.prc = 65;
        Ferdeter.rare = 3;

        return Ferdeter;
    }

    pokemon defineFlamenroule() {
        pokemon Flamenroule;

        Flamenroule.nom = "FLAMENROULE";
        Flamenroule.type = 'F';
        Flamenroule.pvMax = 82;
        Flamenroule.pvNow = 82;
        Flamenroule.atk = 115;
        Flamenroule.def = 74;
        Flamenroule.taux = 39;
        Flamenroule.prc = 90;
        Flamenroule.rare = 2;

        return Flamenroule;
    }

    pokemon defineDelestin() {
        pokemon Delestin;

        Delestin.nom = "DELESTIN";
        Delestin.type = 'W';
        Delestin.pvMax = 90;
        Delestin.pvNow = 90;
        Delestin.atk = 102;
        Delestin.def = 73;
        Delestin.taux = 39;
        Delestin.prc = 70;
        Delestin.rare = 3;

        return Delestin;
    }

    pokemon defineOyacata() {
        pokemon Oyacata;

        Oyacata.nom = "OYACATA";
        Oyacata.type = 'W';
        Oyacata.pvMax = 150;
        Oyacata.pvNow = 150;
        Oyacata.atk = 100;
        Oyacata.def = 115;
        Oyacata.taux = 10;
        Oyacata.prc = 35;
        Oyacata.rare = 1;

        return Oyacata;
    }

    pokemon defineNigirigon() {
        pokemon Nigirigon;

        Nigirigon.nom = "NIGIRIGON";
        Nigirigon.type = 'W';
        Nigirigon.pvMax = 68;
        Nigirigon.pvNow = 68;
        Nigirigon.atk = 50;
        Nigirigon.def = 60;
        Nigirigon.taux = 39;
        Nigirigon.prc = 82;
        Nigirigon.rare = 4;

        return Nigirigon;
    }

    pokemon defineMotorizard() {
        pokemon Motorizard;

        Motorizard.nom = "MOTORIZARD";
        Motorizard.type = 'N';
        Motorizard.pvMax = 70;
        Motorizard.pvNow = 70;
        Motorizard.atk = 95;
        Motorizard.def = 65;
        Motorizard.taux = 74;
        Motorizard.prc = 121;
        Motorizard.rare = 2;

        return Motorizard;
    }

    pokemon defineChongjian() {
        pokemon Chongjian;

        Chongjian.nom = "CHONGJIAN";
        Chongjian.type = 'G';
        Chongjian.pvMax = 85;
        Chongjian.pvNow = 85;
        Chongjian.atk = 85;
        Chongjian.def = 100;
        Chongjian.taux = 2;
        Chongjian.prc = 70;
        Chongjian.rare = 3;

        return Chongjian;
    }

    pokemon defineBaojian() {
        pokemon Baojian;

        Baojian.nom = "BAOJIAN";
        Baojian.type = 'W';
        Baojian.pvMax = 80;
        Baojian.pvNow = 80;
        Baojian.atk = 120;
        Baojian.def = 80;
        Baojian.taux = 2;
        Baojian.prc = 135;
        Baojian.rare = 2;

        return Baojian;
    }

    pokemon defineDinglu() {
        pokemon Dinglu;

        Dinglu.nom = "DINGLU";
        Dinglu.type = 'R';
        Dinglu.pvMax = 155;
        Dinglu.pvNow = 155;
        Dinglu.atk = 110;
        Dinglu.def = 125;
        Dinglu.taux = 2;
        Dinglu.prc = 45;
        Dinglu.rare = 1;

        return Dinglu;
    }

    pokemon defineYuyu() {
        pokemon Yuyu;

        Yuyu.nom = "YUYU";
        Yuyu.type = 'F';
        Yuyu.pvMax = 55;
        Yuyu.pvNow = 55;
        Yuyu.atk = 80;
        Yuyu.def = 80;
        Yuyu.taux = 2;
        Yuyu.prc = 100;
        Yuyu.rare = 4;

        return Yuyu;
    }

    pokemon defineRugitLune() {
        pokemon RugitLune;

        RugitLune.nom = "RUGIT-LUNE";
        RugitLune.type = 'R';
        RugitLune.pvMax = 105;
        RugitLune.pvNow = 105;
        RugitLune.atk = 139;
        RugitLune.def = 71;
        RugitLune.taux = 6;
        RugitLune.prc = 119;
        RugitLune.rare = 1;

        return RugitLune;
    }

    pokemon defineGardeDeFer() {
        pokemon GardeDeFer;

        GardeDeFer.nom = "GARDE-DE-FER";
        GardeDeFer.type = 'R';
        GardeDeFer.pvMax = 74;
        GardeDeFer.pvNow = 74;
        GardeDeFer.atk = 130;
        GardeDeFer.def = 90;
        GardeDeFer.taux = 6;
        GardeDeFer.prc = 116;
        GardeDeFer.rare = 2;

        return GardeDeFer;
    }

}

#endif
