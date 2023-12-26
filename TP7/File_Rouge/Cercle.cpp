//
// Created by root on 12/20/23.
//

#include "Forme.hpp"

class [[maybe_unused]] Cercle : public Forme {
public:
    [[nodiscard]] Cercle* clone() const override {
        return new Cercle(*this);
    }
};
