#include "game.h"

#include <iostream>
#include <string>

#include "board.h"
#include "dice.h"
#include "player.h"
#include "randomPole.h"

Game::Game(IDice* dice, IBoard* board, Player* player1, Player* player2)
    : board_(board),
      dice_(dice),
      player1_(player1),
      player2_(player2) {}

void Game::Run(IRandomPole* pole) {
  int cel = pole->RollRandomPosition();
  int jama = pole->RollRandomPosition();
  while (jama == cel) {
    jama = pole->RollRandomPosition();
  }
  board_->DrawFieldPossion(jama, cel);

  while (!CheckEndGame()) {
    NextTurn();
  }
  std::cout << "game is O V E R!" << std::endl;
}

void Game::ProcessTurn(Player* p) {
  p->Move(dice_->Roll(), board_->GetSize());
  board_->HandlePlayerLand(p);
}

void Game::NextTurn() {
  ProcessTurn(player1_);
  if (CheckEndGame()) {
    return;
  }
  ProcessTurn(player2_);
  if (CheckEndGame()) {
    return;
  }
  ShowStatus(*player1_);
  ShowStatus(*player2_);
}

bool Game::CheckEndGame() {
  if (player1_->IsOut() || player2_->IsOut()) {
    return true;
  } else {
    return false;
  }
}

void Game::ShowStatus(const Player& p) const {
  std::cout << p.PlayerName() << " position: " << p.GetPosition() << std::endl;
}

Game::~Game() {}
