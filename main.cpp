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
int main () {
    unsigned short virtual_size= 4;
    std::array <int, capacite> ma_pile = {1,2,3,4,5};
    std::array <int, capacite> ma_pile_backup = ma_pile;
    unsigned short selection =0;
    //ma_pile.fill(get_zero());
    std::cout<<"Tableau : [";
    for (size_t i = 0; i <ma_pile.size(); i++)
    {
        std::cout<<ma_pile.at(i);
        if (i != ma_pile.size()-1)
        {
            std::cout<<", ";
        }
        /*if (ma_pile.at(i)!= get_zero())
        {
            virtual_size++;
        }*/
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"Compteur : "<<virtual_size<<std::endl;
    // print menu.
    help();
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
            switch (selection) {
                case 1:
                    std::cout<<"Valeur :";
                    std::cin>>new_value;
                    push(new_value, ma_pile,virtual_size);
                    break;
                case 2:
                    pop(ma_pile,virtual_size);
                    break;
                case 3:
                    std::cout << "Sommet : " << top(ma_pile,virtual_size) << std::endl;
                    break;
                case 4:
                    std::cout<<"Valeur :";
                    std::cin>>new_value;
                    top(ma_pile,virtual_size) = new_value;
                    std::cout<<"Valeur remplacée. " <<std::endl;
                    break;
                case 5:
                    std::cout <<(empty(ma_pile,virtual_size)?"La pile est vide.":"La pile n'est pas vide.") << std::endl;
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
        }
        catch (std::exception& e){
            std::cerr << "\nErreur : " << e.what() << std::endl;
            ma_pile = ma_pile_backup;
        }
    }
    while (selection != 0);
    return 0;

}
