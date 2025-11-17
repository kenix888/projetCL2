#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "tree.h"
#include "menu.h"
#include "menu.c"
#include "tree.c"
#include "node.c"


int main() {
    //generation de la seed pour le rand()
    srand(time(NULL));
    //creation des arbres
    t_tree noms, verbes, adverbes, adjectifs;
    //on initialise les racines a 0
    noms.root = createNode('0');
    verbes.root = createNode('0');
    adverbes.root = createNode('0');
    adjectifs.root = createNode('0');
    noms.depth = verbes.depth = adverbes.depth = adjectifs.depth = 0;

    //on remplit l'arbre
    RemplirArbre(&noms, &adverbes, &adjectifs, &verbes);

    // on lance le menu avec les choix
    menu(noms, verbes, adverbes, adjectifs);

    return 0;
}