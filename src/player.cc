#include "player.h"

#include <string>

// human

Human::Human(std::string name) : name_(name) {}

std::string Human::PlayerName() const {
  return name_;
}

int Human::GetPosition() const {
  return position_;
}

bool Human::IsOut() const {
  return is_out_;
}

void Human::SetOut(bool playerout) {
  is_out_ = playerout;
}

void Human::Move(int steps, int board_size) {
  position_ = (position_ + steps) % board_size;
}

// computer

Computer::Computer(std::string name) : name_(name) {}

std::string Computer::PlayerName() const {
  return name_;
}

int Computer::GetPosition() const {
  return position_;
}

bool Computer::IsOut() const {
  return is_out_;
}

void Computer::SetOut(bool playerout) {
  is_out_ = playerout;
}

void Computer::Move(int steps, int board_size) {
  position_ = (position_ + steps) % board_size;
}
