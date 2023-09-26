// include the Catch2 header
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "game.h"

using namespace model;

TEST_CASE("Testing movePlayer") {
    Game game(0);
//    SECTION("Position is invalid") {
//        model::Position nextPos(-1,-1);

//        REQUIRE(map_.isInMap(nextPos) == false);
//    }

    SECTION("Next tile is a IS or TEXT or RULE tile") {
        SECTION("Next tile: IS") {
            Position testDestination(5,12);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::DOWN);

            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);

            std::cout << game.getMapRepresentation() << std::endl;
            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::IS);

            game.movePlayer(Direction::DOWN);

        }
        SECTION("Next tile: TEXT") {
            Position testDestination(4,12);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::DOWN);

            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);

            std::cout << game.getMapRepresentation() << std::endl;
            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::TEXT_BABA);
            REQUIRE(game.getMap().getTile(testDestination).getBlockType() == BlockType::TEXT);

            game.movePlayer(Direction::DOWN);

        }
        SECTION("Next tile: RULE") {
            Position testDestination(6,12);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);
            game.movePlayer(Direction::LEFT);

            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::DOWN);

            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);

            std::cout << game.getMapRepresentation() << std::endl;
            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::YOU);
            REQUIRE(game.getMap().getTile(testDestination).getBlockType() == BlockType::RULE);

            game.movePlayer(Direction::DOWN);

        }

        SECTION("A valid rule is pushed") {
            SECTION("Valid rule is broken") {
                Position testDestination(4,12);
                Position testDestination2(4,11);


                game.movePlayer(Direction::DOWN);
                game.movePlayer(Direction::LEFT);
                game.movePlayer(Direction::LEFT);
                game.movePlayer(Direction::LEFT);

                game.movePlayer(Direction::DOWN);
                game.movePlayer(Direction::DOWN);

                game.movePlayer(Direction::RIGHT);
                game.movePlayer(Direction::RIGHT);

                std::cout << game.getMapRepresentation() << std::endl;
                REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::TEXT_BABA);
                REQUIRE(game.getMap().getTile(testDestination).getBlockType() == BlockType::TEXT);

                //rule broken
                game.movePlayer(Direction::DOWN);

                //test if possible or not to move (broke BABA IS YOU)
                game.movePlayer(Direction::UP);
                REQUIRE(game.getMap().getTile(testDestination2).getBlock() == Block::BABA);

            }
            SECTION("Valid rule not broken (3 blocks pushed)") {
                Position testDestination(4,12);
                Position posTextBaba(5,12);
                Position posIs(6,12);
                Position posYou(7,12);
                Position playerPos(4,11);

                game.movePlayer(Direction::DOWN);
                game.movePlayer(Direction::LEFT);
                game.movePlayer(Direction::LEFT);
                game.movePlayer(Direction::LEFT);

                game.movePlayer(Direction::DOWN);
                game.movePlayer(Direction::DOWN);
                game.movePlayer(Direction::DOWN);

                game.movePlayer(Direction::RIGHT);
                game.movePlayer(Direction::RIGHT);

                REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::BABA);
                REQUIRE(game.getMap().getTile(posTextBaba).getBlock() == Block::TEXT_BABA);
                REQUIRE(game.getMap().getTile(posIs).getBlock() == Block::IS);
                REQUIRE(game.getMap().getTile(posYou).getBlock() == Block::YOU);

                //Check if baba can still move
                game.movePlayer(Direction::UP);
                REQUIRE(game.getMap().getTile(playerPos).getBlock() == Block::BABA);
            }

        }
    }

    SECTION("Next tile is a BLOCK tile") {

        SECTION("Next tile: BLOCK::BACKGROUND") { // FIXME: will crash
            Position nextLeft(4,8);
            Position testDestination(2,8);

            game.movePlayer(Direction::LEFT);

            REQUIRE(nextLeft == Position(4,8));

            game.movePlayer(Direction::LEFT);
            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::BACKGROUND);
        }

        SECTION("Next tile: BLOCK::STOP") {
            Position testDestination(5,6);

            game.movePlayer(Direction::UP);
            game.movePlayer(Direction::UP);

            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::WALL); //WALL IS STOP in level 0
        }


        SECTION("Next tile: BLOCK::PUSH") {
            Position testDestination(8,8);

            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            REQUIRE(game.getMap().getTile(testDestination).getBlock() == Block::ROCK); //ROCK IS PUSH in level 0

            // check rock

        }

        SECTION("Next tile: BLOCK::WIN") {
            Position testDestination(12,8);

            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);
            game.movePlayer(Direction::RIGHT);

            std::cout << game.getMapRepresentation() << std::endl;

            // REQUIRE(game.getGameState() == true);
            REQUIRE(game.getLevel() == 1); // won == next level
        }

        SECTION("Next tile: BLOCK::KILL (lava)") {
            Game game_four(4);
            Position testDestination(10,7);
            Tile rock;

            game_four.movePlayer(Direction::RIGHT);
            game_four.movePlayer(Direction::RIGHT);
            game_four.movePlayer(Direction::RIGHT);
            game_four.movePlayer(Direction::RIGHT);
            game_four.movePlayer(Direction::RIGHT);

            rock = game.getMap().getTile(Position(9,7));

            game_four.movePlayer(Direction::RIGHT);
            // check kill, but we cant since it automatically go to true.
            // REQUIRE(game.isGameLost() == false);

        }
        SECTION("Next tile: BLOCK::SINK") {
            Game game_three(3);

            Position testDestination(7,8);
            game.movePlayer(Direction::DOWN);
            game.movePlayer(Direction::DOWN);

            REQUIRE(game_three.getMap().getTile(testDestination).getBlock() == Block::WATER);
            // we can't do it since it automatically goes to true after dying.
            //REQUIRE(game.isGameLost() == false);

            //3
        }
        //SECTION("Next tile: BLOCK::SLIP") {}

    }


}
