#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "dice.h"
#include "player.h"
#include "randomPole.h"

class Game {
 public:
  Game(IDice* dice, IBoard* board, Player* player1, Player* player2);
  Game(const Game& other) = delete;
  Game& operator=(const Game& other) = delete;
  Game(Game&& other) noexcept = default;
  Game& operator=(Game&& other) noexcept = default;
  ~Game();
  void Run(IRandomPole* pole);

 private:
  void ProcessTurn(Player* p);
  void NextTurn();
  bool CheckEndGame();
  void ShowStatus(const Player& p) const;
  IBoard* board_;
  IDice* dice_;
  Player* player1_;
  Player* player2_;
};

#endif
