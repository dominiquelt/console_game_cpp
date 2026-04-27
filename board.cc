#include "board.h"

#include <vector>

#include "field.h"
#include "player.h"

Board::Board(int PolaGry) {
  fields_.resize(PolaGry);
}

int Board::GetSize() {
  return fields_.size();
}

void Board::DrawFieldPossion(int jama_index, int cel_index) {
  fields_[jama_index].SetType(Field::kJama);
  fields_[cel_index].SetType(Field::kCel);
}

void Board::HandlePlayerLand(Player* p) {
  int pos = p->GetPosition();
  fields_[pos].OnLand(p);
}
