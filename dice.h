#ifndef DICE_H
#define DICE_H

#include <random>

#include "losowanie.h"

class IDice {
 public:
  virtual ~IDice() = default;
  virtual int Roll() = 0;
};

class Dice : public IDice {
 public:
  Dice(Losowanie* model);
  ~Dice() override = default;
  int Roll() override;

  Dice(const Dice& other) = delete;
  Dice& operator=(const Dice& other) = delete;

  Dice(Dice&& other) noexcept = default;
  Dice& operator=(Dice&& other) noexcept = default;

 private:
  Losowanie* los_;
  std::uniform_int_distribution<> dist_;
};

#endif
