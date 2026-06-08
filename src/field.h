#ifndef FIELD_H
#define FIELD_H

class Player;

class Field {
 public:
  virtual ~Field() = default;
  virtual void OnLand(Player* p) = 0;
};

#endif
