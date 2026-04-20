#include "board.h"

#include <vector>

#include "field.h"

Board::Board(int PolaGry) {
  fields_.resize(PolaGry);
}

int Board::GetSize() {
  return fields_.size();
}

void Board::DrawFieldPossion(int jama_index, int cel_index) {
  fields_[jama_index].SetType(1);
  fields_[cel_index].SetType(2);
}
