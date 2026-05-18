#ifndef FIELDSAFE_H
#define FIELDSAFE_H

#include "field.h"

class Player;

class FieldSafe : public Field {
 public:
  FieldSafe();
  ~FieldSafe() = default;
  void OnLand(Player* p) override;

 private:
};

#endif
