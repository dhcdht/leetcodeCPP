// https://leetcode.com/problems/longest-increasing-subsequence/description/
// 300. Longest Increasing Subsequence
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */
#import <iostream>
#import <vector>
#import "helper.hpp"

class Solution105 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        vector<int> counts(n, 1);
        vector<int> preIndexs(n, -1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (counts[j] + 1 > counts[i]) {
                        preIndexs[i] = j;
                        counts[i] = counts[j] + 1;
                    }
                }
            }
        }

        int maxCount = 0;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] > maxCount) {
                maxCount = counts[i];
            }
        }

        return maxCount;
    }

    void test() {
        vector<pair<vector<int>, int>> tests = {
                {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
                {{1,3,6,7,9,4,10,5,6}, 6},
        };
        runUnitTest("105 : 300. Longest Increasing Subsequence", tests, [&](auto input) {
            return this->lengthOfLIS(input);
        });
    }
};
