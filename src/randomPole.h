#ifndef RANDOMPOLE_H
#define RANDOMPOLE_H

#include <random>

#include "losowanie.h"

class IRandomPole {
 public:
  virtual ~IRandomPole() = default;
  virtual int RollRandomPosition() = 0;
};

class RandomPole : public IRandomPole {
 public:
  RandomPole(Losowanie* model, int liczbaPol);
  int RollRandomPosition() override;

  ~RandomPole() override = default;
  RandomPole(const RandomPole& other) = delete;
  RandomPole& operator=(const RandomPole& other) = delete;

  RandomPole(RandomPole&& other) noexcept = default;
  RandomPole& operator=(RandomPole&& other) noexcept = default;

 private:
  Losowanie* los_;
  std::uniform_int_distribution<> dist_;
};

#endif
