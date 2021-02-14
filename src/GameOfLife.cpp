#include "GameOfLife.h"

GameOfLife::GameOfLife(uint64_t height, uint64_t width, uint64_t maxIters, bool useSIMD):
    height_(height),
    width_(width),
    maxIters_(maxIters),
    useSIMD_(useSIMD) {}

void GameOfLife::run() {
  if (useSIMD_) {
    runSIMD();
  } else {
    runScalar();
  }
}

void GameOfLife::randomInit() {
  // impl
}

void GameOfLife::runScalar() {
  // impl
}

void GameOfLife::runSIMD() {
  // impl
}


