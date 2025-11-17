//
// Created by Elliott on 20/11/2022.
//

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

//choix a faire dans le menu
int choix(){
    int n;
    printf("1: RECHERCHER UNE FORME DE BASE\n2: RECHERCHER UN MOT\n3: GENERER UN MOT AU HASARD\n4: GENERER UNE PHRASE AU HASARD\n5: QUITTER\n");
    scanf("%d",&n);
    return n;
}


void menu(t_tree noms,t_tree verbes,t_tree adverbes,t_tree adjectifs){


    boolean fin = false;
    //relance le menu tant que l'utilisateur n'a pas choisi de quitter le programme
    while (!fin){

        int x = choix();
        if (x ==1){
            //verifie la presence d'un mot dans les arbres
            int present;
            char* recherche = calloc(30,sizeof(char));
            printf("Ecrivez un mot a rechercher :\n");
            scanf("%s", recherche);
            //recherche dans les arbres la presence d'un mot
            present = MotExiste(noms.root, recherche);
            present = present + MotExiste(verbes.root, recherche);
            present = present + MotExiste(adverbes.root, recherche);
            present = present + MotExiste(adjectifs.root, recherche);
            if (present >= 1) {
                printf("Le mot est bien present.\n\n");
            }
            else {
                printf("Le mot n'est pas present.\n\n");
            }
        }
        if (x ==2){
            //question 7 a faire ici
            fin = true;
        }
        if (x ==3){
            char mot1[30]="\0";
            char mot2[30]="\0";
            char mot3[30]="\0";
            char mot4[30]="\0";
            //choisi au hasard l'un des 4 arbres pour en afficher un mot aleatoire
            int n = rand() %4;
            if (n==0){
                ExtraireMotHasard(noms.root, mot1);
                printf("Le mot genere au hasard est : %s\n\n",mot1);
            }
            if (n==1){
                ExtraireMotHasard(verbes.root, mot2);
                printf("Le mot genere au hasard est : %s\n\n",mot2);
            }
            if (n==2){
                ExtraireMotHasard(adverbes.root, mot3);
                printf("Le mot genere au hasard est : %s\n\n",mot3);
            }
            if (n==3){
                ExtraireMotHasard(adjectifs.root, mot4);
                printf("Le mot genere au hasard est : %s\n\n",mot4);
            }
        }
        if (x ==4){

            char nom1[30]="\0";
            char nom2[30]="\0";
            char nom3[30]="\0";
            char nom4[30]="\0";
            char nom5[30]="\0";
            char nom6[30]="\0";
            char verbe1[30]="\0";
            char verbe2[30]="\0";
            char verbe3[30]="\0";
            char verbe4[30]="\0";
            char verbe5[30]="\0";
            char adjectif1[30]="\0";
            char adjectif2[30]="\0";
            char adjectif3[30]="\0";
            char adjectif4[30]="\0";
            char adverbe1[30]="\0";

            //choisir le modele de phrase a renvoyer
            int option;
            printf("Quel modele de phrase voulez-vous generer ?\n");
            printf("(entrer le numero associe)\n");
            printf(" \n");
            do {
                printf("1. forme de base : nom - adjectif - verbe - nom\n");
                printf("2. forme de base : nom - \"qui\" - verbe - verbe - nom - adjectif\n");
                printf("3. forme de base : nom - adjectif - verbe - adverbe - \"et\" - verbe - nom - adjectif \n");
                printf("4. forme flechie : nom - adjectif - verbe - nom\n");
                printf("5. forme flechie : nom - \"qui\" - verbe - verbe - nom - adjectif\n");
                printf("6. forme flechie : nom - adjectif - verbe - adverbe - \"et\" - verbe - nom - adjectif \n");
                printf("7. quitter\n");
                scanf("%d", &option);
            } while ((option < 1) || (option > 6));
            if (option == 1){
                ExtraireMotHasard(noms.root, nom1);
                ExtraireMotHasard(noms.root, nom2);
                ExtraireMotHasard(verbes.root, verbe1);
                ExtraireMotHasard(adjectifs.root, adjectif1);
                printf(" \n");
                printf("%s %s %s %s\n\n", nom1, adjectif1, verbe1, nom2);
            }
            if (option == 2){
                ExtraireMotHasard(noms.root, nom3);
                ExtraireMotHasard(noms.root, nom4);
                ExtraireMotHasard(verbes.root,verbe2);
                ExtraireMotHasard(verbes.root, verbe3);
                ExtraireMotHasard(adjectifs.root, adjectif2);
                printf(" \n");
                printf("%s qui %s %s %s %s\n\n", nom3, verbe2, verbe3, nom4, adjectif2);
            }
            if (option == 3){
                ExtraireMotHasard(noms.root, nom5);
                ExtraireMotHasard(noms.root, nom6);
                ExtraireMotHasard(verbes.root,verbe4);
                ExtraireMotHasard(verbes.root, verbe5);
                ExtraireMotHasard(adjectifs.root, adjectif3);
                ExtraireMotHasard(adjectifs.root, adjectif4);
                ExtraireMotHasard(adverbes.root, adverbe1);
                printf(" \n");
                printf("%s %s %s %s et %s %s %s\n\n", nom5, adjectif3, verbe3, adverbe1, verbe4, nom6, adjectif2);
            }
                if (option >3) {
                    //rajouter la creation de phrase en forme flechie ici
                    fin = true;
                    break;
                }
        }
        if (x ==5){
            //permet de quitter le programme
            fin = true;
        }
    }
}
