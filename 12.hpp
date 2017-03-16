// https://leetcode.com/problems/max-consecutive-ones/#/description
// 485. Max Consecutive Ones
/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution12 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;

        int curMax = 0;
        for_each(nums.begin(), nums.end(), [&](int num) {
            if (num == 1) {
                curMax += 1;
            } else {
                if (curMax > result) {
                    result = curMax;
                }

                curMax = 0;
            }
        });
        if (curMax > result) {
            result = curMax;
        }

        return result;
    }

    void test() {

    }
};
