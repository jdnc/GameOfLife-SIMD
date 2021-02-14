#pragma once
#include <cstdint>
#include <vector>

class GameOfLife {

  public:
    GameOfLife(uint64_t gridHeight, uint64_t gridWidth, uint64_t maxIters, bool useSIMD);
    void randomInit();
    void run();

  private:
    uint64_t height_;
    uint64_t width_;
    uint64_t maxIters_;
    std::vector<std::vector<bool>> grid_;

    bool useSIMD_;

    void runScalar();
    void runSIMD();
};


