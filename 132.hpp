// https://leetcode.com/problems/toeplitz-matrix/description/
// 766. Toeplitz Matrix
/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.


Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
 */
#import <iostream>
#import "helper.hpp"
#import <vector>

class Solution132 {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n <= 1) {
            return true;
        }
        int m = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            int x = 0;
            int y = i;
            int num = matrix[x][y];
            x += 1;
            y += 1;
            while (x < n && y < m) {
                if (matrix[x][y] != num) {
                    return false;
                }
                x += 1;
                y += 1;
            }
        }

        for (int i = 1; i < n; ++i) {
            int x = i;
            int y = 0;
            int num = matrix[x][y];
            x += 1;
            y += 1;
            while (x < n && y < m) {
                if (matrix[x][y] != num) {
                    return false;
                }
                x += 1;
                y += 1;
            }
        }

        return true;
    }

    void test() {
        typedef vector<vector<int>> Input;
        vector<pair<Input, bool>> tests = {
                {{{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}}, true},
                {{{1, 2},       {2, 2}},                     false},
                {{{18},         {66}},                       true}
        };
        runUnitTest("132 : 766. Toeplitz Matrix", tests, [&](Input input) {
            return this->isToeplitzMatrix(input);
        });
    }
};
