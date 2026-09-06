add_executable(
    game_test
    game_test.cpp
)

target_link_libraries(
    game_test
    PRIVATE
        game
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(game_test)