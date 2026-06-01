#ifndef FIELDJAMA_H
#define FIELDJAMA_H

#include "field.h"

class Player;

class FieldJama : public Field {
 public:
  FieldJama();
  ~FieldJama() override = default;
  FieldJama(const FieldJama& other) = default;
  FieldJama& operator=(const FieldJama& other) = default;
  FieldJama(FieldJama&& other) noexcept = default;
  FieldJama& operator=(FieldJama&& other) noexcept = default;

  void OnLand(Player* p) override;

 private:
};

#endif
