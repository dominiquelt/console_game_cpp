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

Game::Game(const Game& other)
    : board_(other.board_ ? new Board(*other.board_) : nullptr),
      dice_(other.dice_ ? new Dice(&los_) : nullptr),
      player1_(other.player1_ ? new Player(*other.player1_) : nullptr),
      player2_(other.player2_ ? new Player(*other.player2_) : nullptr) {
  std::cout << "[Kopiujacy] Gleboka kopia zasobu.\n";
}
Game& Game::operator=(const Game& other) {
  std::cout << "[Przypisanie kopiujace] Zwolnienie starego i kopia nowego.\n";
  if (this != &other) {
    delete board_;
    delete dice_;
    delete player1_;
    delete player2_;

    board_ = other.board_ ? new Board(*other.board_) : nullptr;
    dice_ = other.dice_ ? new Dice(&los_) : nullptr;
    player1_ = other.player1_ ? new Player(*other.player1_) : nullptr;
    player2_ = other.player2_ ? new Player(*other.player2_) : nullptr;
  }
  return *this;
}

Game::Game(Game&& other) noexcept
    : board_(other.board_),
      dice_(other.dice_),
      player1_(other.player1_),
      player2_(other.player2_) {
  std::cout << "[Przenoszacy] Przejęcie wskaźnika.\n";
  other.board_ = nullptr;
  other.dice_ = nullptr;
  other.player1_ = nullptr;
  other.player2_ = nullptr;
}

Game& Game::operator=(Game&& other) noexcept {
  std::cout << "[Przypisanie przenoszace] Zamiana wskaźników.\n";
  if (this != &other) {
    delete board_;
    delete dice_;
    delete player1_;
    delete player2_;

    board_ = other.board_;
    dice_ = other.dice_;
    player1_ = other.player1_;
    player2_ = other.player2_;

    other.board_ = nullptr;
    other.dice_ = nullptr;
    other.player1_ = nullptr;
    other.player2_ = nullptr;
  }
  return *this;
}

Game::~Game() {
  delete board_;
  delete dice_;
  delete player1_;
  delete player2_;
}
