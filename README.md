# Mathématiques 4 • Pokimax III
Pokimax III est la suite du projet Pokimax initialement réalisé dans le cadre du cours d'Algorithmique et Programmation du Semestre 1 de l'IMAC. Cette fois-ci le projet est réalisé dans le cadre du cours de Mathématiques du Semestre 4 de l'IMAC. 

Initialement le but du projet était de réaliser un jeu inspiré de Pokémon en C++ et devant être jouable dans l'invite de commandes de Linux. Pour la nouvelle partie mathématiques, il s'agit de réaliser un programme sur ordinateur qui simule un jeu avec des composantes aléatoires
maîtrisées par des paramètres. 

J'ai donc décidé de reprendre le projet Pokimax et d'y implanter des paramètres aléatoires maîtrisés. 

## I. Fonctionnement du jeu

### 1. L'introduction
Au lancement du jeu, une première ligne de texte apparaîtra pour vous demander si vous voulez regarder l'introduction du jeu. 
```
regarder l'introduction ? (y/n)
```

repondez avec `y` pour oui et `n` pour non et appuyez sur entrée. 

Si vous avez choisi de regarder l'introduction, un dialogue d'introduction défilera et vous présentera le monde de Pokémon. On vous demandera votre nom. 

```
Comment t'appelles-tu ?
Votre Nom ? : 
```

Entrez votre nom puis appuyez sur entrée. **Votre nom est un facteur important dans la partie aléatoire du jeu.** En effet à partir de votre nom est calculé un ID qui rentrera en tant que paramètre dans de nombreuses lois de probabilités du jeu. Si vous avez choisi de ne pas regarder l'introduction, un ID vous sera donné d'office : 50. 

On finira par vous expliquer les commandes puis vous pourrez passer à la suite. 

### 2. Paramétrage de la carte

Une fois l'introduction jouée ou passée, le jeu vous proposera de donner des valeurs pour la génération de la carte. 
```
hauteur de la map (conseillee : 25) :
largeur de la map (conseillee : 50) :
```
Entrez les valeurs qui vous conviennent pour la taille de la carte. Faites en fonction de la taille de la fenêtre de votre invite de commande pour éviter de faire une carte trop grande. 
```
forme de la map (0 = normal, 1 = Gauss, 2 = Triangulaire) :
```
pour ce dernier paramètre, entrez ̀`0`, `1` ou `2` pour choisir comment les Pokémon seront distribués sur la carte.

Une fois ces paramètres rentrés, un texte défilera pour donner des estimations quant au nombre de Pokémon dans votre partie, puis le jeu commencera.

### 3. La carte

Voilà de quoi aura l'air la carte : 
```
---------------------------------------------------
|0                                                |
|                                  ?              |
|     ?   ??                       ?              |
|                         ?        ?              |
|  ?                                              |
|     ?      ?           ?  ?                     |
|                           ? ? ?? ?        ?     |
|                                       ?         |
|       ? ??                    ?              ?  |
|?      ?         ?                    ? ?        |
|                ?                                |
|                                             ?   |
|                     ? ?                         |
|        ?                                        |
|        ?  ? ?           ?           ?           |
|  ?    ?                            ?            |
|                      ?               ?          |
|                                  ?              |
|                           ?                     |
|                  ?              ?      ?     ?  |
|                                                 |
|                   ?   ?                         |
|                               ?                 |
---------------------------------------------------
```
Votre personnage est représenté par le caractère `0`, il apparaît dans le coin supérieur gauche de la carte. Les `?` sont des Pokémon. votre objectif est de rencontrer tous les Pokémon de la carte. 

Pour cela, déplacez-vous avec les touches `Z`, `Q`, `S` et `D` et gérez votre équipe de Pokémon avec la touche `T`. Lancez un combat contre un Pokémon sauvage en entrant en contact avec lui. 

### 3. Gestion de l'équipe

Vous commencez le jeu avec un Pikachu et votre équipe peut contenir jusqu'à 6 Pokémon. 

En appuyant sur la touche `T`, un écran comme celui-ci apparaîtra :
```
Quel Pokemon doit remplacer PIKACHU ?
1 - PIKACHU
2 - NIGOSIER
3 - PLUMELINE
4 - 
5 - 
6 - 
```
Entrez un nombre entre 1 et 6 puis appuyez sur entrée pour placer le Pokémon correspondant en première position dans l'équipe. Au lancement d'un combat contre un pokémon sauvage, c'est le premier Pokémon de l'équipe qui est envoyé. 

