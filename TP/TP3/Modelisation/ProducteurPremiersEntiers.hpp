//
// Created by root on 12/7/23.
//

#ifndef C_PRODUCTEURPREMIERSENTIERS_HPP
#define C_PRODUCTEURPREMIERSENTIERS_HPP

#include "Producteur.hpp"

class ProducteurPremiersEntiers: public Producteur{
public:
    void produire(int nombre, const std::string& nomFichier) override;
};

#endif //C_PRODUCTEURPREMIERSENTIERS_HPP
