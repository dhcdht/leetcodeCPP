// https://leetcode.com/problems/move-zeroes/#/description
// 283. Move Zeroes
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution35 {
public:
    void moveZeroes(vector<int>& nums) {
        int lastZeroIndex = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num != 0 && -1 != lastZeroIndex) {
                swap(nums[i], nums[lastZeroIndex]);
                ++lastZeroIndex;
            } else if (-1 == lastZeroIndex && 0 == num) {
                lastZeroIndex = i;
            }
        }
    }

    void test() {
//        auto input = vector<int>({0, 1, 0, 3, 12});
        auto input = vector<int>({2, 1});
        this->moveZeroes(input);
        cout << "283. Move Zeroes : ";
        for (auto num : input) {
            cout << num << ",";
        }
        cout << endl;
    }
};