Si vous capturez un Pokémon alors que votre équipe est complète, le jeu vous proposera de relâcher un de vos pokémon pour l'accueillir. Vous pourrez aussi relâcher le pokémon que vous venez de capturer en entrant 7. 

Si vous entrez une valeur interdite (>6 ou 0 par exemple) ou si vous tentez de mettre en première position un Pokémon n'ayant plus de PV, il ne se passera rien. tapez un autre chiffre valide puis appuyez sur entrée. 

### 4. Combat

Une fois que vous aurez rencontré un `?`, un combat ce lancera.

```
                  MORPHEO
                  PV 70/70
   PIKACHU
   PV 58/100

Un MORPHEO sauvage apparait !

R - ATTAQUE   T - POKEMON
F - CAPTURE   G - FUITE
V - ESTIMATIONS
```
Appuyez sur `R` pour tenter d'attaquer le Pokémon sauvage, appuyez sur `F` pour tenter de le capturer, appuyez sur `T` pour gérer votre équipe et appuyez sur `G` pour prendre la fuite. 

Appuyez sur la touche `V` pour avoir des estimations sur ce qu'il va ce passer lors du prochain tour. 

## II. Lois de probabilités et variables aléatoires utilisées

### 1. Loi uniforme
La loi uniforme modélise une situation où chaque événement à la même probabilité d'arriver. 

#### Implémentation
La loi uniforme a été implémentée en utilisant la fonction `rand()` de la librarie C++ `stdlib.h`. 

Implémentée ainsi : `static_cast<float>(rand())/RAND_MAX;`, elle permet de retourner une valeur aléatoire entre 0 et 1 (compris) de manière uniforme.

Cette loi sert à définir les autres lois. 

#### Dans le jeu
- Elle sert lors de l'initialisation de la carte : le Pokémon qui est assigné à chaque `?` est déterminé lors de la création de la carte. Un `std::vector` contenant chaque Pokémon multiplié par son taux de rareté (entre 1 et 7) est créé auparavant. Pour savoir quel pokémon sera assigné à un`?`, un nombre est tiré uniformément entre 0 et la longeur du `std::vector` et ce sera le Pokémon situé à cette position dans le vecteur qui sera tiré. 
- Elle sert aussi lors d'un combat, quand on tente de capturer un pokémon sauvage, une valeur aléatoire entre 0 et 100 est tirée uniformément et si elle est inférieure au pourcentage de chance de capturer le Pokémon, le celui-ci est capturé. 

### 2. Loi géométrique
La loi géométrique modélise le nombre d'essais nécessaires avant d'obtenir un succès. 

#### Implémentation
La fonction permettant de connaître le nombre d'essais nécéssaire avant d'obtenir un succès est implémentée comme ceci : 
```cpp
int essaisGeometrique(float p) {
    int k = 1;
    float Px = std::pow(1-p, k-1)*p;
    while(Px < 0.95) {
        ++k;
        Px += std::pow(1-p, k-1)*p;
    }
    return k;
}
```
le paramètre `p` utilisé en paramètre de la fonction est une probabilité donnée grâce à l'ID du joueur. La valeur 0.95 à été choisie arbitrairement. 

Une autre fonction a été implémentée pour cette loi : 

```cpp
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
```
avec
```cpp
float probaGeometrique(int id, int k) {
    float p = getPFromId(id);
    return std::pow(1-p, k-1)*p;
}
```
Cette fonction modélise les essais avant d'obtenir un succès et calcule la probabilité d'obtenir la situation modélisée. 

#### Dans le jeu
Elle sert lors des estimations. Dans un combat, en utilisant la touche `V`, la loi géométrique est utilisée pour estimer le nombre d'essais nécéssaires avant que votre Pokémon arrive a toucher son adversaire avec une attaque et inversement. Elle sert aussi a estimer le nombre d'essais nécéssaires avant de réussir à capturer le pokémon adverse. 

### 3. Loi de Bernoulli

La loi de Bernoulli modélise une situation si ne peut avoir que 2 issues : un succès, de probabilité $p$ et un échec, de probabilité $1-p$.

