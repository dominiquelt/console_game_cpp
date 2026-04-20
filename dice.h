#ifndef DICE_H
#define DICE_H

#include <random>

#include "losowanie.h"

class Dice {
 public:
  Dice(Losowanie* model);
  int Roll();

 private:
  Losowanie* los_;  // kompoilator domysla sie ze tu chce stworzyc obiekt jesli
                    // istnieje konstruktor domyslny ()
  std::uniform_int_distribution<> dist_;
};

#endif
