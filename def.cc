#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "dec.h"

// DICE
Dice::Dice(losowanie* model) : los(model), dist(1, 6) {}
int Dice::Roll() {
  auto* gen = los->getGenerator();
  return dist(*gen);
}

losowanie::losowanie() : gen(rd()) {}

std::mt19937* losowanie::getGenerator() {
  return &gen;
}

randomPole::randomPole(losowanie* model, int liczbaPol)
    : los(model), dist(0, liczbaPol - 1) {}

int randomPole::getPole() {
  return dist(*los->getGenerator());
}

// --- ---FIELD
void Field::OnLand(Player* p) {
  std::cout << "Stoisz na bezpiecznym polu." << std::endl;
}

// void TrapField::OnLand(Player* p) {
//   std::cout << "O NIE! To JAMA! Wpadasz w pułapkę." << std::endl;
// }

// void GoalField::OnLand(Player* p) {
//   std::cout << "GRATULACJE! To jest CEL! Wygrałeś!" << std::endl;
// }

// --- BOARD
Board::Board(int liczbaPol, losowanie* systemLosu) {
  randomPole rp(systemLosu, liczbaPol);

  int jamaIdx = rp.getPole();
  int celIdx = rp.getPole();

  while (jamaIdx == celIdx) {
    celIdx = rp.getPole();
  }

  for (int i = 0; i < liczbaPol; i++) {
    fields.push_back(new Field());
  }
  std::cout << "Plansza stworzona! Jama na: " << jamaIdx
            << ", Cel na: " << celIdx << std::endl;
}

Board::~Board() {
  for (Field* f : fields) {
    delete f;
  }
  fields.clear();
}

Field* Board::getField(int index) {
  if (index >= 0 && index < fields.size()) {
    return fields[index];
  }
  return nullptr;
}
