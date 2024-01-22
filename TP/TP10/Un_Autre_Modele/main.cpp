//
// Created by root on 1/11/24.
//
#include <vector>
#include <memory>
#include "Mage.hpp"
#include "Chaman.hpp"

std::vector<std::unique_ptr<Sorcier>> sorciers;

void addSorcier(Sorcier* sorcier){
    sorciers.push_back(std::unique_ptr<Sorcier>(sorcier));
}

void castAllSpells(){
    for(auto& sorcier : sorciers){
        sorcier->ensorceler();
    }
}

int main() {
    addSorcier(new Mage("Gandalf"));
    addSorcier(new Chaman("Legolas"));

    castAllSpells();

    return 0;
}