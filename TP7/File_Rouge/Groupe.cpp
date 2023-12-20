//
// Created by root on 12/20/23.
//
#include "Forme.hpp"
#include <iostream>
#include <vector>

class [[maybe_unused]] Groupe : public Forme {
    std::vector<Forme*> membres;
public:
    [[nodiscard]] Groupe* clone() const override {
        auto* nouveauGroupe = new Groupe();
        for (const auto& membre : membres) {
            nouveauGroupe->ajouter(membre->clone());
        }
        return nouveauGroupe;
    }


    void ajouter(Forme* forme){
        membres.push_back(forme);
    }
};