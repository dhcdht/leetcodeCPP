// https://leetcode.com/problems/battleships-in-a-board/#/description
// 419. Battleships in a Board
/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution4 {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;

        for (int i = 0; i < board.size(); ++i) {
            auto row = board.at(i);
            for (int j = 0; j < row.size(); ++j) {
                auto item = row.at(j);

                if (item == 'X') {
                    if (j == (row.size() - 1) || row.at(j + 1) != 'X') {
                        if (i == (board.size() - 1) || board.at(i + 1).at(j) != 'X') {
                            count += 1;
                        }
                    }
                }
            }

        }

        return count;
    }

    void test() {
        auto row0 = vector<char>({'X', '.', '.', 'X'});
        auto row1 = vector<char>({'.', '.', '.', 'X'});
        auto row2 = vector<char>({'.', '.', '.', 'X'});
        vector<vector<char>> board = vector<vector<char>>({row0, row1, row2});
//        auto row0 = vector<char>({'X'});
//        vector<vector<char>> board = vector<vector<char>>({row0});
//        auto row0 = vector<char>({'X', 'X', 'X'});
//        vector<vector<char>> board = vector<vector<char>>({row0});
        auto result = this->countBattleships(board);
        cout << "419. Battleships in a Board : " << result << endl;
    }
};
