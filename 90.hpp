// https://leetcode.com/problems/maximum-subarray/#/description
// 53. Maximum Subarray
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
#import <iostream>

class Solution90 {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        auto maxSum = nums[0];
        auto maxEndHere = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxEndHere = max(nums[i], maxEndHere + nums[i]);
            maxSum = max(maxSum, maxEndHere);
        }

        return maxSum;
    }

    void test() {

    }
};
