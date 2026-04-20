#include "field.h"

#include <iostream>

#include "player.h"

Field::Field() {}

void Field::OnLand(Player* p) {
  if (type_ == 1) {
    std::cout << "Wpadasz do jamy, przerywasz" << std::endl;
  } else if (type_ == 2) {
    std::cout << "Stoisz na polu cel, WYGRANA!" << std::endl;
  } else {
    std::cout << "Stoisz na bezpiecznym polu." << std::endl;
  }
}
void Field::SetType(int new_type) {
  type_ = new_type;
}
