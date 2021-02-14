#include <iostream>

#include "GameOfLife.h"

constexpr uint64_t kHeight = 100;
constexpr uint64_t kWidth = 100;
constexpr uint64_t kMaxIters = 100;

// TODO make params CLI flags
int main(int argc, char* argv[]) {
  std::cout << "Initializing grid" << std::endl;
  auto game = GameOfLife(kHeight, kWidth, kMaxIters, false);
  game.printGrid();
  game.randomInit();
  std::cout << "Initial config: " << std::endl;
  game.printGrid();

  game.run();
}
