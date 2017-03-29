// https://leetcode.com/problems/single-number-iii/#/description
// 260. Single Number III
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */
#import <iostream>

using namespace std;

class Solution33 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        for (auto num : nums) {
            xorResult ^= num;
        }

        int xorResultOnlyLastBitOne = xorResult & ((xorResult - 1) ^ xorResult);

        int a = 0;
        int b = 0;
        for (auto num : nums) {
            if (num & xorResultOnlyLastBitOne) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return vector<int>({a, b});
    }

    void test() {
        auto input = vector<int>({1, 2, 1, 3, 2, 5});
        auto result = this->singleNumber(input);
        cout << "260. Single Number III : ";
        for (auto num : result) {
            cout << num << ",";
        }
        cout << endl;
    }
};
