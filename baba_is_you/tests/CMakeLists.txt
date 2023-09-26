cmake_minimum_required(VERSION 3.5)

add_executable(baba_is_you_tests
        main.cpp
        testGame.cpp
        testPosition.cpp
        #testMap.cpp
		testTile.cpp
        ../src/game.cpp
        ../src/tile.cpp
        ../src/map.cpp
        ../src/position.cpp
)
target_include_directories(baba_is_you_tests PRIVATE
    ../src
	../src/resources/levels
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
target_link_libraries(baba_is_you_tests Catch2::Catch2WithMain)
