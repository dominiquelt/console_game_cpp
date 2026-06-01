#include "dice.h"

#include <random>

Dice::Dice(Losowanie* model) : los_(model), dist_(1, 6) {}
int Dice::Roll() {
  auto* gen = los_->Getgenerator();
  return dist_(*gen);
}

