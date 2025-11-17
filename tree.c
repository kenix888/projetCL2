//
// Created by Elliott on 01/11/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"


// rempli les arbres
void RemplirArbre(p_tree arbre_nom, p_tree arbre_adv, p_tree arbre_adj, p_tree arbre_vrb){          //Fonction qui remplit les arbres noms, verbes, adjectifs et adverbes avec les formes de base
    FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\Elliott\\CLionProjects\\untitled35\\dictionnaire_non_accentue.txt", "r");  //Ouverture du dictionnaire non accentue en mode lecture
    char  l[200];
    int compteur=0;
    while(fgets(l, 1000, fichier)!=NULL){           //Lecture ligne par ligne
        char mot_flechi[35]="\0", mot_base[35]="\0", type[70]="\0";
        int i=0, j=0, k=0;
        while((l[i]!=' ')&&(l[i]!=9)){              //stockage du mot fléchi
            if((64<(int)l[i]) && ((int)l[i]<123)) {
                strncat(mot_flechi, &l[i], 1);      //On ajoute lettre par lettre
            }
            i++;
        }
        j=i+1;
        while(l[j]==' ')                        //on place le curseur après les espaces
            j++;
        while((l[j]!=' ')&&(l[j]!=9)){          //stockage du mot de base
            strncat(mot_base, &l[j], 1);            //On ajoute lettre par lettre
            j++;
        }
        k=j+1;
        while(l[k]==' ')                        //on place le curseur après les espaces
            k++;
        while(l[k]!='\n'){                  //stockage du type
            strncat(type, &l[k], 1);            //On ajoute lettre par lettre
            k++;
        }
        int code_asc;
        if(ReconnaitreType(type)==1){
            if(MotExiste(arbre_nom->root, mot_flechi)==0) {
                p_node temp = arbre_nom->root;
                for (i = 0; i < strlen(mot_base); i++) {          //on parcours le mot et on remplit l'arbre en même temps
                    code_asc = mot_base[i];
                    if((97<=code_asc)&&(code_asc<=122)){              //si le caractère est une lettre
                        if (temp->sons[code_asc - 97] ==NULL) {           //on choisit la case du tableau où on stocke la lettre en fonction de son code ascii
                            temp->sons[code_asc - 97] = createNode(mot_base[i]);
                            arbre_nom->depth++;
                        }
                        else{
                            temp->sons[code_asc - 97]->lettre = mot_base[i];
                        }
                        temp = temp->sons[code_asc - 97];
                    }
                    else if(mot_base[i]=='-'){
                        if (temp->sons[26]==NULL) {           //on stock les tirets dans le 27e fils
                            temp->sons[26] = createNode(mot_base[i]);
                            arbre_nom->depth++;
                        }
                        temp = temp->sons[26];
                    }
                    else{
                        if (temp->sons[27]==NULL) {           //on stock les ' dans le 28e fils
                            temp->sons[27] = createNode(mot_base[i]);
                            arbre_nom->depth++;
                        }
                        temp = temp->sons[27];
                    }
                }
            }
            if(strcmp(mot_base, mot_flechi)!=0){                   //Si le mot est une forme fléchie on la stocke dans le dernier noeud du mot de base dans l'arbre
                AjouterFlechie(arbre_nom, mot_base, mot_flechi, type);
            }
        }
        else if(ReconnaitreType(type)==2){              //Si le mot est un verbe
            if(MotExiste(arbre_vrb->root, mot_base)==0){            //si le mot n'est pas déjà stocké dans l'arbre
                p_node temp = arbre_vrb->root;
                for(i=0; i<strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if((97<=code_asc)&&(code_asc<=122)){
                        if (temp->sons[code_asc - 97] ==NULL) {           //on choisit la case du tableau où on stocke la lettre en fonction de son code ascii
                            temp->sons[code_asc - 97] = createNode(mot_base[i]);
                            arbre_vrb->depth++;
                        }
                        else{
                            temp->sons[code_asc - 97]->lettre = mot_base[i];
                        }
                        temp = temp->sons[code_asc - 97];
                    }
                    else if(mot_base[i]=='-'){
                        if (temp->sons[26]==NULL) {           //on stock les tirets dans le 27e fils
                            temp->sons[26] = createNode(mot_base[i]);
                            arbre_vrb->depth++;
                        }
                        temp = temp->sons[26];
                    }
                    else{
                        if (temp->sons[27]==NULL) {           //on stock les ' dans le 28e fils
                            temp->sons[27] = createNode(mot_base[i]);
                            arbre_vrb->depth++;
                        }
                        temp = temp->sons[27];
                    }
                }
            }
            if(strcmp(mot_base, mot_flechi)!=0){                   //Si le mot est une forme fléchie on la stocke dans le dernier noeud du mot de base dans l'arbre
                AjouterFlechie(arbre_vrb, mot_base, mot_flechi, type);
            }
        }
        else if(ReconnaitreType(type)==3) {              //Si le mot est un adjectif
            if(MotExiste(arbre_adj->root, mot_base)==0){            //si le mot n'est pas déjà stocké dans l'arbre
                p_node temp = arbre_adj->root;
                for (i = 0; i < strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if((97<=code_asc)&&(code_asc<=122)){
                        if (temp->sons[code_asc - 97] ==NULL) {           //on choisit la case du tableau où on stocke la lettre en fonction de son code ascii
                            temp->sons[code_asc - 97] = createNode(mot_base[i]);
                            arbre_adj->depth++;
                        }
                        else{
                            temp->sons[code_asc - 97]->lettre = mot_base[i];
                        }
                        //printf("%c\n", temp->sons[code_asc - 97]->lettre);
                        temp = temp->sons[code_asc - 97];
                    }
                    else if(mot_base[i]=='-'){
                        if (temp->sons[26]==NULL) {           //on stock les tirets dans le 27e fils
                            temp->sons[26] = createNode(mot_base[i]);
                            arbre_adj->depth++;
                        }
                        temp = temp->sons[26];
                    }
                    else{
                        if (temp->sons[27]==NULL) {           //on stock les ' dans le 28e fils
                            temp->sons[27] = createNode(mot_base[i]);
                            arbre_adj->depth++;
                        }
                        temp = temp->sons[27];
                    }
                }
            }
            if(strcmp(mot_base, mot_flechi)!=0){                   //Si le mot est une forme fléchie on la stocke dans le dernier noeud du mot de base dans l'arbre
                AjouterFlechie(arbre_adj, mot_base, mot_flechi, type);
            }
        }
        else if(ReconnaitreType(type)==4){
            if(MotExiste(arbre_adj->root, mot_base)==0){            //si le mot n'est pas déjà stocké dans l'arbre
                p_node temp = arbre_adv->root;
                for(i=0; i<strlen(mot_base); i++) {
                    code_asc = mot_base[i];
                    if((97<=code_asc)&&(code_asc<=122)){
                        if (temp->sons[code_asc - 97] ==NULL) {           //on choisit la case du tableau où on stocke la lettre en fonction de son code ascii
                            temp->sons[code_asc - 97] = createNode(mot_base[i]);
                            arbre_adv->depth++;
                        }
                        else{
                            temp->sons[code_asc - 97]->lettre = mot_base[i];
                        }
                        //printf("%c\n", temp->sons[code_asc - 97]->lettre);
                        temp = temp->sons[code_asc - 97];
                    }
                    else if(mot_base[i]=='-'){
                        if (temp->sons[26]==NULL) {           //on stock les tirets dans le 27e fils
                            temp->sons[26] = createNode(mot_base[i]);
                            arbre_adv->depth++;
                        }
                        temp = temp->sons[26];
                    }
                    else{
                        if (temp->sons[27]==NULL) {           //on stock les ' dans le 28e fils
                            temp->sons[27] = createNode(mot_base[i]);
                            arbre_adv->depth++;
                        }
                        temp = temp->sons[27];
                    }
                }
            }
            if(strcmp(mot_base, mot_flechi)!=0){            //Si le mot est une forme fléchie on la stocke dans le dernier noeud du mot de base dans l'arbre
                AjouterFlechie(arbre_adv, mot_base, mot_flechi, type);
            }
        }
    }
    fclose(fichier);
}


