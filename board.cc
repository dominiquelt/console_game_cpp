#include "board.h"

#include <vector>

#include "field.h"
#include "player.h"

Board::Board(int PolaGry) {
  for (int i = 0; i < PolaGry; i++) {
    fields_.push_back(std::make_unique<FieldSafe>());
  }
}

int Board::GetSize() {
  return fields_.size();
}

void Board::DrawFieldPossion(int jama_index, int cel_index) {
  fields_[jama_index] = std::make_unique<FieldJama>();
  fields_[cel_index] = std::make_unique<FieldCel>();
}

void Board::HandlePlayerLand(Player* p) {
  int pos = p->GetPosition();
  fields_[pos]->OnLand(p);
}
Board::~Board() = default;


Board::Board(Board&& other) noexcept = default;
Board& Board::operator=(Board&& other) noexcept = default;