#### Implémentation
La fonction permettant de connaitre si l'expérience de bernoulli est un succès est définie comme suit : 
```cpp
bool bernouilli(float p) {
    float val = uniforme();
    return val < p ? true : false;
}
```
avec le paramètre `p`, une probabilité de succès. 

#### Dans le jeu
Elle sert en combat, au moment d'attaquer. la loi de Bernoulli est utilisée pour savoir si le pokémon attaquant va réussi à toucher l'autre. en cas de succès, tous les calculs sont réalisés, en cas d'échec une ligne de texte vous indique que le pokémon a raté son attaque. La probabilité `p` donnée en paramètre de la fonction est calculée à partir de la statistique de précision du pokemon. $$p = \frac{\frac{\rm{précision}*90}{130}+20}{100}$$

*(`p` peut être supérieur à 1, votre Pokémon touchera à tous les coups)*

### 4. Loi binomiale

La loi binomiale modélise la probabilité d'obtenir un certain nombre de succès de probabilté $p$ parmi un nombre d'essais. 

#### Implémentation

la fonction permettant de connaitre la probabilité de $k$ succès parmi $n$ expériences réalisées est implémentée comme suit : 

``` cpp
float binomiale(int id, int k, int n) {
    float p = getPFromId(id);
    float Cnk = (float)fact(n)/((float)fact(k)*(float)fact(n-k));
    float Pk = Cnk*std::pow(p, k)*std::pow(1-p, n-k);
    return Pk;
}
``` 
pour une meilleure lisibilité : $$C_n^k=\frac{n!}{k!\times(n-k)!}\\P_k=C_n^k\times p^k(1-p)^{n-k}$$

avec comme paramètre `id` l'ID du joueur qui donne la probabilité de succès. 

#### Dans le jeu

Elle sert dans les combats, au moment de la capture. Dans les jeux Pokémon originaux, lorsqu'on tente de capturer un pokémon sauvage, la Poké Ball (objet permettant de capturer et dans laquelle est enfermée le Pokémon) tremble 3 fois avant de se refermer et de confirmer la capture. Ici cette situation est modélisée avec une loi de bernoulli. 1 succès parmi 4 essais vaut 1 tremblement, 2 succès parmi 4 essais vaut 2 tremblements, 3 succès parmi 4 essais vaut 3 tremblements et enfin 4 succès parmi 4 essais vaut la fermeture de la Poké Ball. 

d'autres paramètres rentrent en considération lors de la capture, le pourcentage de chances de capturer est calculé ainsi : $$p_{\times100} = \rm{binomiale}(ID, 4, 4)\times\frac{taux}{2}\times\left(1-\frac{PV_{actuels}-1}{PV_{max}}\right)\times100$$

### 5. Loi de Poisson

La loi de Poisson décrit le comportement du nombre d'événements se produisant dans un intervalle temporel ou spacial.

#### Implémentation

La fonction permettant de connaitre le nombre d'événements sur une aire est définie comme suit : 

``` cpp
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
```

Elle prend en entrée le paramètre `lambda` calculé à l'avance. 

#### Dans le jeu

Elle sert au tout début du jeu, a donner le nombre de Pokémon (`?`) qui apparaîtront sur la carte. Le paramètre `lambda` est calculé en fonction de la hauteur et de la largeur renseignées, ainsi que d'une probabilité calculée à partir de l'ID du joueur : $$\lambda=p_{ID}\times\frac{\rm{hauteur}}{3}\times\frac{\rm{largeur}}{3}$$

### 6. Loi hypergéométrique

La loi hypergéométrique permet d'obtenir le nombre d'éléments présentant une caractéristique particulière parmi une sélection d'éléments

#### Implémentation

La fonction permettant d'estimer le nombre d'éléments particuliers parmi $x$ éléments, tirés d'une population de $m$ éléments, dans laquelle on retrouve $n$ éléments particuliers est définie comme suit : 

``` cpp
int hypergeometrique(int n, int m, int x, int iter) {
        int mTotal = 0;
        for (int i = 0; i < iter; ++i) {
            int xSample = 0;
            for (int j = 0; j < x; ++j) {
                int val = uniforme()*n;
                if (val < m) {
                    xSample++;
                }
            }
            mTotal += xSample;
        }
        return mTotal / iter;
    }
```

la paramètre `iter` permet de réaliser la simulation un certain nombre de fois et d'obtenir une moyenne. 

