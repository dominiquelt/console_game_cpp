#include "losowanie.h"

#include <random>

Losowanie::Losowanie() : gen_(rd_()) {}

std::mt19937* Losowanie::Getgenerator() {
  return &gen_;
}
