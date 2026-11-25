#include <array>
#include <iostream>
#include <string>
#include "affichage.h"
//
// Created by maxsc on 18.11.2026.
//
void help() {
    std::cout<<"Ce programme permet de manipuler une pile d'entiers."<<std::endl;
    std::cout<<"1 - Empiler"<<std::endl;
    std::cout<<"2 - Dépiler"<<std::endl;
    std::cout<<"3 - Consulter le sommet"<<std::endl;
    std::cout<<"4 - Modifier l'élément au sommet"<<std::endl;
    std::cout<<"5 - Vérifier si la pile est vide"<<std::endl;
    std::cout<<"6 - Afficher le nombre de valeurs"<<std::endl;
    std::cout<<"7 - Vider la pile"<<std::endl;
    std::cout<<"8 - Afficher toute la pile"<<std::endl;
    std::cout<<"0 - Quitter"<<std::endl;
    std::cout<<"Valeur : ";
}

void select_options(int selection)
{
    switch (selection)
    {
        case 0:
            break;
        case 1:
            //ta fonction
            break;
        case 2:
            //ta fonction
            break;
        case 3:
            //ta fonction
            break;
        case 4:
            //ta fonction
            break;
        case 5:
            //ta fonction
            break;
        case 6:
            //ta fonction
            break;
        case 7:
            //ta fonction
            break;
        case 8:
            //ta fonction
            break;
    }
    //return selection;
}
void affichage_retour (int selection, const std::string& feedback)
{
    std::array<std::string,12> options = {
        "Valeur empilée.",
        "Valeur retirée :",
        "Sommet :",
        "Valeur de remplacement :",
        "Valeur remplacée." ,
        "La pile n'est pas vide.",
        "La pile est vide.",
        "Sommet / Fond -> ",
        "Erreur : impossible de dépiler une pile vide.",
        "Nombre de valeurs : ",
        "Sommet -> ",
        "Fond   ->" };
    //return ;
    std::cout << options[selection] << feedback<< std::endl;
}

