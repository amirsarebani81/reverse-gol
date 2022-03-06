# Reverse Game of Life

- [Reverse Game of Life](#reverse-game-of-life)
  - [About](#about)
  - [Build](#build)
  - [Test](#test)

## About

This program takes the number of steps and the final table of the game as input from the user and displays the initial table if possible as output.
Run the program and give input like this:

Input

```text
4 5 10
....*
..*.*
.*..*
..*.*

```

Output

```text
..*.*
...**
**.**
*....
```

## Build

Enter the following commands to build and run the program (**CMake version >= 3.16 required**)

```bash
cmake -S . -B build
cmake --build build
build/gol
```

## Test

Enter the following commands to test using the Google Test Framework

```bash
cd test
cmake -S . -B build
cmake --build build
cd build && ctest
```
