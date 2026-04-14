#include <iostream>
#include <random>

#include "dec.h"

losowanie los;  // globalna zmienna poza mainem

int main() {
  int pola = 0;
  while (pola < 5) {
    std::cout << "Wyznacz ilość pol: " << std::endl;
    std::cin >> pola;
  }
  randomPole pole(&los, pola);
  int cel = pole.getPole();
  int jama = pole.getPole();  // jama nie moze = cel //linie 15-19 w board W
                              // MAINIE UZYC OBIEKTU BOARD
  while (jama == cel) {
    jama = pole.getPole();
  }

  std::cout << "Wspaniale gramy na " << pola << " polach!" << " JAMA: " << jama
            << " CEL: " << cel << std::endl;

  int pole_komputer = 0;
  int pole_user = 0;
  bool is_out = false;
  int rzut = 0;

  Dice dice(&los);

  while (is_out != true) {
    std::cout << "Rzucam kostka" << std::endl;
    rzut = dice.Roll();
    pole_komputer = pole_komputer + rzut;
    if (pole_komputer >= pola) {
      pole_komputer = pole_komputer - pola;
    }
    std::cout << "teraz stoje na polu: " << pole_komputer << std::endl;
    if (pole_komputer == jama || pole_komputer == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    } else {
      std::cout << "twoj rzut, 1" << std::endl;
    }
    rzut = dice.Roll();
    pole_user = pole_user + rzut;
    if (pole_user >= pola) {
      pole_user = pole_user - pola;
    }
    std::cout << "teraz stoisz na polu: " << pole_user << std::endl;
    if (pole_user == jama || pole_user == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    } else {
      std::cout << "teraz ja" << std::endl;
    }
  }

  return 0;
}
