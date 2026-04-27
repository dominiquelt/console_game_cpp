#include "field.h"

#include <iostream>

#include "player.h"

Field::Field() {}

void Field::OnLand(Player* p) {
  if (type_ == kJama) {
    std::cout << "Wpadasz do jamy, przerywasz" << std::endl;
    p->SetOut(true);
  } else if (type_ == kCel) {
    std::cout << "Stoisz na polu cel, WYGRANA!" << std::endl;
    p->SetOut(true);
  } else {
    std::cout << "Stoisz na bezpiecznym polu. Gramy dalej!" << std::endl;
  }
}
void Field::SetType(FieldType new_type) {
  type_ = new_type;
}
