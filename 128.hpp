// https://leetcode.com/problems/maximum-gap/description/
// 164. Maximum Gap
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
 */
#import <iostream>
#import "helper.hpp"
#import <vector>

class Solution128 {
public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        int min = nums[0];
        int max = nums[0];
        for (auto num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
        }

        int gapLength = max - min;
        int bucketGap = (int) ceil((double) gapLength / (double) n);
        if (bucketGap == 0) {
            return 0;
        }
        int bucketCount = (int) ceil((double) gapLength / (double) bucketGap) + 1;
        vector<int> mins(bucketCount, INT_MAX);
        vector<int> maxs(bucketCount, INT_MIN);
        for (auto num : nums) {
            int convNum = num - min;
            int index = convNum / bucketGap;

            if (convNum < mins[index]) {
                mins[index] = convNum;
            }
            if (convNum > maxs[index]) {
                maxs[index] = convNum;
            }
        }

        int result = 0;
        int lastMax = maxs[0];
        for (int i = 1; i < bucketCount; ++i) {
            if (mins[i] == INT_MAX) {
                continue;
            }

            int gap = mins[i] - lastMax;
            if (gap > result) {
                result = gap;
            }

            lastMax = maxs[i];
        }

        return result;
    }

    void test() {
        typedef vector<int> Input;
        vector<pair<Input, int>> tests = {
                {{3, 6, 9, 1}, 3},
                {{10},         0},
                {{},           0},
                {{1, 3, 100},  97}
        };
        runUnitTest("128 : 164. Maximum Gap", tests, [&](Input input) {
            return this->maximumGap(input);
        });

    }
};
