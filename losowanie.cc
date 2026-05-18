#include "losowanie.h"

#include <random>

Losowanie::Losowanie() : gen_(rd_()) {}

std::mt19937* Losowanie::Getgenerator() {
  return &gen_;
}

Losowanie& Losowanie::GetInstance() {
  static Losowanie instance;  // created once, lives forever
  return instance;
}

Losowanie::~Losowanie() = default;
