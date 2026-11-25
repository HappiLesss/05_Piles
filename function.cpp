//
// Created by lordelbardooo on 11/18/26.
//
#include "function.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <exception>

void push(const int new_element,std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // check if the virtual size of stack is < than the max size of stack.
    if (virtual_size<stack.size()) {
        // push the element.
        stack.at(virtual_size) = new_element;
        virtual_size++;
        //std::cout << "Valeur empilée." << std::endl;
        return;
    }
    // we cant push any element.
    throw(std::overflow_error("Impossible d'empiler une pile pleine."));
}
int pop(std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // check if the virtual size is not null.
    if (virtual_size > 0) {
        // erase the last element of the stack.
        //std::cout << "Valeur retirée: " << stack.at(virtual_size-1) << std::endl;
        virtual_size--;
        return stack.at(virtual_size);
    }
    else {
        // suicide
        throw(std::underflow_error("Impossible de dépiler une pile vide."));
    }
    return 0;
}
int& top(std::array<int, capacite>& stack, const unsigned short virtual_size) {
    // this method returns the last element of the stack.
    if (virtual_size > 0) {
        return stack.at(virtual_size-1);
    }
    throw(std::underflow_error("Impossible de consulter le sommer d'une pile vide."));
}
bool empty(const std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // is the virtual size of stack null ?
    return virtual_size;
}
void clear(const std::array<int, capacite>& stack, unsigned short& virtual_size) {
    // setting the virtual size as 0.
    virtual_size = 0;
    //std::cout << "Pile vidée." << std::endl;
}

unsigned short size(const unsigned virtual_size) {
    // return the virtual size of the stack.
    return virtual_size;
}

void print_pile(const std::array<int, capacite>& stack, const unsigned short virtual_size) {
    std::string text_sommet = "Sommet ->";
    std::string text_fond = "Fond   ->";
    unsigned int num_spacing = std::max(text_sommet.length(), text_fond.length());
    std::string spacing = "";
    if (virtual_size == 0) {
        // virtual size is null.
        throw(std::underflow_error("Impossible d'afficher une pile vide."));
    }
    if (virtual_size == 1) {
        // the pile contains only one element.
        text_sommet = "Sommet/Fond ->";
    }
    // we be printing that pile !
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