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

int GameOfLife::state(int i, int j) {
  if (i >= width_ || i < 0 || j >= height_ || j < 0) return 0;
  if (!grid_[i][j]) return 0;
  return 1;
}

int GameOfLife::countNbrs(uint64_t i, uint64_t j) {
  return state(i, j - 1) + state(i, j + 1) + state(i - 1, j) + state(i + 1, j) +
         state(i - 1, j - 1) + state(i - 1, j + 1) + state(i + 1, j - 1) +
         state(i + 1, j + 1);
}

void GameOfLife::runScalar() {
  auto generation = 1;
  while (generation <= maxIters_) {
   auto nextGrid = std::vector<std::vector<bool>>(height_,
                                              std::vector<bool>(width_, false));
    for (auto i = 0; i < height_; ++i) {
      for (auto j = 0; j < width_; ++j) {
        auto count = countNbrs(i, j);
        if (grid_[i][j] && count > 1 && count < 4) {
          nextGrid[i][j] = true;
        } else if (!grid_[i][j] && count == 3) {
          nextGrid[i][j] = true;
        }
      }
    }
    grid_ = nextGrid;
    std::cout << "Generation " << generation++ << std::endl;
    printGrid();
  }
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
