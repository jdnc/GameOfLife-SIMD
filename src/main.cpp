#include <iostream>

#include "GameOfLife.h"

constexpr uint64_t kHeight = 100;
constexpr uint64_t kWidth = 100;
constexpr uint64_t kMaxIters = 100;

// TODO make params CLI flags
int main(int argc, char* argv[]) {
  std::cout << "Initializing grid...";
  auto game = GameOfLife(kHeight, kWidth, kMaxIters, false);
  game.randomInit();
  game.run();
}
