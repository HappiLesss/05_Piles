cmake_minimum_required(VERSION 4.3)
project(05_Piles)

set(CMAKE_CXX_STANDARD 14)

add_executable(05_Piles
        main.cpp
        function.cpp
        function.h
        constantes.h
        affichage.h
        gestion_erreurs.cpp
        gestion_erreurs.h
        affichage.cpp)
