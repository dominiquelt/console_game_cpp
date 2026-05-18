#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Board;

class Player {
 public:
  Player(std::string n);

  void Move(int steps, int board_size);
  void SetOut(bool playerout);
  bool IsOut() const;  // isout
  int GetPosition() const;
  std::string PlayerName() const;

  ~Player();
  Player(const Player& other);
  Player& operator=(const Player& other);
  Player(Player&& other) noexcept;
  Player& operator=(Player&& other) noexcept;

 private:
  int position_ = 0;
  std::string name_;
  bool is_out_ = false;
};

#endif
