#ifndef FIELD_H
#define FIELD_H

class Player;

class Field {
 public:
  enum FieldType {
    kSafe,  // automatically = 0
    kJama,  // automatically = 1
    kCel    // automatically = 2
  };
  Field();
  void OnLand(Player* p);
  void SetType(FieldType new_type);

 private:
  int number_;
  FieldType type_ = kSafe;
};

#endif
