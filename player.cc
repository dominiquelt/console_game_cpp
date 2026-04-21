#include "player.h"

#include <iostream>
#include <string>

#include "dice.h"

Player::Player(std::string n) {
  name_ = n;
  std::cout << "hej " << n << std::endl;
}

int Player::GetPosition() {
  return position_;
}
bool Player::GetState() {
  return is_out_;
}
void Player::SetOut(bool playerout) {
  is_out_ = playerout;
}

void Player::Move(int steps, int board_size) {
  position_ = (position_ + steps) % board_size;
}
