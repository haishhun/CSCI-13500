#include "Dice.h"

#include <cstdlib>
#include <ctime>

int RollDice() {
  // srand() in main() of the game.
  return rand() % 6 + 1;
}