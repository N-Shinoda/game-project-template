#include <gtest/gtest.h>

#include <game/game.hpp>

TEST(GameTest, IsInitialize_ReturnsTrue)
{
    game::Game game;

    EXPECT_TRUE(game.initialize());
}

TEST(GameTest, CanInitializeGame)
{
    game::Game game;

    ASSERT_TRUE(game.initialize());

    //game.run();
}