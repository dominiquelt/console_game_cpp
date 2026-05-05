#ifndef RANDOMPOLE_H
#define RANDOMPOLE_H

#include <random>

#include "losowanie.h"

class RandomPole {
 public:
  RandomPole(
      Losowanie* model,
      int liczbaPol);  // oporocz losowania musze przekazac jeszcze liczbe pol
  int RollRandomPosition();

 private:
  Losowanie* los_;
  std::uniform_int_distribution<> dist_;
};

#endif
