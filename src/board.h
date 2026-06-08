#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>

#include "field.h"
#include "fieldCel.h"
#include "fieldJama.h"
#include "fieldSafe.h"

class Player;

class IBoard {
 public:
  virtual ~IBoard() = default;
  virtual void DrawFieldPossion(int jama_index, int cel_index) = 0;
  virtual int GetSize() = 0;
  virtual void HandlePlayerLand(Player* p) = 0;
};

class Board : public IBoard {
 public:
  Board(int PolaGry);
  ~Board() override = default;
  void DrawFieldPossion(int jama_index, int cel_index) override;
  int GetSize() override;
  void HandlePlayerLand(Player* p) override;

  Board(const Board& other) = delete;
  Board& operator=(const Board& other) = delete;

  Board(Board&& other) noexcept = default;
  Board& operator=(Board&& other) noexcept = default;

 private:
  std::vector<std::unique_ptr<Field>> fields_;
};

#endif
