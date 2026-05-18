#ifndef FIELD_H
#define FIELD_H

class Player;

class Field {
 public:
  // enum FieldType { kSafe, kJama, kCel };
  Field();
  virtual ~Field() = default;
  Field(const Field& other) = delete;
  Field& operator=(const Field& other) = delete;
  Field(Field&& other) noexcept = delete;
  Field& operator=(Field&& other) noexcept = delete;

  virtual void OnLand(Player* p) = 0;
  // void SetType(FieldType new_type);

 private:
  // int number_;
  // FieldType type_ = kSafe;
};

#endif
