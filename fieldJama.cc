#include "fieldJama.h"

#include <iostream>

#include "player.h"

FieldJama::FieldJama() {}

void FieldJama::OnLand(Player* p) {
  std::cout << "You fell into a pit, game over!" << std::endl;
  p->SetOut(true);
}
