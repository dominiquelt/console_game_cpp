#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "board.h"

class Player {
 public:
  Player();
  void Move(int steps);

 private:
  int position_ = 0;
  std::string name_;
};

#endif
