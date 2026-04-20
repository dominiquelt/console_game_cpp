#ifndef FIELD_H
#define FIELD_H

#include "player.h"

class Field {
 public:
  Field();
  void OnLand(Player* p);

 private:
  int number_;
};

#endif
