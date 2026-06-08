#include "fieldCel.h"

#include <iostream>

#include "player.h"

FieldCel::FieldCel() {}

void FieldCel::OnLand(Player* p) {
  std::cout << "You reached the goal, YOU WIN!" << std::endl;
  p->SetOut(true);
}
