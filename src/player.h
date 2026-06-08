#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Board;

class Player {
 public:
  virtual ~Player() = default;
  virtual void Move(int steps, int board_size) = 0;
  virtual void SetOut(bool playerout) = 0;
  virtual bool IsOut() const = 0;
  virtual int GetPosition() const = 0;
  virtual std::string PlayerName() const = 0;
};

class Human : public Player {
 public:
  Human(std::string name);
  ~Human() override = default;
  Human(const Human&) = default;
  Human& operator=(const Human&) = default;
  Human(Human&&) noexcept = default;
  Human& operator=(Human&&) noexcept = default;

  void Move(int steps, int board_size) override;
  void SetOut(bool playerout) override;
  bool IsOut() const override;
  int GetPosition() const override;
  std::string PlayerName() const override;

 private:
  int position_ = 0;
  std::string name_;
  bool is_out_ = false;
};

class Computer : public Player {
 public:
  Computer(std::string name);
  ~Computer() override = default;
  Computer(const Computer&) = default;
  Computer& operator=(const Computer&) = default;
  Computer(Computer&&) noexcept = default;
  Computer& operator=(Computer&&) noexcept = default;

  void Move(int steps, int board_size) override;
  void SetOut(bool playerout) override;
  bool IsOut() const override;
  int GetPosition() const override;
  std::string PlayerName() const override;

 private:
  int position_ = 0;
  std::string name_;
  bool is_out_ = false;
};

#endif
