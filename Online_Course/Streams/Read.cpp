//
// Created by malik on 12/26/2023.
//
#include <fstream>
#include <iostream>

int main(){
    //flags :: std::ios::in or std::ios::out
    std::ifstream infile("myfile.txt");
    if(infile){
        std::string line;
        while(std::getline(infile, line)){
            std::cout << line << "\n";
        }
    }
    else{
        std::cout << "file cannot be opened";
    }
}