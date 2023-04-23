#ifndef Algo_T_h
#define Algo_T_h

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

std::vector<std::vector<std::string>> fieldGenerator(int row, int col, int chance) {
    std::vector<std::vector<std::string>> field(row, std::vector<std::string> (col, "."));
    int num;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            num = rand() % 100;
            if(num  < chance) {
                field[i][j] = "X";
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return field;
}

bool mazeRunner(std::vector<char> lst, char field[8][9]) {
    // start at field[0][0]
    int row = 0;
    int col = 0;
    for (int i = 0; i < 15; i++) {
        if (lst[i] == '1') {
            if (row + 1 == 8 || field[row + 1][col] == 'X') {
                // fail condition
                return false;
            } else {
                // move right
                row += 1;
            }
        } else {
            if (col + 1 == 9 || field[row][col + 1] == 'X') {
                // fail condition
                return false;
            } else {
                // move down
                col += 1;
            }
        }
        if (row == 7 && col == 8) {
            // reach the goal
            return true;
        }
    }
    return false;
}

int algo_one(char field[8][9] ) {
    int row = 8;
    int col = 9;
    int len = row + col - 2;
    int counter = 0;
    // 0 = down
    // 1 = right
    // total moves: row + col - 2 = 8 + 9 - 2 = 15 moves
    for (int bits = 0; bits <= pow(2, len); bits++) {
        std::vector<char> candidate;
        for (int k = 0; k <= len - 1; k ++) {
            int bit = (bits >> k) & 1;
            if (bit == 1) {
                candidate.push_back('1');
            } else {
                candidate.push_back('0');
            }
        }
        if (mazeRunner(candidate, field)) {
            counter++;
        }
    }
    return counter;
}


int soccer_dyn_prog(char field[8][9]) {
    //corner case: initial cell is impassible

    int row = 8;
    int col = 9;


    if(field[0][0] == 'X') 
    {
        return 0;
    }
    int A[8][9] =
    {
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,} };
    //base case
    A[0][0] = 1;
    //general cases
    for(int i = 0; i<row ; i++) 
    {
        for (int j = 0; j < col; j++)

        {
            int above = 0, left = 0;
            if (field[i][j] == 'X')
            {
                A[i][j] = 1;
                continue;
            }
            int from_above = 0, from_left = 0;
            if (i > 0 && field[i - 1][j] == '.')
            {
                above = A[i - 1][j];
            }
            if (j > 0 && field[i][j - 1] == '.')
            {
                left = A[i][j - 1];
            }
            A[i][j] += above + left;
        }
    }

    return A[row - 1][col - 1];
}

/*================================================================*/
bool mazeRunner(std::vector<char> lst, std::vector<std::vector<std::string>> field) {
    // start at field[0][0]
    int row = 0;
    int col = 0;
    for (int i = 0; i < field.size() + field[0].size() - 2; i++) {
        if (lst[i] == '1') {
            if (row + 1 == field.size() || field[row + 1][col] == "X") {
                // fail condition
                return false;
            } else {
                // move right
                row += 1;
            }
        } else {
            if (col + 1 == field[0].size() || field[row][col + 1] == "X") {
                // fail condition
                return false;
            } else {
                // move down
                col += 1;
            }
        }
        if (row == field.size() - 1 && col == field[0].size() - 1) {
            // reach the goal
            return true;
        }
    }
    return false;
}

int algo_one(std::vector<std::vector<std::string>> field) {
    int row = field.size();
    int col = field[0].size();
    int len = row + col - 2;
    int counter = 0;
    // 0 = down
    // 1 = right
    // total moves: row + col - 2 = 8 + 9 - 2 = 15 moves
    for (int bits = 0; bits <= pow(2, len); bits++) {
        std::vector<char> candidate;
        for (int k = 0; k <= len - 1; k ++) {
            int bit = (bits >> k) & 1;
            if (bit == 1) {
                candidate.push_back('1');
            } else {
                candidate.push_back('0');
            }
        }
        if (mazeRunner(candidate, field)) {
            counter++;
        }
    }
    return counter;
}


int soccer_dyn_prog(std::vector<std::vector<std::string>> field) {
    //corner case: initial cell is impassible

    int row = field.size();
    int col = field[0].size();


    if(field[0][0] == "X") 
    {
        return 0;
    }
    std::vector<std::vector<int>> A(row, std::vector<int> (col, 0));
    /*
    int A[8][9] =
    {
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,},
    {0, 0, 0, 0, 0, 0, 0, 0, 0,} };
    */
    //base case
    A[0][0] = 1;
    //general cases
    for(int i = 0; i < row ; i++) 
    {
        for (int j = 0; j < col; j++)

        {
            int above = 0, left = 0;
            if (field[i][j] == "X")
            {
                A[i][j] = 1;
                continue;
            }
            int from_above = 0, from_left = 0;
            if (i > 0 && field[i - 1][j] == ".")
            {
                above = A[i - 1][j];
            }
            if (j > 0 && field[i][j - 1] == ".")
            {
                left = A[i][j - 1];
            }
            A[i][j] += above + left;
        }
    }

    return A[row - 1][col - 1];
}

// clang++ main.cpp -o main
#endif