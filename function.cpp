//
// Created by lordelbardooo on 11/18/26.
//
#include "function.h"
#include <iostream>
#include <array>
#include <algorithm>


void init_array(std::array<int, capacite>& stack) {
    stack.fill(0);
}

void push(const int new_element,std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // vérifie que la taille de notre stack ne dépasse pas notre taille virtuelle
    if (virtual_size<stack.size()) {
       //push le nouvel éléments
        stack.at(virtual_size) = new_element;
        virtual_size++;
        return;
    }
    // Si la stack est pleine, remonte le message d'erreur
    throw(std::overflow_error("Impossible d'empiler une pile pleine."));
}
int pop(std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // vérification si notre stack n'est pas vide
    if (virtual_size > 0) {
        // pop le dernier éléments de notre stack
        virtual_size--;
        return stack.at(virtual_size);
    }
    //si notre stack est vide, remonte une erreur
    throw(std::underflow_error("Impossible de dépiler une pile vide."));
    return 0;
}
int& top(std::array<int, capacite>& stack, const unsigned short virtual_size) {
    // remplacement du dernier éléments de notre stack
    if (virtual_size > 0) {
        return stack.at(virtual_size-1);
    }
    else {
        //retour du message d'erreur si notre pile est vide
        throw(std::underflow_error("Impossible de remplacer le sommet d'une pile vide."));
    }
}
std::string top(const unsigned short virtual_size,const std::array<int, capacite>& stack) {
    // permet de retourner l'éléments au sommet de notre pile
    if (virtual_size > 0) {
        return std::to_string(stack.at(virtual_size-1));
    }
    throw(std::underflow_error("Impossible de consulter le sommer d'une pile vide."));
}
bool empty(unsigned short& virtual_size) {
    // si la taille est vide, il retourne true
    return !virtual_size;
}
void clear(unsigned short& virtual_size) {
    // set la vitual size à 0
    virtual_size = 0;
}

unsigned short size(const unsigned virtual_size) {
    // retourne la taille de notre stack
    return virtual_size;
}

void print_pile(const std::array<int, capacite>& stack, const unsigned short virtual_size) {
    std::string text_sommet = "Sommet ->";
    std::string text_fond = "Fond   ->";
    unsigned int num_spacing = std::max(text_sommet.length(), text_fond.length());
    std::string spacing = "";
    if (virtual_size == 0) {
        // retourne le message d'erreur si notre pile est vide
        throw(std::underflow_error("Impossible d'afficher une pile vide."));
    }
    if (virtual_size == 1) {
        // impression si notre stack contient un seul élément
        text_sommet = "Sommet/Fond ->";
    }
    // impression de la pille
    for (int i = 0; i < num_spacing; ++i) {
        spacing += " ";
    }
    for (int i = virtual_size-1; i>=0; --i) {
        //Impression du sommet
        if (i == virtual_size-1) {
            std::cout << text_sommet;
            std::cout << stack.at(i) << std::endl;
        }
        else if (i == 0) {
            //Impression du fond de la pile
            std::cout << text_fond;
            std::cout << stack.at(i) << std::endl;
        }
        else {
            //impression de tous les éléments autre que le sommet et la pile
            std::cout << spacing << stack.at(i) << std::endl;
        }
    }
}