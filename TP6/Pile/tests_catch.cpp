#include "catch.hpp"
#include <sstream>
#include "Pile.hpp"

TEST_CASE("Constructeur par defaut") {
   Pile p; 

   CHECK(  p.empty() );
   CHECK(  0 == p.size() );
}


TEST_CASE("Exceptions de mauvaise construction") {
   // fait appel à une exception standard en cas d'erreur
   REQUIRE_THROWS_AS( Pile(-1).empty(), Pile::ExceptionPile);
   REQUIRE_THROWS_AS( Pile( 0).empty(), Pile::ExceptionPile);
}


TEST_CASE("Exception pile vide") {
   // fait appel à une exception standard en cas d'erreur
   REQUIRE_THROWS_AS( Pile().pop(), Pile::ExceptionPile);

}


TEST_CASE("Live pile") {
    Pile p(10);

    CHECK(  p.empty()     );
    CHECK(  0 == p.size() );

    p.push(5);

    CHECK( !p.empty()    );
    CHECK( 1 == p.size() );
    CHECK( 5 == p.top()  );

    p.push(2);
    p.push(1);

    CHECK( 3 == p.size() );
    CHECK( 1 == p.top()  );

    p.pop();

    CHECK( 2 == p.size() );
    CHECK( 2 == p.top()  );

    p.pop();
    p.pop();

    CHECK( 0 == p.size() );
}
