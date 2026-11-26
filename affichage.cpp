#include <array>
#include <iostream>
#include <string>
#include "affichage.h"
//
// Created by maxsc on 18.11.2026.
//
void saisie(int& saisie, std::string message, std::array<int,2> range) {
    do {
        std::cout <<message;
        std::cin >> saisie;
    }while ((saisie < range[0] || saisie > range[1]) && saisie);
}
void affichage_menu() {
    std::cout<<"Ce programme permet de manipuler une pile d'entiers."<<std::endl;
    std::cout<<"1 - Empiler"<<std::endl;
    std::cout<<"2 - Dépiler"<<std::endl;
    std::cout<<"3 - Consulter le sommet"<<std::endl;
    std::cout<<"4 - Modifier l'élément au sommet"<<std::endl;
    std::cout<<"5 - Vérifier si la pile est vide"<<std::endl;
    std::cout<<"6 - Afficher le nombre de valeurs"<<std::endl;
    std::cout<<"7 - Vider la pile"<<std::endl;
    std::cout<<"8 - Afficher toute la pile"<<std::endl;
    std::cout<<"0 - Quitter";
}

void affichage_retour (int selection, const std::string& feedback)
{
    std::array<std::string,13> options = {
        "",
        "Valeur empilée.",
        "Valeur retirée : ",
        "Sommet : ",
        "Valeur remplacée : " ,
        "",
        "Nombre de valeurs : ",
        "Pile vidée.",
        "",
        ""};
    std::cout << options[selection] << feedback;
}