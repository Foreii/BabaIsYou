#include "position.h"
#include <catch2/catch_test_macros.hpp>

using namespace model;

TEST_CASE("Position") {
    SECTION("Test getX() and getY()") {
        Position pos{1, 2};
        REQUIRE(pos.getX() == 1);
        REQUIRE(pos.getY() == 2);
    }

    SECTION("Test next()") {
        Position pos{1, 2};
        REQUIRE((pos.next(Direction::RIGHT) == Position{2, 2}));
        REQUIRE((pos.next(Direction::UP) == Position{1, 1}));
        REQUIRE((pos.next(Direction::LEFT) == Position{0, 2}));
        REQUIRE((pos.next(Direction::DOWN) == Position{1, 3}));
    }

    SECTION("Test move()") {
        Position pos{1, 2};
        pos.move(Direction::RIGHT);
        REQUIRE((pos == Position{2, 2}));
        pos.move(Direction::UP);
        REQUIRE((pos == Position{2, 1}));
        pos.move(Direction::LEFT);
        REQUIRE((pos == Position{1, 1}));
        pos.move(Direction::DOWN);
        REQUIRE((pos == Position{1, 2}));
    }

    SECTION("Test setPosition()") {
        Position pos{1, 2};
        pos.setPosition(3, 4);
        REQUIRE((pos == Position{3, 4}));
    }

    SECTION("Test operator==() and operator!=()") {
        Position pos1{1, 2};
        Position pos2{1, 2};
        Position pos3{3, 4};
        REQUIRE(pos1 == pos2);
        REQUIRE(pos1 != pos3);
    }
}
