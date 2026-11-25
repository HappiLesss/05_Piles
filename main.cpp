//
// Created by maxsc on 18.11.2026.
//

#include <iostream>
#include <array>
#include "function.h"
#include "affichage.h"
#include "constantes.h"
#include "function.h"
#include <array>
#include <iostream>
#include <limits>

int main () {
    unsigned short virtual_size= 4;
    std::array <int, capacite> ma_pile = {1,2,3,4,5};
    std::array <int, capacite> ma_pile_backup = ma_pile;
    unsigned short selection =0;

    // print menu.
    affichage_menu();
    do{
        try{
            do{
                // inputs manager.
                std::cout<< "\nVotre choix:" ;
                std::cin>>selection;
            }
            while ((selection < 0 || selection > 8) && selection);

            int new_value = 0;
            // setting up backup pile.
            ma_pile_backup = ma_pile;
            std::string feedback_value = "";
            switch (selection) {
                case 1:
                    std::cout<<"Valeur :";
                    std::cin>>new_value;
                    push(new_value, ma_pile,virtual_size);
                    break;
                case 2:
                    feedback_value=std::to_string(pop(ma_pile,virtual_size));
                    break;
                case 3:
                    feedback_value = std::to_string(top(ma_pile,virtual_size));
                    break;
                case 4:
                    std::cout<<"Valeur :";
                    std::cin>>new_value;
                    top(ma_pile,virtual_size) = new_value;
                    break;
                case 5:
                    feedback_value = (empty(ma_pile,virtual_size)?"La pile est vide.":"La pile n'est pas vide.");
                    break;
                case 6:
                    std::cout << size(virtual_size) << std::endl;
                    break;
                case 7:
                    clear(ma_pile, virtual_size);
                    break;
                case 8:
                    print_pile(ma_pile,virtual_size);
                    break;
                default:
                    break;
            }
            std::cout << feedback_value << std::endl;
            affichage_retour(selection-1, feedback_value);
        }
        catch (std::exception& e){
            std::cerr << "\nErreur : " << e.what() << std::endl;
            ma_pile = ma_pile_backup;
        }
    }
    while (selection != 0);
    return 0;

}
