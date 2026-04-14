#ifndef DEC_H
#define DEC_H

#include <iostream>
#include <random>
#include <string>
#include <vector>

class Player;
class Board;

class Field {
 public:
  void OnLand(Player* p);
  // virtual ~Field() {}  //  destruktor w klasach bazowych
 private:
  int number;
};

// class TrapField : public Field {
//  public:
//   void OnLand(Player* p) override;
// }; //obiekt trap field o typie field albo wektor pol z oznaczonym w indeksie
// trap/goal

// class GoalField : public Field {
//  public:
//   void OnLand(Player* p) override;
// };

class Player {
 public:
  void Move(int steps);

 private:
  int position = 0;
  std::string name;
  Board* board;
};

class Game {
 public:
  void Run();

 private:
  void NextTurn();
  void CheckEndTheGame();  // moze tu bool?
  void ShowStatus();
};

class losowanie {
 private:
  std::random_device rd;
  std::mt19937 gen;

 public:
  losowanie();
  std::mt19937* getGenerator();
};

class randomPole {
 private:
  losowanie* los;  // kompoilator domysla sie ze tu chce stworzyc obiekt jesli
                   // istnieje konstruktor domyslny ()
  std::uniform_int_distribution<> dist;

 public:
  randomPole(
      losowanie* model,
      int liczbaPol);  // oporocz losowania musze przekazac jeszcze liczbe pol
  int getPole();
};

class Dice {
 private:
  losowanie* los;  // kompoilator domysla sie ze tu chce stworzyc obiekt jesli
                   // istnieje konstruktor domyslny ()
  std::uniform_int_distribution<> dist;

 public:
  Dice(losowanie* model);
  int Roll();
};

class Board {
 public:
  Board(int liczbaPol, losowanie* systemLosu);  // Konstruktor
  ~Board();
  Field* getField(int index);

 private:
  std::vector<Field*> fields;
};

#endif
