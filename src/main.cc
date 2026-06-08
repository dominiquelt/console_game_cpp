
#include "board.h"
#include "game.h"
#include "player.h"
#include "randomPole.h"

int GenerateNumberOfFields();

int main() {
  int pola = GenerateNumberOfFields();
  Losowanie& los = Losowanie::GetInstance();
  std::unique_ptr<IDice> dice = std::make_unique<Dice>(&los);
  std::unique_ptr<IBoard> board = std::make_unique<Board>(pola);
  std::unique_ptr<Player> player1 = std::make_unique<Human>("Computer");
  std::unique_ptr<Player> player2 = std::make_unique<Human>("Human");
  std::unique_ptr<IRandomPole> pole = std::make_unique<RandomPole>(&los, pola);
  Game newGame(dice.get(), board.get(), player1.get(), player2.get());
  newGame.Run(pole.get());
  return 0;
}

int GenerateNumberOfFields() {
  int pola = 0;
  while (pola < 5) {
    std::cout << "Enter number of fields: " << std::endl;
    std::cin >> pola;
  }
  return pola;
}
