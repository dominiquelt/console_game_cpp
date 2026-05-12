
#include "game.h"

int GenerateNumberOfFields();

int main() {
  int pola = GenerateNumberOfFields();
  Game newGame(pola);
  newGame.Run();
  return 0;
}

int GenerateNumberOfFields() {
  int pola = 0;
  while (pola < 5) {
    std::cout << "Wyznacz ilość pol: " << std::endl;
    std::cin >> pola;
  }
  return pola;
}
