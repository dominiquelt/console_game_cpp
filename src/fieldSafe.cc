#include "fieldSafe.h"

#include <iostream>

#include "field.h"

FieldSafe::FieldSafe() {}

void FieldSafe::OnLand(Player* p) {
  std::cout << "Safe field. Keep playing!" << std::endl;
}
