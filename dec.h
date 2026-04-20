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

 private:
  int number;
};

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

class losowanie {  // obiekty definiujemy z duzej litery, metody tez np
                   // getGenerator, kolejnosc sekcji public>>protecte>>private
 private:
  std::random_device
      rd;  // poprawic prywatne zmienne na np rd_ wazna jest ta podloga!
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
