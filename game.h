#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "dice.h"
#include "losowanie.h"
#include "player.h"

class Game {
 public:
  Game(int pola);
  Game(const Game& other) = delete;
  Game& operator=(const Game& other) = delete;
  Game(Game&& other) noexcept;
  Game& operator=(Game&& other) noexcept;
  ~Game();
  void Run();

 private:
  void ProcessTurn(Player* p);
  void NextTurn();
  bool CheckEndGame();
  void ShowStatus(const Player& p) const;
  Losowanie& los_;
  int pola_;
  Board board_;
  Dice dice_;
  Player player1_;
  Player player2_;
};

#endif
