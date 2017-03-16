// https://leetcode.com/problems/single-number/#/description
// 136. Single Number
/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution15 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for_each(nums.begin(), nums.end(), [&](int num) {
            result ^= num;
        });

        return result;
    }

    void test() {

    }
};
