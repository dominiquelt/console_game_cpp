#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "field.h"

class Player;

class Board {
 public:
  Board(int PolaGry);

  void DrawFieldPossion(int jama_index, int cel_index);
  int GetSize();
  void HandlePlayerLand(Player* p);

  ~Board();

  Board(const Board& other);
  Board& operator=(const Board& other);

  Board(Board&& other) noexcept;
  Board& operator=(Board&& other) noexcept;

 private:
  std::vector<Field> fields_;
};

#endif
