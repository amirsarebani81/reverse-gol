#! /bin/bash
echo "compile main.cpp"
g++ main.cpp gol.hpp gol.cpp -o main.exe && echo "run main.exe"
echo "--------------------------------"
./main.exe
echo "--------------------------------"
echo "remove main.exe"
rm main.exe