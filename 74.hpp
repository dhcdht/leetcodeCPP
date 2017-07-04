// https://leetcode.com/problems/maximum-product-of-three-numbers/#/description
// 628. Maximum Product of Three Numbers
/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 */
#import <iostream>

class Solution74 {
public:
    int maximumProduct(vector<int> &nums) {
        auto maxs = vector<int>(3, INT32_MIN);
        auto mins = vector<int>(2, INT32_MAX);

        for (auto item : nums) {
            if (item > maxs[0]) {
                maxs[2] = maxs[1];
                maxs[1] = maxs[0];
                maxs[0] = item;
            } else if (item > maxs[1]) {
                maxs[2] = maxs[1];
                maxs[1] = item;
            } else if (item > maxs[2]) {
                maxs[2] = item;
            }
            if (item < mins[0]) {
                mins[1] = mins[0];
                mins[0] = item;
            } else if (item < mins[1]) {
                mins[1] = item;
            }
        }

        auto power1 = maxs[0] * maxs[1] * maxs[2];
        auto power2 = maxs[0] * mins[0] * mins[1];

        auto result = max(power1, power2);

        return result;
    }

    void test() {

    }
};
