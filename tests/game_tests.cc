#include "game.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mocks.h"

using namespace ::testing;

class GameTests : public ::testing::Test {
 protected:
  void SetUp() override {
    game_ = std::make_unique<Game>(&dice_mock_, &board_mock_, &player1_mock_,
                                   &player2_mock_);
  }

  NiceMock<DiceMock> dice_mock_;
  NiceMock<BoardMock> board_mock_;
  NiceMock<PlayerMock> player1_mock_;
  NiceMock<PlayerMock> player2_mock_;
  NiceMock<RandomPoleMock> pole_mock_;
  std::unique_ptr<Game> game_;
};

TEST_F(GameTests, DrawFieldPossionCalledOnceWithCorrectArgs) {
  EXPECT_CALL(pole_mock_, RollRandomPosition())
      .WillOnce(Return(1))
      .WillOnce(Return(2));
  ON_CALL(player1_mock_, IsOut()).WillByDefault(Return(true));

  EXPECT_CALL(board_mock_, DrawFieldPossion(2, 1)).Times(1);

  game_->Run(&pole_mock_);
}

TEST_F(GameTests, NoDiceRollWhenPlayer1IsOutBeforeFirstTurn) {
  EXPECT_CALL(pole_mock_, RollRandomPosition())
      .WillOnce(Return(1))
      .WillOnce(Return(2));
  ON_CALL(player1_mock_, IsOut()).WillByDefault(Return(true));

  EXPECT_CALL(dice_mock_, Roll()).Times(0);

  game_->Run(&pole_mock_);
}

TEST_F(GameTests, RerollsWhenJamaEqualsCell) {
  EXPECT_CALL(pole_mock_, RollRandomPosition())
      .WillOnce(Return(3))
      .WillOnce(Return(3))
      .WillOnce(Return(5));
  ON_CALL(player1_mock_, IsOut()).WillByDefault(Return(true));

  EXPECT_CALL(board_mock_, DrawFieldPossion(5, 3)).Times(1);

  game_->Run(&pole_mock_);
}
