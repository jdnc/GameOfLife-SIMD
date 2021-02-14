#include "GameOfLife.h"

#include <time.h>

#include <cstdlib>
#include <iostream>

GameOfLife::GameOfLife(uint64_t height, uint64_t width, uint64_t maxIters,
                       bool useSIMD)
    : height_(height), width_(width), maxIters_(maxIters), useSIMD_(useSIMD) {
  grid_ =
      std::vector<std::vector<bool>>(height_, std::vector<bool>(width_, false));
}

void GameOfLife::run() {
  if (useSIMD_) {
    runSIMD();
  } else {
    runScalar();
  }
}

void GameOfLife::randomInit() {
  srand(time(NULL));
  for (auto i = 0; i < height_; ++i)
    for (auto j = 0; j < width_; ++j) {
      // initialize 10% of the grid
      if (rand() % 100 <= 10) {
        grid_[i][j] = true;
      }
    }
}

void GameOfLife::runScalar() {
  // impl
}

void GameOfLife::runSIMD() {
  // impl
}

void GameOfLife::printGrid() {
  for (auto i = 0; i < height_; ++i) {
    for (auto j = 0; j < width_; ++j) {
      if (grid_[i][j]) {
        std::cout << '*';
      } else {
        std::cout << ".";
      }
    }

    std::cout << std::endl;
  }
}
