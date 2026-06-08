#include "randomPole.h"

#include <random>

#include "losowanie.h"

RandomPole::RandomPole(Losowanie* model, int liczbaPol)
    : los_(model), dist_(0, liczbaPol - 1) {}

int RandomPole::RollRandomPosition() {
  return dist_(*los_->Getgenerator());
}

