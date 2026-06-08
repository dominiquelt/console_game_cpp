#pragma once

#include <gmock/gmock.h>

#include "board.h"
#include "dice.h"
#include "player.h"
#include "randomPole.h"

class DiceMock : public IDice {
 public:
  MOCK_METHOD(int, Roll, (), (override));
};

class BoardMock : public IBoard {
 public:
  MOCK_METHOD(void, DrawFieldPossion, (int, int), (override));
  MOCK_METHOD(int, GetSize, (), (override));
  MOCK_METHOD(void, HandlePlayerLand, (Player*), (override));
};

class PlayerMock : public Player {
 public:
  MOCK_METHOD(void, Move, (int, int), (override));
  MOCK_METHOD(void, SetOut, (bool), (override));
  MOCK_METHOD(bool, IsOut, (), (const, override));
  MOCK_METHOD(int, GetPosition, (), (const, override));
  MOCK_METHOD(std::string, PlayerName, (), (const, override));
};

class RandomPoleMock : public IRandomPole {
 public:
  MOCK_METHOD(int, RollRandomPosition, (), (override));
};
