// https://leetcode.com/problems/island-perimeter/#/description
// 463. Island Perimeter
/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
https://leetcode.com/static/images/problemset/island.png
 */
#import <iostream>

using namespace std;

class Solution9 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); ++i) {
            auto row = grid[i];
            for (int j = 0; j < row.size(); ++j) {
                auto item = row[j];

                if (item == 1) {
                    if (i == 0 || grid[i-1][j] == 0) {
                        result += 1;
                    }
                    if (j == 0 || grid[i][j-1] == 0) {
                        result += 1;
                    }
                    if (i == grid.size() - 1 || grid[i + 1][j] == 0) {
                        result += 1;
                    }
                    if (j == row.size() - 1 || grid[i][j + 1] == 0) {
                        result += 1;
                    }
                }
            }
        }

        return result;
    }

    void test() {

    }
};
