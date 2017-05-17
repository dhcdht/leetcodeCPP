// https://leetcode.com/problems/number-of-islands/#/description
// 200. Number of Islands
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
 */
#import <iostream>
#import <vector>

class Solution60 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    result += 1;
                    this->markIsland(grid, i, j);
                }
            }
        }

        return result;
    }

    void markIsland(vector<vector<char>> &grid, int x, int y) {
        if (grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '2';

        if (x > 0) {
            this->markIsland(grid, x - 1, y);
        }
        if (y > 0) {
            this->markIsland(grid, x, y - 1);
        }
        if (x < grid.size() - 1) {
            this->markIsland(grid, x + 1, y);
        }
        if (y < grid[x].size() - 1) {
            this->markIsland(grid, x, y + 1);
        }
    }

    void test() {

    }
};
