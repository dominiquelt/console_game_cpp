#include "field.h"

#include <iostream>

#include "player.h"

Field::Field() = default;

/*void Field::OnLand(Player* p) {
  switch (type_) {
    case kJama:
      std::cout << "Wpadasz do jamy, przerywasz" << std::endl;
      p->SetOut(true);
      break;
    case kCel:
      std::cout << "Stoisz na polu cel, WYGRANA!" << std::endl;
      p->SetOut(true);
      break;
    default:
      std::cout << "Stoisz na bezpiecznym polu. Gramy dalej!" << std::endl;
      break;
  }
}*/

/*void Field::SetType(FieldType new_type) {
  type_ = new_type;
}*/
