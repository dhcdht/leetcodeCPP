// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/#/description
// 453. Minimum Moves to Equal Array Elements
/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution44 {
public:
    int minMoves(vector<int>& nums) {
        auto n = nums.size();

        int sum = 0;
        int minNum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int curNum = nums[i];
            if (curNum < minNum) {
                minNum = curNum;
            }

            sum += curNum;
        }

        int minSum = minNum * n;
        int result = sum - minSum;

        return result;
    }

    void test() {
        auto input = vector<int>({1,2,3});
        auto result = this->minMoves(input);
        cout << "453. Minimum Moves to Equal Array Elements : " << result << endl;
    }
};
