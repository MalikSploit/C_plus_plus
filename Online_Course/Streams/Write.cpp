//
// Created by malik on 12/26/2023.
//
#include <fstream>
#include <iostream>

int main(){
    //std::ios::app to append to the file
    std::ofstream outfile("myfile.txt");
    if (outfile){
        std::cout << "Please enter the content you want for each line in the file and type 'END' to stop writing :" << std::endl;
        int line = 0;
        std::string input;
        std::cout << "line " + std::to_string(line) + ":";

        while(std::getline(std::cin, input) &&  input != "END"){
            ++line;
            std::cout << "line " + std::to_string(line) + ":";
            outfile << input << std::endl;
        }
        outfile.close();
    }
    else{
        std::cout << "Error creating file";
    }
}