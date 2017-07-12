// https://leetcode.com/problems/search-a-2d-matrix/#/description
// 74. Search a 2D Matrix
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */
#import <iostream>

class Solution83 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row += 1;
            } else if (matrix[row][col] > target) {
                col -= 1;
            }
        }

        return false;
    }

    void test() {

    }
};
