#! /bin/bash
echo "compile main.cpp"
g++ main.cpp gol.hpp gol.cpp -o main.exe && echo "run main.exe"
echo "--------------------------------"
if [[ $# -eq 0 ]]; then
    ./main.exe
else
    ./main.exe < tests/in$1.txt
fi
echo "--------------------------------"
echo "remove main.exe"
rm main.exe