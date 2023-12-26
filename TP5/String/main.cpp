//
// Created by root on 12/11/23.
//
#include <iostream>
#include <string>
#include "Chaine.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Constructeur par defaut") {
Chaine c;
REQUIRE( -1       == c.getCapacite());
REQUIRE(  nullptr == c.c_str()); // 0 ou NULL pour les vieux compilos
}


TEST_CASE("Verification des const sur les accesseurs") {
    const Chaine c;
    CHECK( -1       == c.getCapacite());
    CHECK(nullptr == c.c_str());
}


TEST_CASE("Constructeur par chaine C") {
    char  source []= "rien";
    Chaine c1(source);
    CHECK( (signed) strlen(source) == c1.getCapacite() );
    CHECK( 0 == strcmp(source, c1.c_str()) );

    Chaine c2 = "";
    CHECK( 0 == c2.getCapacite() );
    CHECK( 0 == strcmp("", c2.c_str()));
}


TEST_CASE("Constructeur avec capacite") {
    Chaine c1(6);
    CHECK( 6 == c1.getCapacite());
    CHECK( 0 == strlen(c1.c_str()));

    // Est-ce que la libération mémoire est faite ?
}


TEST_CASE("Constructeur de copie") {
    Chaine s1(10);   // une chaine vide
    Chaine s2 = s1;  // une autre chaine vide

    CHECK( s1.getCapacite() == s2.getCapacite());
    // tous les problemes vont venir de la
    // j'ai converti en void * uniquement pour l'affichage de catch
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));
}


TEST_CASE("methode afficher") {
    const char * original = "une chaine a tester";
    const Chaine c1(original);
    std::stringstream ss;

    c1.afficher(); // on verifie juste que ca compile
    std::cout << std::endl;
    c1.afficher(std::cout); // ca compile, mais pas d'interet pour les tests
    std::cout << std::endl;
    c1.afficher(ss); // utilisable pour les tests

    CHECK( ss.str() == original ); //  test de std::string :-)
}


TEST_CASE("operateur d'affectation") {
    Chaine s1("une premiere chaine");
    Chaine s2("une deuxieme chaine plus longue que la premiere");

    s1 = s2;

    CHECK( s1.getCapacite() == s2.getCapacite());
    CHECK( (void *)s1.c_str() != (void *)s2.c_str() );
    CHECK( 0 == strcmp(s1.c_str(), s2.c_str() ));

    s1 = s1; // est ce que cela va survivre a l execution ?
}


TEST_CASE("Surcharge <<") {
    const char * chaine = "une nouvelle surcharge";
    Chaine s(chaine);
    std::stringstream ss;
    ss << s;  // :-)

    CHECK( ss.str() == chaine ); //  test de std::string, again :-))
}