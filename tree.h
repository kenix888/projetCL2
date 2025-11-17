//
// Created by Elliott on 01/11/2022.
//

#ifndef PROJETGÉNÉRATEURPHRASES_TREE_H
#define PROJETGÉNÉRATEURPHRASES_TREE_H

#include "node.h"

typedef struct s_tree
{
    p_node root;
    int depth;
} t_tree, *p_tree;

void RemplirArbre(p_tree, p_tree, p_tree, p_tree);
int ReconnaitreType(char*);
char CaracSpecial(char);
void displayTree(p_node);
void AjouterFlechie(p_tree, char*, char*, char*);
int MotExiste(p_node, char*);
void ExtraireMotHasard(p_node, char*);
char* GenererPhraseConj(p_node, p_node, p_node, p_node);
void RenvoiFlechies(p_node, char*);

#endif //PROJETGÉNÉRATEURPHRASES_TREE_H