#include "map.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Map") {
    model::Map map(1);

    SECTION("Test getHeight and getWidth") {
        REQUIRE(map.getHeight() == 18);
        REQUIRE(map.getWidth() == 18);
    }

    SECTION("Test removeTile") {
        model::Tile tile = map.getTile(model::Position(13, 8));
        map.removeTile(tile);
        REQUIRE(map.getTile(model::Position(13, 8)).getBlock() == model::Block::BACKGROUND);
    }

    SECTION("Test moveTile") {
        model::Tile tile = map.getTile(model::Position(13, 8));
        map.moveTile(tile, model::Direction::RIGHT);

        REQUIRE(map.getTile(model::Position(14, 8)).getBlock() == model::Block::BABA);
    }

    SECTION("Test getTile") {
        model::Tile tile = map.getTile(model::Position(100, 100));
        REQUIRE(tile.getBlock() == model::Block::BACKGROUND);
    }

    SECTION("Test initializeRules") {
        std::map<model::Tile, model::Tile> rules;
        map.initializeRules(rules);
        REQUIRE(rules.size() == 3);
    }

}

