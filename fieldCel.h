#ifndef FIELDCEL_H
#define FIELDCEL_H

#include "field.h"

class Player;

class FieldCel : public Field {
 public:
  FieldCel();
  ~FieldCel() = default;
  void OnLand(Player* p) override;

 private:
};

#endif
