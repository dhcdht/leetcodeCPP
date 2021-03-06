// https://leetcode.com/problems/swim-in-rising-water/description/
// 778. Swim in Rising Water
/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].
 */
#import <iostream>
#import "helper.hpp"
#import <vector>
#import <queue>

class Solution131 {
public:
    typedef pair<int, int> Coordinate;
    typedef pair<int, Coordinate> Cell;

    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();
        int ans = max(grid[0][0], grid[n - 1][n - 1]);
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<Coordinate> dir({{-1, 0},
                                {0,  1},
                                {1,  0},
                                {0,  -1}});
        pq.push({ans, {0, 0}});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur.first);
            queue<pair<int, int>> myq;
            myq.push({cur.second.first, cur.second.second});
            while (!myq.empty()) {
                auto p = myq.front();
                myq.pop();
                if (p.first == n - 1 && p.second == n - 1) {
                    return ans;
                }
                for (int i = 0; i < dir.size(); ++i) {
                    Coordinate item = dir[i];
                    Coordinate coord = {p.first + item.first, p.second + item.second};
                    if (coord.first >= 0 && coord.first < n && coord.second >= 0 && coord.second < n
                        && visited[coord.first][coord.second] == 0) {
                        visited[coord.first][coord.second] = 1;
                        if (grid[coord.first][coord.second] <= ans) {
                            myq.push({coord.first, coord.second});
                        } else {
                            pq.push({grid[coord.first][coord.second], coord});
                        }
                    }
                }
            }
        }

        return -1;
    }

    void test() {
        typedef vector<vector<int>> Input;
        vector<pair<Input, int>> tests = {
                {{{0, 2},          {1,  3}},                                                                           3},
                {{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}}, 16}
        };
        runUnitTest("131 : 778. Swim in Rising Water", tests, [&](Input input) {
            return this->swimInWater(input);
        });
    }
};
