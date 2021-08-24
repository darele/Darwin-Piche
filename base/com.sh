FILE=./a.out
if [[ -f "$FILE" ]]; then
    rm ./a.out
fi
g++ -std=c++11 -g -O2 -Wconversion -Wshadow -Wall -Wextra $1.cpp -o a.out
if [[ -f "$FILE" ]]; then
    ./a.out < data.in > data.out
    code data.out
fi
