#ifndef FIELD_H
#define FIELD_H

class Player;

class Field {
 public:
  enum FieldType { kSafe, kJama, kCel };
  Field();
  ~Field();

  Field(const Field& other);
  Field& operator=(const Field& other);

  Field(Field&& other) noexcept;
  Field& operator=(Field&& other) noexcept;
  void OnLand(Player* p);
  void SetType(FieldType new_type);

 private:
  int number_;
  FieldType type_ = kSafe;
};

#endif
