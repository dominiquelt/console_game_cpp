#ifndef FIELDJAMA_H
#define FIELDJAMA_H

#include "field.h"

class Player;

class FieldJama : public Field {
 public:
  FieldJama();
  ~FieldJama() = default;
  void OnLand(Player* p) override;

 private:
};

#endif
