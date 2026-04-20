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

void Move(int steps, int board_size) {}

/*  while (is_out != true) {
    std::cout << "Rzucam kostka" << std::endl;
    rzut = dice.Roll();
    pole_komputer = pole_komputer + rzut;
    if (pole_komputer >= pola) {
      pole_komputer = pole_komputer - pola;
    }
    std::cout << "teraz stoje na polu: " << pole_komputer << std::endl;
    if (pole_komputer == jama || pole_komputer == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    } else {
      std::cout << "twoj rzut, 1" << std::endl;
    }
    rzut = dice.Roll();
    pole_user = pole_user + rzut;
    if (pole_user >= pola) {
      pole_user = pole_user - pola;
    }
    std::cout << "teraz stoisz na polu: " << pole_user << std::endl;
    if (pole_user == jama || pole_user == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    } else {
      std::cout << "teraz ja" << std::endl;
    }
  }*/
