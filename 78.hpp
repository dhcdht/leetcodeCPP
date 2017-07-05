// https://leetcode.com/problems/pascals-triangle/#/description
// 118. Pascal's Triangle
/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

 */
#import <iostream>

class Solution78 {
public:
    vector<vector<int>> generate(int numRows) {
        auto result = vector<vector<int>>();
        if (numRows == 0) {
            return result;
        }
        result.push_back(vector<int>(1, 1));

        for (int i = 1; i < numRows; ++i) {
            auto row = vector<int>();
            row.push_back(1);
            for (int j = 1; j < i; ++j) {
                row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            row.push_back(1);

            result.push_back(row);
        }

        return result;
    }

    void test() {

    }
};
