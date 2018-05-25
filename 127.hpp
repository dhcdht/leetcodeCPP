// https://leetcode.com/problems/01-matrix/description/
// 542. 01 Matrix
/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
 */
#import <iostream>
#import "helper.hpp"
#import <vector>
#import <list>

class Solution127 {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        typedef pair<int, int> Cor;
        int rows = matrix.size();
        if (0 == rows) {
            return {};
        }
        int cols = matrix[0].size();

        list<Cor> checkQueue;
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    result[i][j] = 0;
                    checkQueue.push_back({i, j});
                }
            }
        }

        vector<Cor> offsets = {{-1, 0},
                               {1,  0},
                               {0,  -1},
                               {0,  1}};
        while (!checkQueue.empty()) {
            Cor head = checkQueue.front();
            checkQueue.pop_front();

            for (int i = 0; i < offsets.size(); ++i) {
                Cor cord = {head.first + offsets[i].first, head.second + offsets[i].second};
                if (0 <= cord.first && cord.first < rows
                    && 0 <= cord.second && cord.second < cols) {
                    if (result[head.first][head.second] + 1 < result[cord.first][cord.second]) {
                        result[cord.first][cord.second] = result[head.first][head.second] + 1;
                        checkQueue.push_back(cord);
                    }
                }
            }
        }

        return result;
    }

    void test() {
        typedef vector<vector<int>> Input;
        typedef Input Output;
        vector<pair<Input, Output>> tests = {
                {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}},
                {{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}}},
        };
        runUnitTest("127 : 542. 01 Matrix", tests, [&](Input input) {
            return this->updateMatrix(input);
        });
    }
};
