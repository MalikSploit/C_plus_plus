cmake_minimum_required(VERSION 3.26)
project(C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__
        TP6/Exceptions/main.cpp
        TP6/Exceptions/Chaine.cpp
        TP6/Exceptions/OutOfRangeException.cpp
        TP6/Exceptions/null_pointer.cpp
)
