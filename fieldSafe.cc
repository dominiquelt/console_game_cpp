#include "fieldSafe.h"

#include <iostream>

#include "field.h"

FieldSafe::FieldSafe() {}

void FieldSafe::OnLand(Player* p) {
  std::cout << "Stoisz na bezpiecznym polu. Gramy dalej!" << std::endl;
}
