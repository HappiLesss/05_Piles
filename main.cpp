//
// Created by maxsc on 18.11.2026.
//

#include <iostream>
#include <array>
#include "function.h"
#include "affichage.h"
#include <array>
#include <limits>

int main () {
    // var capacite is defined in function.h
    unsigned short virtual_size= 5;
    std::array <int, capacite> ma_pile;
    init_array(ma_pile);
    std::array <int, capacite> ma_pile_backup = ma_pile;
    int selection =0;
    // print menu.
    affichage_menu();
    do{
        try{
            std::cin.clear();
            saisie(selection, "\n\nVotre choix : ", std::array <int, 2>{0,8});
            int new_value = 0;
            // setting up backup pile.
            ma_pile_backup = ma_pile;
            std::string feedback_value;
            switch (selection) {
                case 1:
                    // add element on top.
                    saisie(new_value, "Valeur : ",
                        std::array <int, 2>{std::numeric_limits<int>::min(),std::numeric_limits<int>::max()});
                    push(new_value, ma_pile,virtual_size);
                    break;
                case 2:
                    // remove top element.
                    feedback_value=std::to_string(pop(ma_pile,virtual_size));
                    break;
                case 3:
                    // return top value.
                    feedback_value = top(virtual_size,ma_pile);
                    break;
                case 4:
                    // replace top value.
                    saisie(new_value, "Valeur de remplacement : ",
                        std::array <int, 2>{std::numeric_limits<int>::min(),std::numeric_limits<int>::max()});
                    top(ma_pile,virtual_size) = new_value;
                    feedback_value = std::to_string(new_value);
                    break;
                case 5:
                    // check if the stack is empty.
                    feedback_value = empty(virtual_size)?"La pile est vide.":"La pile n'est pas vide.";
                    break;
                case 6:
                    // check the size of the stack.
                    feedback_value = std::to_string(size(virtual_size));
                    break;
                case 7:
                    // clear the stack.
                    clear(ma_pile, virtual_size);
                    break;
                case 8:
                    // print the stack from top to bottom.
                    print_pile(ma_pile,virtual_size);
                    break;
                default:
                    break;
            }
            // output return.
            affichage_retour(selection, feedback_value);
        }
        // interactions part.
        catch (std::exception& e){
            std::cout << "Erreur : " << e.what();
            ma_pile = ma_pile_backup;
        }
    }while (selection != 0);
    return EXIT_SUCCESS;

}
