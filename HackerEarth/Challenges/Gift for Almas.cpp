
/**
 * @file Gift for Almas.cpp
 * @author mhmdreda99 (dev.mhmdreda99@gmail.com)
 * @brief Problem Statement
On his birthday, Almas was given a (n x n <n < 500)  matrix of natural numbers up to  and instructions for it. The instruction consisted of symbols 
 and , where if the symbol  L  is given you need to rotate the matrix  degrees to the left, and for the symbol 
 you need to rotate the matrix degrees to the right. The instruction was only 
 characters in length so Almas could handle the twists with ease. Your task is to display the matrix that Almas had at the end of these turns.

Input
The first line consists of one integer n - the size of the matrix.
In the next n lines, you are given n integers. Numbers can range from  1 to 500
Output
Output the final matrix n x n 
.
Note
Important note - you should not print any whitespace or newline if it is not necessary.

Sample Input
2
1 2
3 4
RLR
Sample Output
3 1
4 2
 * @version 0.1
 * @date 2024-01-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> rotate_matrix(std::vector<std::vector<int>>& matrix, char direction) {
    int n = matrix.size();
    std::vector<std::vector<int>> rotated(n, std::vector<int>(n));
    if (direction == 'R') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
    } else if (direction == 'L') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[n - j - 1][i] = matrix[i][j];
            }
        }
    }
    return rotated;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::string instructions;
    std::cin >> instructions;

    for (char instruction : instructions) {
        matrix = rotate_matrix(matrix, instruction);
    }

    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}