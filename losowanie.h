#ifndef LOSOWANIE_H
#define LOSOWANIE_H

#include <iostream>
#include <random>

class Losowanie {
 public:
  static Losowanie& GetInstance();
  std::mt19937* Getgenerator();
  Losowanie(const Losowanie&) = delete;
  Losowanie& operator=(const Losowanie&) = delete;

 private:
  Losowanie();
  std::random_device rd_;
  std::mt19937 gen_;
};

#endif
