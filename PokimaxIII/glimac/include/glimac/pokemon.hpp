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
    }pokemon;

    pokemon definePikachu() {
        pokemon Pikachu;

        Pikachu.nom = "PIKACHU";
        Pikachu.type = 'E';
        Pikachu.pvMax = 100;
        Pikachu.pvNow = 100;
        Pikachu.atk = 70;
        Pikachu.def = 70;
        Pikachu.taux = 80;

        return Pikachu;
    }


    pokemon defineCanarticho() {
        pokemon Canarticho;

        Canarticho.nom = "CANARTICHO";
        Canarticho.type = 'N';
        Canarticho.pvMax = 100;
        Canarticho.pvNow = 100;
        Canarticho.atk = 90;
        Canarticho.def = 55;
        Canarticho.taux = 75;

        return Canarticho;
    }

    pokemon defineInsolourdo(){
        pokemon Insolourdo;

        Insolourdo.nom = "INSOLOURDO";
        Insolourdo.type = 'R';
        Insolourdo.pvMax = 100;
        Insolourdo.pvNow = 100;
        Insolourdo.atk = 70;
        Insolourdo.def = 70;
        Insolourdo.taux = 75;

        return Insolourdo;
    }

    pokemon defineQwilfish() {
        pokemon Qwilfish;

        Qwilfish.nom = "QWILFISH";
        Qwilfish.type = 'W';
        Qwilfish.pvMax = 100;
        Qwilfish.pvNow = 100;
        Qwilfish.atk = 95;
        Qwilfish.def = 85;
        Qwilfish.taux = 15;

        return Qwilfish;
    }

    pokemon defineCaratroc() {
        pokemon Caratroc;

        Caratroc.nom = "CARATROC";
        Caratroc.type = 'R';
        Caratroc.pvMax = 100;
        Caratroc.pvNow = 100;
        Caratroc.atk = 10;
        Caratroc.def = 230;
        Caratroc.taux = 75;

        return Caratroc;
    }

    pokemon defineCorayon() {
        pokemon Corayon;

        Corayon.nom = "CORAYON";
        Corayon.type = 'W';
        Corayon.pvMax = 100;
        Corayon.pvNow = 100;
        Corayon.atk = 55;
        Corayon.def = 95;
        Corayon.taux = 25;

        return Corayon;
    }

    pokemon defineCadoizo() {
        pokemon Cadoizo;

        Cadoizo.nom = "CADOIZO";
        Cadoizo.type = 'W';
        Cadoizo.pvMax = 100;
        Cadoizo.pvNow = 100;
        Cadoizo.atk = 55;
        Cadoizo.def = 45;
        Cadoizo.taux = 15;

        return Cadoizo;
    }

    pokemon defineAirmure() {
        pokemon Airmure;

        Airmure.nom = "AIRMURE";
        Airmure.type = 'R';
        Airmure.pvMax = 100;
        Airmure.pvNow = 100;
        Airmure.atk = 80;
        Airmure.def = 140;
        Airmure.taux = 10;

        return Airmure;
    }

    pokemon defineEcremeuh() {
        pokemon Ecremeuh;

        Ecremeuh.nom = "ECREMEUH";
        Ecremeuh.type = 'N';
        Ecremeuh.pvMax = 100;
        Ecremeuh.pvNow = 100;
        Ecremeuh.atk = 80;
        Ecremeuh.def = 100;
        Ecremeuh.taux = 15;

        return Ecremeuh;
    }

    pokemon definePosipi() {
        pokemon Posipi;

        Posipi.nom = "POSIPI";
        Posipi.type = 'E';
        Posipi.pvMax = 100;
        Posipi.pvNow = 100;
        Posipi.atk = 50;
        Posipi.def = 40;
        Posipi.taux = 80;

        return Posipi;
    }

    pokemon defineNegapi() {
        pokemon Negapi;

        Negapi.nom = "NEGAPI";
        Negapi.type = 'E';
        Negapi.pvMax = 100;
        Negapi.pvNow = 100;
        Negapi.atk = 50;
        Negapi.def = 40;
        Negapi.taux = 80;

        return Negapi;
    }

    pokemon defineMuciole() {
        pokemon Muciole;

        Muciole.nom = "MUCIOLE";
        Muciole.type = 'G';
        Muciole.pvMax = 100;
        Muciole.pvNow = 100;
        Muciole.atk = 75;
        Muciole.def = 75;
        Muciole.taux = 60;

        return Muciole;
    }

    pokemon defineLumivole() {
        pokemon Lumivole;

        Lumivole.nom = "LUMIVOLE";
        Lumivole.type = 'G';
        Lumivole.pvMax = 100;
        Lumivole.pvNow = 100;
        Lumivole.atk = 75;
        Lumivole.def = 75;
        Lumivole.taux = 60;

        return Lumivole;
    }

    pokemon defineChartor() {
        pokemon Chartor;

        Chartor.nom = "CHARTOR";
        Chartor.type = 'F';
        Chartor.pvMax = 100;
        Chartor.pvNow = 100;
        Chartor.atk = 85;
        Chartor.def = 140;
        Chartor.taux = 35;

        return Chartor;
    }

    pokemon defineSpinda() {
        pokemon Spinda;

        Spinda.nom = "SPINDA";
        Spinda.type = 'N';
        Spinda.pvMax = 100;
        Spinda.pvNow = 100;
        Spinda.atk = 60;
        Spinda.def = 60;
        Spinda.taux = 60;

        return Spinda;
    }

    pokemon defineMangriff() {
        pokemon Mangriff;

        Mangriff.nom = "MANGRIFF";
        Mangriff.type = 'N';
        Mangriff.pvMax = 100;
        Mangriff.pvNow = 100;
        Mangriff.atk = 115;
        Mangriff.def = 60;
        Mangriff.taux = 35;

        return Mangriff;
    }

    pokemon defineSeviper() {
        pokemon Seviper;

        Seviper.nom = "SEVIPER";
        Seviper.type = 'N';
        Seviper.pvMax = 100;
        Seviper.pvNow = 100;
        Seviper.atk = 115;
        Seviper.def = 60;
        Seviper.taux = 35;

        return Seviper;
    }

    pokemon defineSeleroc() {

        pokemon Seleroc;

        Seleroc.nom = "SELEROC";
        Seleroc.type = 'R';
        Seleroc.pvMax = 100;
        Seleroc.pvNow = 100;
        Seleroc.atk = 55;
        Seleroc.def = 65;
        Seleroc.taux = 15;

        return Seleroc;
    }

    pokemon defineSolaroc() {

        pokemon Solaroc;

        Solaroc.nom = "SOLAROC";
        Solaroc.type = 'R';
        Solaroc.pvMax = 100;
        Solaroc.pvNow = 100;
        Solaroc.atk = 55;
        Solaroc.def = 65;
        Solaroc.taux = 15;

        return Solaroc;
    }

    pokemon defineKecleon() {
        pokemon Kecleon;

        Kecleon.nom = "KECLEON";
        Kecleon.type = 'N';
        Kecleon.pvMax = 100;
        Kecleon.pvNow = 100;
        Kecleon.atk = 90;
        Kecleon.def = 70;
        Kecleon.taux = 80;

        return Kecleon;
    }

    pokemon definePachirisu() {
        pokemon Pachirisu;

        Pachirisu.nom = "PACHIRISU";
        Pachirisu.type = 'E';
        Pachirisu.pvMax = 100;
        Pachirisu.pvNow = 100;
        Pachirisu.atk = 90;
        Pachirisu.def = 70;
        Pachirisu.taux = 80;

        return Pachirisu;
    }

    pokemon definePijako() {
        pokemon Pijako;

        Pijako.nom = "PIJAKO";
        Pijako.type = 'N';
        Pijako.pvMax = 100;
        Pijako.pvNow = 100;
        Pijako.atk = 45;
        Pijako.def = 70;
        Pijako.taux = 75;

        return Pijako;
    }

    pokemon defineMotisma() {
        pokemon Motisma;

        Motisma.nom = "MOTISMA";
        Motisma.type = 'N';
        Motisma.pvMax = 100;
        Motisma.pvNow = 100;
        Motisma.atk = 65;
        Motisma.def = 107;
        Motisma.taux = 15;

        return Motisma;
    }

    pokemon defineNanmeouie() {
        pokemon Nanmeouie;

        Nanmeouie.nom = "NANMEOUIE";
        Nanmeouie.type = 'N';
        Nanmeouie.pvMax = 100;
        Nanmeouie.pvNow = 100;
        Nanmeouie.atk = 60;
        Nanmeouie.def = 86;
        Nanmeouie.taux = 80;

        return Nanmeouie;
    }

    pokemon defineBargantua() {
        pokemon Bargantua;

        Bargantua.nom = "BARGANTUA";
        Bargantua.type = 'W';
        Bargantua.pvMax = 100;
        Bargantua.pvNow = 100;
        Bargantua.atk = 95;
        Bargantua.def = 65;
        Bargantua.taux = 25;

        return Bargantua;
    }

    pokemon defineMaracachi() {
        pokemon Maracachi;

        Maracachi.nom = "MARACACHI";
        Maracachi.type = 'W';
        Maracachi.pvMax = 100;
        Maracachi.pvNow = 100;
        Maracachi.atk = 86;
        Maracachi.def = 67;
        Maracachi.taux = 80;

        return Maracachi;
    }

    pokemon defineEmolga() {
        pokemon Emolga;

        Emolga.nom = "EMOLGA";
        Emolga.type = 'E';
        Emolga.pvMax = 100;
        Emolga.pvNow = 100;
        Emolga.atk = 75;
        Emolga.def = 60;
        Emolga.taux = 80;

        return Emolga;
    }

    pokemon defineMamambo() {
        pokemon Mamambo;

        Mamambo.nom = "MAMAMBO";
        Mamambo.type = 'W';
        Mamambo.pvMax = 100;
        Mamambo.pvNow = 100;
        Mamambo.atk = 75;
        Mamambo.def = 80;
        Mamambo.taux = 30;

        return Mamambo;
    }

    pokemon defineHexagel() {
        pokemon Hexagel;

        Hexagel.nom = "HEXAGEL";
        Hexagel.type = 'W';
        Hexagel.pvMax = 100;
        Hexagel.pvNow = 100;
        Hexagel.atk = 50;
        Hexagel.def = 30;
        Hexagel.taux = 10;

        return Hexagel;
    }

    pokemon defineLimonde() {
        pokemon Limonde;

        Limonde.nom = "LIMONDE";
        Limonde.type = 'R';
        Limonde.pvMax = 100;
        Limonde.pvNow = 100;
        Limonde.atk = 66;
        Limonde.def = 84;
        Limonde.taux = 30;

        return Limonde;
    }

    pokemon defineAflamanoir() {
        pokemon Aflamanoir;

        Aflamanoir.nom = "AFLAMANOIR";
        Aflamanoir.type = 'F';
        Aflamanoir.pvMax = 100;
        Aflamanoir.pvNow = 100;
        Aflamanoir.atk = 97;
        Aflamanoir.def = 66;
        Aflamanoir.taux = 35;

        return Aflamanoir;
    }

    pokemon defineFermite() {
        pokemon Fermite;

        Fermite.nom = "FERMITE";
        Fermite.type = 'G';
        Fermite.pvMax = 100;
        Fermite.pvNow = 100;
        Fermite.atk = 109;
        Fermite.def = 112;
        Fermite.taux = 35;

        return Fermite;
    }

    pokemon defineDedenne() {
        pokemon Dedenne;

        Dedenne.nom = "DEDENNE";
        Dedenne.type = 'E';
        Dedenne.pvMax = 100;
        Dedenne.pvNow = 100;
        Dedenne.atk = 60;
        Dedenne.def = 60;
        Dedenne.taux = 75;

        return Dedenne;
    }

    pokemon defineStrassie() {
        pokemon Strassie;

        Strassie.nom = "STRASSIE";
        Strassie.type = 'R';
        Strassie.pvMax = 100;
        Strassie.pvNow = 100;
        Strassie.atk = 50;
        Strassie.def = 150;
        Strassie.taux = 15;

        return Strassie;
    }

    pokemon defineBrocelome() {
        pokemon Brocelome;

        Brocelome.nom = "BROCELOME";
        Brocelome.type = 'G';
        Brocelome.pvMax = 100;
        Brocelome.pvNow = 100;
        Brocelome.atk = 70;
        Brocelome.def = 48;
        Brocelome.taux = 50;

        return Brocelome;
    }

    pokemon definePlumeline() {
        pokemon Plumeline;

        Plumeline.nom = "PLUMELINE";
        Plumeline.type = 'F';
        Plumeline.pvMax = 100;
        Plumeline.pvNow = 100;
        Plumeline.atk = 70;
        Plumeline.def = 70;
        Plumeline.taux = 20;

        return Plumeline;
    }

    pokemon defineFroussardine() {
        pokemon Froussardine;

        Froussardine.nom = "FROUSSARDINE";
        Froussardine.type = 'W';
        Froussardine.pvMax = 100;
        Froussardine.pvNow = 100;
        Froussardine.atk = 20;
        Froussardine.def = 20;
        Froussardine.taux = 60;

        return Froussardine;
    }

    pokemon defineConcombaffe () {
        pokemon Concombaffe;

        Concombaffe.nom = "CONCOMBAFFE";
        Concombaffe.type = 'W';
        Concombaffe.pvMax = 100;
        Concombaffe.pvNow = 100;
        Concombaffe.atk = 60;
        Concombaffe.def = 130;
        Concombaffe.taux = 60;

        return Concombaffe;
    }

    pokemon defineMeteno () {
        pokemon Meteno;

        Meteno.nom = "METENO";
        Meteno.type = 'R';
        Meteno.pvMax = 100;
        Meteno.pvNow = 100;
        Meteno.atk = 100;
        Meteno.def = 60;
        Meteno.taux = 80;

        return Meteno;
    }

    pokemon defineDodoala () {
        pokemon Dodoala;

        Dodoala.nom = "DODOALA";
        Dodoala.type = 'N';
        Dodoala.pvMax = 100;
        Dodoala.pvNow = 100;
        Dodoala.atk = 115;
        Dodoala.def = 65;
        Dodoala.taux = 45;

        return Dodoala;
    }

    pokemon defineBoumata () {
        pokemon Boumata;

        Boumata.nom = "BOUMATA";
        Boumata.type = 'F';
        Boumata.pvMax = 100;
        Boumata.pvNow = 100;
        Boumata.atk = 78;
        Boumata.def = 135;
        Boumata.taux = 30;

        return Boumata;
    }

    pokemon defineTogedemaru () {
        pokemon Togedemaru;

        Togedemaru.nom = "TOGEDEMARU";
        Togedemaru.type = 'E';
        Togedemaru.pvMax = 100;
        Togedemaru.pvNow = 100;
        Togedemaru.atk = 98;
        Togedemaru.def = 63;
        Togedemaru.taux = 70;

        return Togedemaru;
    }

    pokemon defineMimiqui () {
        pokemon Mimiqui;

        Mimiqui.nom = "MIMIQUI";
        Mimiqui.type = 'N';
        Mimiqui.pvMax = 100;
        Mimiqui.pvNow = 100;
        Mimiqui.atk = 90;
        Mimiqui.def = 80;
        Mimiqui.taux = 17;

        return Mimiqui;
    }

    pokemon defineDenticrisse () {
        pokemon Denticrisse;

        Denticrisse.nom = "DENTICRISSE";
        Denticrisse.type = 'W';
        Denticrisse.pvMax = 100;
        Denticrisse.pvNow = 100;
        Denticrisse.atk = 105;
        Denticrisse.def = 70;
        Denticrisse.taux = 30;

        return Denticrisse;
    }

    pokemon defineDraieul() {

        pokemon Draieul;

        Draieul.nom = "DRAIEUL";
        Draieul.type = 'N';
        Draieul.pvMax = 100;
        Draieul.pvNow = 100;
        Draieul.atk = 60;
        Draieul.def = 85;
        Draieul.taux = 30;

        return Draieul;
    }
    pokemon defineSinistrail() {

        pokemon Sinistrail;

        Sinistrail.nom = "SINISTRAIL";
        Sinistrail.type = 'G';
        Sinistrail.pvMax = 100;
        Sinistrail.pvNow = 100;
        Sinistrail.atk = 131;
        Sinistrail.def = 100;
        Sinistrail.taux = 10;

        return Sinistrail;
    }
    pokemon defineKatagami() {

        pokemon Katagami;

        Katagami.nom = "KATAGAMI";
        Katagami.type = 'G';
        Katagami.pvMax = 100;
        Katagami.pvNow = 100;
        Katagami.atk = 181;
        Katagami.def = 131;
        Katagami.taux = 3;

        return Katagami;
    }

    pokemon defineWattapik() {
        pokemon Wattapik;

        Wattapik.nom = "WATTAPIK";
        Wattapik.type = 'E';
        Wattapik.pvMax = 100;
        Wattapik.pvNow = 100;
        Wattapik.atk = 100;
        Wattapik.def = 95;
        Wattapik.taux = 75;

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

        return Dolman;
    }

    pokemon defineBekaglacon() {

        pokemon Bekaglacon;

        Bekaglacon.nom = "BEKAGLACON";
        Bekaglacon.type = 'W';
        Bekaglacon.pvMax = 100;
        Bekaglacon.pvNow = 100;
        Bekaglacon.atk = 80;
        Bekaglacon.def = 110;
        Bekaglacon.taux = 60;

        return Bekaglacon;
    }

    pokemon defineMorpeko() {
        pokemon Morpeko;

        Morpeko.nom = "MORPEKO";
        Morpeko.type = 'E';
        Morpeko.pvMax = 100;
        Morpeko.pvNow = 100;
        Morpeko.atk = 95;
        Morpeko.def = 60;
        Morpeko.taux = 70;

        return Morpeko;
    }

}

#endif