int ReconnaitreType(char* type){            //Fonction qui renvoie le numéro correspondant au type du mot
    if(type[0]=='N')
        return 1;
    else if(type[0]=='V')
        return 2;
    else if(type[2]=='j')
        return 3;
    else if(type[2]=='v')
        return 4;
}





// permet d'ajouter les formes flechies et leurs types dans le dernier noeud d'un mot dans l'arbre
void AjouterFlechie(p_tree tree, char *mot_base, char *mot_flechi, char *type){         //Fonction qui ajoute les formes flechies d'un mot dans son dernier noeud
    p_node temp = tree->root;
    int cmp=0, i;
    for(i=0; i<strlen(mot_base)-1; i++){              //On parcours l'arbre jusqu'au dernier noeud du mot
        int code_asc = mot_base[i];
        if((97<=code_asc)&&(code_asc<=122))
            temp = temp->sons[code_asc-97];
        else if(mot_base[i]=='-')
            temp = temp->sons[26];
        else
            temp = temp->sons[27];
    }
    for(int j=0; j< strlen(mot_flechi)-1; j++){           //On parcours le mot en stockant chaque lettre dans le tableau des fléchies
        temp->flechies[temp->nb_flechies][j] = mot_flechi[j];
        cmp=j;
    }
    cmp++;
    temp->flechies[temp->nb_flechies][cmp] = '/';           //On stock le type à la suite du mot flechie en separant les 2 par un / afin de pouvoir connaitre son accord
    cmp++;
    for(int k=0; k<strlen(type); k++){           //On parcours le mot en stockant chaque lettre dans le tableau des fléchies
        temp->flechies[temp->nb_flechies][cmp] = type[k];
        cmp++;
    }
    temp->flechies[temp->nb_flechies][cmp]='\0';
    temp->nb_flechies++;
}

