#ifndef FIELD_H
#define FIELD_H

class Player;

class Field {
 public:
  Field();
  void OnLand(Player* p);
  void SetType(int new_type);

 private:
  int number_;
  int type_ = 0;
};

#endif
