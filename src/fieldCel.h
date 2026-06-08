#ifndef FIELDCEL_H
#define FIELDCEL_H

#include "field.h"

class Player;

class FieldCel : public Field {
 public:
  FieldCel();
  ~FieldCel() override = default;
  FieldCel(const FieldCel& other) = default;
  FieldCel& operator=(const FieldCel& other) = default;
  FieldCel(FieldCel&& other) noexcept = default;
  FieldCel& operator=(FieldCel&& other) noexcept = default;

  void OnLand(Player* p) override;

 private:
};

#endif
