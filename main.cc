#include <iostream>
#include <random>

#include "board.h"
#include "dice.h"
#include "losowanie.h"
#include "player.h"
#include "randomPole.h"

Losowanie los;  // globalna zmienna poza mainem

int main() {
  int pola = 0;
  while (pola < 5) {
    std::cout << "Wyznacz ilość pol: " << std::endl;  // do klasy game
    std::cin >> pola;
  }

  Board plansza(pola);

  RandomPole pole(&los, pola);  // co zamienic
  int cel = pole.getPole();
  int jama = pole.getPole();

  while (jama == cel) {
    jama = pole.getPole();
  }

  plansza.DrawFieldPossion(jama, cel);

  std::cout << "Wspaniale gramy na " << plansza.GetSize() << " polach!"
            << " JAMA: " << jama << " CEL: " << cel << std::endl;

  Player komputer("Komputer");
  Player user("Gracz");
  int rzut = 0;

  Dice dice(&los);

  while (komputer.GetState() == false && user.GetState() == false) {
    std::cout << "Rzucam kostka" << std::endl;
    rzut = dice.Roll();

    komputer.Move(rzut, plansza.GetSize());

    std::cout << "teraz stoje na polu: " << komputer.GetPosition()
              << " twoj rzut!" << std::endl;

    rzut = dice.Roll();
    user.Move(rzut, plansza.GetSize());

    std::cout << "teraz stoisz na polu: " << komputer.GetPosition()
              << std::endl;
    std::cout << " teraz ja" << std::endl;
  }
  return 0;
}
