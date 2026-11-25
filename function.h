//
// Created by lordelbardooo on 11/18/26.
//
#include <array>
#include <iostream>
#include <string>
#include <cmath>
#include <exception>

#ifndef INC_05_PILES_FUNCTION_H
#define INC_05_PILES_FUNCTION_H
const unsigned short capacite =5;
void push(const int new_element, std::array<int, capacite>& stack, unsigned short& virtual_size);
unsigned short size(const unsigned virtual_size);
unsigned short get_capactite();
int pop(std::array<int,capacite >& stack, unsigned short& virtual_size);

int& top(std::array<int, capacite>& stack,const unsigned short virtual_size);
bool empty(const std::array<int, capacite>& stack, unsigned short& virtual_size);
void clear(const std::array<int, capacite>& stack, unsigned short& virtual_size);

void print_pile(const std::array<int, capacite>& stack, const unsigned short virtual_size);

#endif //INC_05_PILES_FUNCTION_H
