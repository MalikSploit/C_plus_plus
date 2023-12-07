cmake_minimum_required(VERSION 3.26)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__
        TP3/Modelisation/main.cpp
        TP3/Modelisation/ProducteurPremiersEntiers.cpp
        TP3/Modelisation/Producteur.cpp
        TP3/Modelisation/Statisticien.cpp
        TP3/Modelisation/ProducteurAleatoire.cpp)