#### Dans le jeu

Elle sert au tout début du jeu, juste après la loi de Poisson permettant de donner le nombre de Pokémon qui apparaîtront sur la carte. La Loi hypergéométrique est utilisée pour estimer le nombre de Pokémon rares qui apparaîtront. Chaque Pokémon à une statistique de rareté qui lui est assignée. Un pokémon ayant une valeur 1 ou 2 est considéré comme rare. La valeur va jusqu'à 7. Un Pokémon ayant une valeur de rareté égale à 7 est 7 fois moins rare qu'un Pokémon ayant une rareté de 1. 

En prenant en compte les 96 Pokémon du jeu et en la multipliant par la rareté de chacun, cela nous donne le paramètre $m = 286$. 

En prenant seulement les pokémon considérés comme rare et en les multipliant par leur rareté de respectives, on obtient le paramètre $n=62$

Avec $x$ défini avec la loi de Poisson juste avant et `iter` fixé à 1000.

### 7. Loi normale centrée réduite

La loi normale centrée réduite permet de modéliser différentes situations dans de nombreux domaines comme la distribution des tailles d'une population ou la plage de résultats de tests standardisés (QI) par exemple.

#### Implémentation

La fonction permettant de simuler une loi normale centrée réduite grâce à une courbe en cloche de Gauss est définie comme suit : 

``` cpp
// Quand courbe vaut 1
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
    } 
    /*else if (courbe == 2) {
        val = triangulaire(1);

    }*/
    return val;
}
```
avec
``` cpp
float gauss(float val) {
    return (1/(std::sqrt(2*M_PI)))*std::exp(-2.0*val*val);
}
```
Pour une meilleure lisibilité, la fonction `gauss(float val)` renvoie$$\frac{1}{\sqrt{2\pi}}\times e^{-2\rm{val}^2}$$

Cette fonction donne une courde en cloche de gauss centrée sur $0$ et légèrement déformée pour resserrer la "cloche" afin qu'elle soit comprise entre $-1,5$ et $1,5$.

Dans densité(), les nombres sont tirés aléatoirement dans cet intervalle puis replacés entre $0$ et $1$ avant d'être retournés 

#### Dans le jeu

Elle sert après avoir fait le choix de la "forme" de la carte. en choisissant 1, l'emplacement des `?` sera fait suivant la courbe en cloche de Gauss évoquée précédemment. Tous les Pokémon devraient être distribués vers le centre de la carte avec ce choix. 

### 8. Loi triangulaire

La loi triangulaire permet de modéliser différentes situations dans de nombreux domaines comme des temps d'attente ou des estimations de coûts par exemple. 

#### Implémentation

La fonction permettant de simuler une loi triangulaire est défine comme suit :

``` cpp
// Quand courbe vaut 2
float densite(int id, int courbe) {
    float val = uniforme();
    /* if (courbe == 1) {
        val = uniforme()*3-1.5;
        float image = uniforme()*.38;
        float obj = gauss(val);
        while (image > obj) {
            val = uniforme()*3-1.5;
            obj = gauss(val);
        }
        val = (val+1.5)/3;
    } */
    else if (courbe == 2) {
        val = triangulaire(1);
    }
    return val;
}
```
avec

``` cpp
float triangulaire(float mode) {
    float val = uniforme();
    if (val < mode) {
        return sqrt(val*mode);
    } else {
        return 1-sqrt((1-val)*(1-mode));
    }
}
```

Cette fonction simule une loi triangulaire de support $]0 ; 1[$ et de mode fixé à $1$.

#### Dans le jeu

Elle sert après avoir fait le choix de la "forme" de la carte. en choisissant 2, l'emplacement des `?` sera fait suivant la loi trianglaire avec les paramètres cité précédemment. Tous les Pokémon devraient être distribués vers le coin inférieur gauche de la carte avec ce choix. 

## III. Compilation et execution
dans l'invite de commande utiliser :
```
./pkmxIII.sh
```

## IV. Dépendances
La librairie `conio.h` est nécessaire pour utiliser Pokimax III. voir : [github.com/zoelabbb/conio.h](https://github.com/zoelabbb/conio.h)

- en cas de conflit sur une certaine fonction ```gettext```, modifier le fichier conio.h dans ```usr/include/``` et commenter la ligne 377