#ifndef LOSOWANIE_H
#define LOSOWANIE_H

#include <iostream>
#include <random>

class Losowanie {
 public:
  Losowanie();
  std::mt19937* Getgenerator();

 private:
  std::random_device rd_;
  std::mt19937 gen_;
};

#endif
