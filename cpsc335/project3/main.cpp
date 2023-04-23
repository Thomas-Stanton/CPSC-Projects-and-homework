#include "algo.h"
#include <chrono>

char field[8][9] = {{'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
                    {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
                    {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
                    {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
                    {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
                    {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
                    {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
                    // goal is field[7][8]

std::vector<std::vector<std::string>> fieldA = {{".", ".", ".", ".", ".", ".", "X", ".", "X"},
                                                {"X", ".", ".", ".", ".", ".", ".", ".", "."},
                                                {".", ".", ".", "X", ".", ".", ".", "X", "."},
                                                {".", ".", "X", ".", ".", ".", ".", "X", "."},
                                                {".", "X", ".", ".", ".", ".", "X", ".", "."},
                                                {".", ".", ".", ".", "X", ".", ".", ".", "."},
                                                {".", ".", "X", ".", ".", ".", ".", ".", "X"},
                                                {".", ".", ".", ".", ".", ".", ".", ".", "."}};                   

int main() {
    // for printing
    for(int i = 0; i < 8; i++ ) { // col
        for (int j = 0; j < 9; j++) { // row
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // vector of vectors
    int row, col, chance;
    int inp;
    std::vector<std::vector<std::string>> sField;
    std::cout << "Would you like to test the given example? Type 0 for no and 1 for yes: ";
    std::cin >> inp;
    if (inp == 0){
        std::cout << "How many rows: ";
        std::cin >> row;
        std::cout << "How many columns: ";
        std::cin >> col;
        std::cout << "Chance of a cell being an X (0 to 100): ";
        std::cin >> chance;
    }

    if (inp == 0) {
        sField = fieldGenerator(row, col, chance);
    }
    else {
        sField = fieldA;
    }

    // using vectors
    auto start0 = std::chrono::high_resolution_clock::now();
    int ansZero = algo_one(sField);
    auto end0 = std::chrono::high_resolution_clock::now();
    auto duration0 = std::chrono::duration_cast<std::chrono::nanoseconds>(end0 - start0).count();
    std::cout << "Testing algo one" << std::endl;
    std::cout << "Execution time: " << duration0 << " nanoseconds." << std::endl;
    std::cout << "Correct paths to goal from (0, 0): " << ansZero << std::endl;

    auto startA = std::chrono::high_resolution_clock::now();
    auto endA = std::chrono::high_resolution_clock::now();
    auto durationA = std::chrono::duration_cast<std::chrono::nanoseconds>(endA - startA).count();
    int ansZeroA = soccer_dyn_prog(sField);
    std::cout << "Testing algo two" << std::endl;
    std::cout << "Execution time: " << durationA << " nanoseconds." << std::endl;
    std::cout << "Correct paths to goal from (0, 0): " << ansZeroA << std::endl;
  

    // using arrays
    /*
    auto start = std::chrono::high_resolution_clock::now();
    int ansOne = algo_one(field);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " nanoseconds." << std::endl;
    std::cout << "Correct paths to goal from (0, 0): " << ansOne << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    int ansTwo = soccer_dyn_prog(field);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto  duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
    std::cout << "Execution time: " << duration2 << " nanoseconds." << std::endl;
    std::cout << "Correct paths to goal from (0, 0): " << ansTwo << std::endl;
    */

  
    return 0;
};
