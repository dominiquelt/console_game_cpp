#include "dec.h"
#include <string>
#include <vector>
#include <random>
#include <iostream>

// DICE
std::mt19937 Dice::gen(std::random_device{}());

int Dice::Roll(int max) {
    std::uniform_int_distribution<int> dist(0, max);
    return dist(gen);
}