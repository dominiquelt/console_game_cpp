#include <iostream>
#include <random>


int main() {
  std::random_device rd;                     
  std::mt19937 gen(rd());
  int pola = 0;
  while (pola < 5) {
    std::cout<< "Wyznacz ilość pol: "<<std::endl;
    std::cin >> pola;
  }
  std::uniform_int_distribution<> dist(0,pola-1);
  int cel = dist(gen);
  int jama = dist(gen); // jama nie moze = cel
  while (jama == cel)
  {
    jama = dist(gen);
  }
  
  std::cout<< "Wspaniale gramy na "<< pola << " polach!" << " JAMA: " << jama << " CEL: "<< cel << std::endl;

  int pole_komputer =0;
  int pole_user =0;
  bool is_out = false;
  int rzut = 0;

  while ( is_out != true ){
    std::cout << "Rzucam kostka"<< std::endl;
    rzut =dist(gen);
    pole_komputer = pole_komputer +rzut;
    if (pole_komputer >= pola){
      pole_komputer = pole_komputer - pola;
    }
    std::cout << "teraz stoje na polu: " << pole_komputer << std::endl;
    if (pole_komputer == jama || pole_komputer == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    }
    else {
      std::cout << "twoj rzut, 1" << std::endl;
    }
    rzut = dist(gen);
    pole_user = pole_user +rzut;
    if (pole_user >= pola){
      pole_user = pole_user - pola;
    }
    std::cout << "teraz stoisz na polu: " << pole_user << std::endl;
    if (pole_user == jama || pole_user == cel) {
      std::cout << "koniec gry" << std::endl;
      is_out = true;
    }
    else {
      std::cout << "teraz ja" << std::endl;
    }

  }

  // while wysolowany != jama lub cel
     // uzytkownik rzut kostka random
     /* 0+cyfra z rzutu
      cout numer pola (jesli numer pola >= ilosci pol to wynik - ilosc pol = pole na ktorym uzytkownik stanie)
      komputer to samo
      znowu uztykownik 
     */

  return 0;
}
