// https://leetcode.com/problems/product-of-array-except-self/#/description
// 238. Product of Array Except Self
/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution36 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }

        auto result = vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int mutil = nums[nums.size() - 1];
        for (int j = nums.size() - 2; j >= 0; --j) {
            result[j] *= mutil;
            mutil *= nums[j];
        }

        return result;
    }

    void test() {
//        vector<int> input = {1,2,3,4};
        vector<int> input = {1, 0};
        auto result = this->productExceptSelf(input);
        cout << "238. Product of Array Except Self : ";
        for (auto num : result) {
            cout << num << ",";
        }
        cout << endl;
    }
};
