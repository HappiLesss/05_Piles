//
// Created by lordelbardooo on 11/18/26.
//
#include <array>
#include <string>

#ifndef INC_05_PILES_FUNCTION_H
#define INC_05_PILES_FUNCTION_H
const unsigned short capacite =5;
void init_array(std::array<int, capacite>& stack);
void push(int new_element, std::array<int, capacite>& stack, unsigned short& virtual_size);
unsigned short size(unsigned virtual_size);
int pop(std::array<int,capacite >& stack, unsigned short& virtual_size);

int& top(std::array<int, capacite>& stack,unsigned short virtual_size);
std::string top(unsigned short virtual_size,const std::array<int, capacite>& stack);
bool empty( unsigned short& virtual_size);
void clear(unsigned short& virtual_size);

void print_pile(const std::array<int, capacite>& stack,unsigned short virtual_size);

#endif //INC_05_PILES_FUNCTION_H
