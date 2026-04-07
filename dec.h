#ifndef DEC_H
#define DEC_H

#include <string>
#include <vector>
#include <random>
#include <iostream>

class Player;
class Board;


class Field {
public:
    void OnLand(Player);

};

class Board {
public:
    int DrawFieldPosition();

private:
    std::vector<Field* > fields;

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
    void CheckEndTheGame(); // moze tu bool?
    void ShowStatus();

    

};

class Dice {
    private:
        static std::mt19937 gen; // static, eby wszystkie kostki używały tego samego ziarna
    public:
        static int Roll(int max);
};

#endif

//1. tutaj static gena a gdzie pozostale dane dotyczace losowania, ktore ustawialam na pcozatku poprzedniej gry
//2. co to jest to virtual 
//3. gdzie dawac konstruktor czemu kaza mi dawac konstruktor w pliku h
