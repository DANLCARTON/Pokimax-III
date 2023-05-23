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

Si vous avez choisi de regarder l'introduction, un texte reprenant le dialogue d'introduction du professeur Chen dans Pokémon : Version Rouge et Bleue défilera et vous présentera le monde de Pokémon. Il vous demandera votre nom. 

```
Comment t'appelles-tu ?
Votre Nom ? : 
```

Entrez votre nom puis appuyez sur entrée. Votre nom est un facteur important dans la partie aléatoire du jeu. En effet à partir de votre nom est calculé un ID qui rentrera en tant que paramètre dans de nombreuses lois de probabilités du jeu. Si vous avez choisi de ne pas regarder l'introduction, un ID vous sera donné d'office : 50. 

Le professeur Chen finira par vous expliquer les commandes puis vous pourrez jouer. 

### 2. Paramétrage de la carte

Une fois l'introduction jouée ou passée, le jeu vous proposera de donner des valeurs pour la génération de la carte. 
```
hauteur de la map (conseillee : 25) :
largeur de la map (conseillee : 50) :
```
Entrez les valeurs qui vous conviennent pour la taille de la carte. Faites en fonction de la taille de la fenêtre de votre invite de commande pour éviter de faire une carte trop grande. 
```
forme de la map (0 = normal, 1 = Gauss, 2 = 2X) :
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

## II. Lois de probabilités et variables aléatoires

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
- Elle sert lors des estimations. Dans un combat, en utilisant la touche `V`, la loi géométrique est utilisée pour estimer le nombre d'essais nécéssaires avant que votre Pokémon arrive a toucher son adversaire avec un attaque et inversement. Elle sert aussi a estimer le nombre d'essais nécéssaires avant de réussir à capturer le pokémon adverse. 


## III. Compilation et execution
dans l'invite de commande utiliser :
```
./pkmxIII.sh
```

## IV. Dépendances
La librairie `conio.h` est nécessaire pour utiliser Pokimax III. voir : [zoelabbb/conio.h](https://github.com/zoelabbb/conio.h)
en cas de conflit sur une certaine fonction ```gettext```, modifier le fichier conio.h dans ```usr/include/``` et commenter la ligne 377