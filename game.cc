#include "game.h"

#include <iostream>
#include <string>

#include "board.h"
#include "dice.h"
#include "losowanie.h"
#include "player.h"
#include "randomPole.h"

Game::Game(int pola)
    : los_(Losowanie::GetInstance()),
      pola_(pola),
      board_(pola),
      dice_(&los_),
      player1_("Komputer"),
      player2_("Gracz") {}

void Game::Run() {
  RandomPole pole(&los_, pola_);

  int cel = pole.RollRandomPosition();
  int jama = pole.RollRandomPosition();
  while (jama == cel) {
    jama = pole.RollRandomPosition();
  }
  board_.DrawFieldPossion(jama, cel);

  while (!CheckEndGame()) {
    NextTurn();
  }
  std::cout << "game is O V E R!" << std::endl;
}
void Game::ProcessTurn(Player* p) {
  p->Move(dice_.Roll(), board_.GetSize());
  board_.HandlePlayerLand(p);
}

void Game::NextTurn() {
  ProcessTurn(&player1_);
  if (CheckEndGame()) {
    return;
  }
  ProcessTurn(&player2_);
  if (CheckEndGame()) {
    return;
  }
  ShowStatus(player1_);
  ShowStatus(player2_);
}
bool Game::CheckEndGame() {
  if (player1_.IsOut() || player2_.IsOut()) {
    return true;
  } else {
    return false;
  }
}
void Game::ShowStatus(const Player& p) const {
  std::cout << p.PlayerName() << " position: " << p.GetPosition() << std::endl;
}

Game::Game(Game&& other) noexcept
    : los_(Losowanie::GetInstance()),
      board_(std::move(other.board_)),
      dice_(std::move(other.dice_)),
      player1_(std::move(other.player1_)),
      player2_(std::move(other.player2_)) {
  std::cout << "[Przenoszacy] Przejęcie zasobu.\n";
}

Game& Game::operator=(Game&& other) noexcept {
  std::cout << "[Przypisanie przenoszace] Zamiana zasobow.\n";
  if (this != &other) {
    board_ = std::move(other.board_);
    dice_ = std::move(other.dice_);
    player1_ = std::move(other.player1_);
    player2_ = std::move(other.player2_);
  }
  return *this;
}

Game::~Game() {}
