#include "player.h"

#include <iostream>
#include <string>

Player::Player(std::string n) {
  name_ = n;
  std::cout << "hej " << n << std::endl;
}

std::string Player::PlayerName() const {
  return name_;
}

int Player::GetPosition() const {
  return position_;
}
bool Player::IsOut() const {
  return is_out_;
}
void Player::SetOut(bool playerout) {
  is_out_ = playerout;
}

void Player::Move(int steps, int board_size) {
  position_ = (position_ + steps) % board_size;
}

Player::~Player() = default;
Player::Player(const Player& other) = default;
Player& Player::operator=(const Player& other) = default;
Player::Player(Player&& other) noexcept = default;
Player& Player::operator=(Player&& other) noexcept = default;
