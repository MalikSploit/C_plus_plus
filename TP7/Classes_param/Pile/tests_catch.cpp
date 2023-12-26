#include "catch.hpp"
#include <sstream>
#include "Pile.hpp"

using IntPile = Pile<int>;

TEST_CASE("Constructeur par defaut") {
    IntPile p;
    //Pile<int> p;

    CHECK( p.empty() );
    CHECK( 0 == p.size() );
}