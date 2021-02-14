# GameOfLife-SIMD
Implement the famous cellular automaton [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life). Attempt to learn more about SIMD, by using the AVX2.0 intel intrinsics on my latptop.

# Build and Run

## Check SIMD support on your HW
```
grep avx2 /proc/cpuinfo
```

## Build
```
make
```

## Run
```
./game
```
