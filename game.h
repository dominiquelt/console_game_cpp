#ifndef GAME_H
#define GAME_H

#include "losowanie.h"
class Dice;
class Player;
class Board;

class Game {
 public:
  Game();
  Game(const Game& other);
  Game& operator=(const Game& other);
  Game(Game&& other) noexcept;
  Game& operator=(Game&& other) noexcept;
  ~Game();
  void Run();

 private:
  void NextTurn();
  bool CheckEndGame();
  void ShowStatus();
  Losowanie los_;
  Dice* dice_ = nullptr;
  Board* board_ = nullptr;
  Player* player1_ = nullptr;
  Player* player2_ = nullptr;
};

#endif

// just a comment for a new branch
