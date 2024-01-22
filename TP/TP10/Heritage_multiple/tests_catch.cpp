#include "catch.hpp"
#include "Humain.hpp"
#include "Machine.hpp"
#include "Humanoide.hpp"

TEST_CASE("Humain1") {
    const char * nom ="Alex";
    const Humain alex(nom, Genre::Homme, 35);

    CHECK( nom   == alex.getNom()   );
    CHECK( Genre::Homme == alex.getGenre() );
    CHECK( 35    == alex.getAge()   );
}


TEST_CASE("Humain2") {
    Humain thomas("thomas", Genre::Homme, 26);

    thomas.setNom("conchita");
    thomas.setAge(27);
    thomas.setGenre(Genre::Femme);

    CHECK( "conchita" == thomas.getNom()   );
    CHECK( Genre::Femme      == thomas.getGenre() );
    CHECK( 27         == thomas.getAge()   );
}

TEST_CASE("Machine") {
    Machine stylet("stylet Apple", 2*24*3600, 1);

    CHECK( "stylet Apple" == stylet.getType()      );
    CHECK( 2*24*3600      == stylet.getAutonomie() );
    CHECK( 1              == stylet.getIfixit()    );
}

TEST_CASE("Robocop") {
    Humanoide robocop("Murphy", "Robocop 1.0", Genre::Homme, 35);

    CHECK( "Murphy"      == robocop.getNom()    );
    CHECK( "Robocop 1.0" == robocop.getType()   );
    CHECK( Genre::Homme         == robocop.getGenre()  );
    std::cout << robocop.getAge() << std::endl;
    std::cout << robocop.getIfixit() << std::endl;
    CHECK( 35            == robocop.getAge()    );
    CHECK( 3             == robocop.getIfixit() );
}
