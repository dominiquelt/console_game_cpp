#include "fieldJama.h"

#include <iostream>

#include "player.h"

FieldJama::FieldJama() {}

void FieldJama::OnLand(Player* p) {
  std::cout << "Wpadasz do jamy, przerywasz" << std::endl;
  p->SetOut(true);
}
