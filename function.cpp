//
// Created by lordelbardooo on 11/18/26.
//
#include "function.h"
#include <iostream>
#include <array>
#include <algorithm>


void push(const int new_element,std::array<int, capacite>& stack, unsigned short& virtual_size) {
    //  Check si la taille de notre stack ne dépasse pas celle de notre taille virtuelle
    if (virtual_size<stack.size()) {
        // push le nouvel élément
        stack.at(virtual_size) = new_element;
        //incrémentation de notre compteur de size
        virtual_size++;
        return;
    }
    // we cant push any element.
    throw(std::overflow_error("Impossible d'empiler une pile pleine."));
}
int pop(std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // vérifie que notre taille virtuelle est non nulle
    if (virtual_size > 0) {
        // erase the last element of the stack.
        virtual_size--;
        //retourne la valeur que nous allons retirer
        return stack.at(virtual_size-1);
    }
    else {
        throw(std::underflow_error("Impossible de dépiler une pile vide."));
    }
    return 0;
}
int& top(std::array<int, capacite>& stack, const unsigned short virtual_size) {
    //Retourne le dernier élément de notre stack
    if (virtual_size > 0) {
        return stack.at(virtual_size-1);
    }
    throw(std::underflow_error("Impossible de consulter le sommer d'une pile vide."));
}
bool empty(unsigned short& virtual_size) {
    // retourne le test pour check si notre valeure est nulle
    return virtual_size;
}
void clear(unsigned short& virtual_size) {
    // setting the virtual size as 0.
    virtual_size = 0;
}

unsigned short size(const unsigned virtual_size) {
    // retourne la taille virtuelle de notre stack
    return virtual_size;
}

void print_pile(const std::array<int, capacite>& stack, const unsigned short virtual_size) {
    std::string text_sommet = "Sommet ->";
    std::string text_fond = "Fond   ->";
    unsigned int num_spacing = std::max(text_sommet.length(), text_fond.length());
    std::string spacing = "";
    if (virtual_size == 0) {
        // Retourne erreur si notre stack est vide
        throw(std::underflow_error("Impossible d'afficher une pile vide."));
    }
    if (virtual_size == 1) {
        // la pille ne contient que un élément
        text_sommet = "Sommet/Fond ->";
    }
    // impression de la pille
    for (int i = 0; i < num_spacing; ++i) {
        spacing += " ";
    }
    for (int i = virtual_size-1; i>=0; --i) {
        if (i == virtual_size-1) {
            std::cout << text_sommet;
            std::cout << stack.at(i) << std::endl;
        }
        else if (i == 0) {
            std::cout << text_fond;
            std::cout << stack.at(i) << std::endl;
        }
        else {
            std::cout << spacing << stack.at(i) << std::endl;
        }
    }
}