// https://leetcode.com/problems/minesweeper/#/description
// 529. Minesweeper
/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
Example 1:
Input:

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:
Input:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Note:
The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution23 {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        this->clickBoard(board, click);

        return board;
    }

    void clickBoard(vector<vector<char>> &board, vector<int> click) {
        int x = click[0];
        int y = click[1];

        char currentZone = board[x][y];
        if (currentZone == 'M' || currentZone == 'X') {
            board[x][y] = 'X';
            return;
        }
        if (currentZone == 'B' || ('1' <= currentZone && currentZone <= '8')) {
            return;
        }
        if (currentZone == 'E') {
            board[x][y] = 'B';

            auto nextClicks = vector<vector<int>>();
            bool shouldContinueClick = this->checkAdjacentZone(board, click, nextClicks);

            if (shouldContinueClick) {
                for (auto nextClick : nextClicks) {
                    this->clickBoard(board, nextClick);
                }
            }
        }
    }

    bool checkAdjacentZone(vector<vector<char>> &board, vector<int> &click, vector<vector<int>> &nextClicks) {
        int x = click[0];
        int y = click[1];

        int adjancentMineCount = 0;
        bool topValid = x - 1 >= 0;
        bool leftValid = y - 1 >= 0;
        bool rightValid = y + 1 < board[0].size();
        bool bottomValid = x + 1 < board.size();
        if (topValid) {
            if (this->zoneIsMine(board, x-1, y)) {
                adjancentMineCount += 1;
            } else {
                nextClicks.push_back({x - 1, y});
            }

            if (leftValid) {
                if (this->zoneIsMine(board, x - 1, y - 1)) {
                    adjancentMineCount += 1;
                } else {
                    nextClicks.push_back({x - 1, y - 1});
                }
            }
            if (rightValid) {
                if (this->zoneIsMine(board, x - 1, y + 1)) {
                    adjancentMineCount += 1;
                } else {
                    nextClicks.push_back({x - 1, y + 1});
                }
            }
        }
        if (bottomValid) {
            if (this->zoneIsMine(board, x + 1, y)) {
                adjancentMineCount += 1;
            } else {
                nextClicks.push_back({x + 1, y});
            }

            if (leftValid) {
                if (this->zoneIsMine(board, x + 1, y - 1)) {
                    adjancentMineCount += 1;
                } else {
                    nextClicks.push_back({x + 1, y - 1});
                }
            }
            if (rightValid) {
                if (this->zoneIsMine(board, x + 1, y + 1)) {
                    adjancentMineCount += 1;
                } else {
                    nextClicks.push_back({x + 1, y + 1});
                }
            }
        }
        if (leftValid) {
            if (this->zoneIsMine(board, x, y - 1)) {
                adjancentMineCount += 1;
            } else {
                nextClicks.push_back({x, y - 1});
            }
        }
        if (rightValid) {
            if (this->zoneIsMine(board, x, y + 1)) {
                adjancentMineCount += 1;
            } else {
                nextClicks.push_back({x, y + 1});
            }
        }

        if (adjancentMineCount > 0) {
            board[x][y] = (char)('0' + adjancentMineCount);

            return false;
        } else {
            return true;
        }
    }

    bool zoneIsMine(vector<vector<char>> &board, int x, int y) {
        char currentZone = board[x][y];
        if (currentZone == 'M' || currentZone == 'X') {
            return 1;
        } else {
            return 0;
        }
    }

    void test() {
        auto input = vector<vector<char>>({{'E','E','E','E','E'},
                                           {'E','E','M','E','E'},
                                           {'E','E','E','E','E'},
                                           {'E','E','E','E','E'}});
        auto click = vector<int>({3, 0});
        auto output = this->updateBoard(input, click);
    }
};
