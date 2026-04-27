#include "game.h"

#include <iostream>
#include <string>

#include "board.h"
#include "dice.h"
#include "losowanie.h"
#include "player.h"
#include "randomPole.h"

Game::Game() {}

void Game::Run() {
  int pola = 0;
  while (pola < 5) {
    std::cout << "Wyznacz ilość pol: " << std::endl;  // do klasy game
    std::cin >> pola;
  }
  board_ = new Board(pola);
  dice_ = new Dice(&los_);
  player1_ = new Player("Komputer");
  player2_ = new Player("Gracz");

  RandomPole pole(&los_, pola);

  int cel = pole.getPole();
  int jama = pole.getPole();
  while (jama == cel) {
    jama = pole.getPole();
  }
  board_->DrawFieldPossion(jama, cel);

  while (!CheckEndGame()) {
    NextTurn();
  }
  std::cout << "game is O V E R!" << std::endl;
}

void Game::NextTurn() {
  player1_->Move(dice_->Roll(), board_->GetSize());
  board_->HandlePlayerLand(player1_);
  if (CheckEndGame()) {
    return;
  }
  player2_->Move(dice_->Roll(), board_->GetSize());
  board_->HandlePlayerLand(player2_);
  if (CheckEndGame()) {
    return;
  }
  ShowStatus();
}
bool Game::CheckEndGame() {
  if (player1_->IsOut() || player2_->IsOut()) {
    return true;
  } else {
    return false;
  }
}
void Game::ShowStatus() {
  std::cout << player1_->PlayerName()
            << " position: " << player1_->GetPosition() << std::endl;
  std::cout << player2_->PlayerName()
            << " position: " << player2_->GetPosition() << std::endl;
}

Game::~Game() {
  delete board_;
  delete dice_;
  delete player1_;
  delete player2_;
}
