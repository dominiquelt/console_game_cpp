#include "fieldCel.h"

#include <iostream>

#include "player.h"

FieldCel::FieldCel() {}

void FieldCel::OnLand(Player* p) {
  std::cout << "Stoisz na polu cel, WYGRANA!" << std::endl;
  p->SetOut(true);
}
