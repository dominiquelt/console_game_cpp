#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "field.h"
#include "losowanie.h"

class Board {
 public:
  Board(int PolaGry);  // Konstruktor
  // Field* getField(int index);
  void DrawFieldPossion(int jama_index, int cel_index);
  int GetSize();

 private:
  std::vector<Field> fields_;
};

#endif
