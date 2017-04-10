// https://leetcode.com/problems/diagonal-traverse/#/description
// 498. Diagonal Traverse
/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.

 */
#import <iostream>

using namespace std;

class Solution50 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }

        int x = 0;
        int y = 0;
        int xStep = -1;
        int yStep = 1;

        auto result = vector<int>();
        int m = matrix.size();
        int n = matrix[0].size();
        while ((x != m - 2 || y != n) && (x != m || y != n - 2)) {
            if (x < 0) {
                xStep = 1;
                yStep = -1;

                if (y < n) {
                    y += 1;
                } else {
                    x += 1;
                }
            } else if (y < 0) {
                xStep = -1;
                yStep = 1;

                if (x < m) {
                    x += 1;
                } else {
                    y += 1;
                }
            } else if (x >= m) {
                xStep = -1;
                yStep = 1;

                y += 1;
            } else if (y >= n) {
                xStep = 1;
                yStep = -1;

                x += 1;
            } else {
                result.push_back(matrix[x][y]);
            }

            x += xStep;
            y += yStep;
        }

        return result;
    }

    void test() {
//        auto input = vector<vector<int>>({{1, 2, 3, 10},
//                                          {4, 5, 6, 11},
//                                          {7, 8, 9, 12},
//                                          {1, 2, 3, 16}});
//        auto input = vector<vector<int>>({{2, 3}});
        auto input = vector<vector<int>>({{2}, {3}});
        auto result = this->findDiagonalOrder(input);
        cout << "498. Diagonal Traverse : ";
        for (auto num : result) {
            cout << num << ",";
        }
        cout << endl;
    }
};
