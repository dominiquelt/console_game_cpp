#ifndef LOSOWANIE_H
#define LOSOWANIE_H

#include <iostream>
#include <random>

class Losowanie {
 public:
  static Losowanie& GetInstance();
  std::mt19937* Getgenerator();
  ~Losowanie() = default;
  Losowanie(const Losowanie&) = delete;
  Losowanie& operator=(const Losowanie&) = delete;

  Losowanie(Losowanie&& other) noexcept = delete;
  Losowanie& operator=(Losowanie&& other) noexcept = delete;

 private:
  Losowanie();
  std::random_device rd_;
  std::mt19937 gen_;
};

#endif
