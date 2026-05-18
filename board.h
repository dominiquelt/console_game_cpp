#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>

#include "field.h"
#include "fieldCel.h"
#include "fieldJama.h"
#include "fieldSafe.h"

class Player;

class Board {
 public:
  Board(int PolaGry);

  void DrawFieldPossion(int jama_index, int cel_index);
  int GetSize();
  void HandlePlayerLand(Player* p);

  ~Board();

  Board(const Board& other) = delete;
  Board& operator=(const Board& other) = delete;

  Board(Board&& other) noexcept;
  Board& operator=(Board&& other) noexcept;

 private:
  std::vector<std::unique_ptr<Field>> fields_;
};

#endif
