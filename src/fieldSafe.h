#ifndef FIELDSAFE_H
#define FIELDSAFE_H

#include "field.h"

class Player;

class FieldSafe : public Field {
 public:
  FieldSafe();
  ~FieldSafe() override = default;
  FieldSafe(const FieldSafe& other) = default;
  FieldSafe& operator=(const FieldSafe& other) = default;
  FieldSafe(FieldSafe&& other) noexcept = default;
  FieldSafe& operator=(FieldSafe&& other) noexcept = default;

  void OnLand(Player* p) override;

 private:
};

#endif