// recherche un mot dans un arbre
int MotExiste(p_node p, char *mot){             //Fonction qui retourne 1 si le mot existe dans l'arbre et 0 sinon
    p_node temp = p;
    for(int i=0; i< strlen(mot)-1; i++){
        if((97<=(int)mot[i])&&((int)mot[i]<=122))
            temp=temp->sons[(int)mot[i]-97];
        else if(mot[i]=='-')
            temp=temp->sons[26];
        else
            temp=temp->sons[27];
        if(temp==NULL){
            return 0;
        }
    }
    return 1;
}

// permet d'extraire un mot au hasard dans l'arbre donné
void ExtraireMotHasard(p_node p, char* mot){          //Fonction qui extrait un mot au hasard parmis les formes de base de l'arbre
    p_node temp = p;
    int val=0;
    int vide;
    while(temp!=NULL){
        vide=1;
        for(int i=0; i<26; i++){            //On regarde si il y des fils du noeud actuel qui ne sont pas vide
            if(temp->sons[i]!=NULL){
                vide=0;
            }
        }
        val=rand() %28;           //On choisit une valeur au hasard entre 0 et 27 donc un noeud au hasard entre 0 et 27
        if(vide==1)               //Si tous les fils sont vides, on sort de la boucle
            temp=NULL;
        else if(temp->sons[val]!=NULL){         //Si le noeud choisi au hasard n'est pas à null
            temp = temp->sons[val];
            strncat(mot, &temp->lettre, 1);         //on ajoute la lettre au mot final
        }
    }
}


char* GenererPhraseConj(p_node arbre_noms, p_node arbre_verbes, p_node arbre_adjectifs, p_node arbre_adverbes){         //Fonction qui génére une phrase composée de forme fléchies choisies au hasard
    char nom[30];
    char verbe[30];
    char adjectif[30];
    char adverbe[30];
    /*ExtraireMotHasard(arbre_noms, nom);
    ExtraireMotHasard(arbre_verbes, verbe);
    ExtraireMotHasard(arbre_adjectifs, adjectif);
    ExtraireMotHasard(arbre_adverbes, adverbe);*/
}




