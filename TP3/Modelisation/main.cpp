//
// Created by root on 12/6/23.
//
#include "Statisticien.hpp"
#include "ProducteurPremiersEntiers.hpp"
#include "ProducteurAleatoire.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Producteur_Initialisation") {
    ProducteurPremiersEntiers p;
    REQUIRE( p.getTravail() == 0);
}

TEST_CASE("Producteur_travail2") {
    ProducteurPremiersEntiers p;
    p.produire(10, "test01.txt");
    p.produire(10, "test01.txt");
    p.produire(10, "test01.txt");
    REQUIRE ( p.getTravail() == 3);
}

TEST_CASE("Producteur_Travail3") {
    const int         DEMANDE    = 10;
    const std::string NOM_FICHIER("test01.txt");
    int               lecture, i;
    ProducteurPremiersEntiers        p;


    p.produire(DEMANDE, NOM_FICHIER);

    std::ifstream fichier(NOM_FICHIER.c_str());

    REQUIRE(fichier.is_open());

    if (!fichier.eof()) {
        fichier >> lecture;
        REQUIRE(DEMANDE == lecture);
        for (i = 0; i < DEMANDE; ++i) {
            fichier >> lecture;
            REQUIRE( lecture == (i+1) );
        }

        REQUIRE(i == DEMANDE);
        // CHECK(fichier.eof());
        fichier.close();

        REQUIRE(p.getTravail() == 1);
    }
}

TEST_CASE("Statisticien_Initialisation") {
    Statisticien p;
    REQUIRE_FALSE(p.estCalculDisponible());
}


void creerFichierTest(const std::string& nomFichier, const std::vector<int>& valeurs) {
    std::ofstream fichier(nomFichier);
    fichier << valeurs.size() << std::endl;
    for (int val : valeurs) {
        fichier << val << std::endl;
    }
}

TEST_CASE("Statisticien tests") {
    Statisticien stat;

    SECTION("Test avec un fichier vide") {
        creerFichierTest("vide.txt", {});
        stat.acquerir("vide.txt");
        REQUIRE_FALSE(stat.estCalculDisponible());
    }

    SECTION("Test avec un fichier de données valide") {
        creerFichierTest("donnees.txt", {1, 2, 3, 4, 5});
        stat.acquerir("donnees.txt");
        REQUIRE(stat.estCalculDisponible());
        REQUIRE(stat.getSomme() == 15);
        REQUIRE(stat.getMoyenne() == Approx(3.0));
    }

    SECTION("Test avec un fichier qui n'existe pas") {
        stat.acquerir("non_existant.txt");
        REQUIRE_FALSE(stat.estCalculDisponible());
    }
}

TEST_CASE("ProducteurAleatoire - Production de fichier avec valeurs aléatoires") {
    ProducteurAleatoire producteur;
    std::string nomFichier = "aleatoire.txt";
    int nombre = 5;

    SECTION("Produire un fichier avec des valeurs aléatoires") {
        producteur.produire(nombre, nomFichier);

        std::ifstream fichier(nomFichier);
        REQUIRE(fichier.is_open());

        int count;
        fichier >> count;
        REQUIRE(count == nombre);

        int val;
        int valeursLues = 0;
        while (fichier >> val) {
            valeursLues++;
        }

        REQUIRE(valeursLues == nombre);
        REQUIRE(producteur.getTravail() == 1);
    }
}