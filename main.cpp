//
// Created by maxsc on 18.11.2026.
//

#include <iostream>
#include <array>
#include <limits>
#include <string>
#include "function.h"
#include "affichage.h"

int main () {
    // var capacite est defini dans notre function.h
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
            // récupération de la pile de sauvegarde
            ma_pile_backup = ma_pile;
            std::string feedback_value;
            switch (selection) {
                case 1:
                    // ajout de l'élément au sommet
                    saisie(new_value, "Valeur : ",
                        std::array <int, 2>{std::numeric_limits<int>::min(),std::numeric_limits<int>::max()});
                    push(new_value, ma_pile,virtual_size);
                    break;
                case 2:
                    // enlève l'élément au sommet
                    feedback_value=std::to_string(pop(ma_pile,virtual_size));
                    break;
                case 3:
                    // retourn la valeur au sommet
                    feedback_value = top(virtual_size,ma_pile);
                    break;
                case 4:
                    // remplace la valeur au sommet
                    saisie(new_value, "Valeur de remplacement : ",
                        std::array <int, 2>{std::numeric_limits<int>::min(),std::numeric_limits<int>::max()});
                    top(ma_pile,virtual_size) = new_value;
                    feedback_value = std::to_string(new_value);
                    break;
                case 5:
                    // check si la stack est vide
                    feedback_value = empty(virtual_size)?"La pile est vide.":"La pile n'est pas vide.";
                    break;
                case 6:
                    // check la taille de la stack
                    feedback_value = std::to_string(size(virtual_size));
                    break;
                case 7:
                    // clear la stack.
                    clear(virtual_size);
                    break;
                case 8:
                    // print la totalité de la stack
                    print_pile(ma_pile,virtual_size);
                    break;
                default:
                    break;
            }
            // output return.
            affichage_retour(selection, feedback_value);
        }
        // interactions, catch des erreurs
        catch (std::exception& e){
            std::cout << "Erreur : " << e.what();
            ma_pile = ma_pile_backup;
        }
    }
    while (selection != 0);
    return EXIT_SUCCESS;

}
