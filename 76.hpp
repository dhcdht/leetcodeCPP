// https://leetcode.com/problems/find-the-duplicate-number/#/description
// 287. Find the Duplicate Number
/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */
#import <iostream>

class Solution76 {
public:
    int findDuplicate(vector<int> &nums) {
        auto one = 0;
        auto two = 1;

        while (nums[one] != nums[two]) {
            one += 1;
            one = one % nums.size();
            two += 2;
            two = two % nums.size();

            if (two == one) {
                two += 1;
                two = two % nums.size();
            }
        }

        return nums[one];
    }

    void test() {
//        auto nums = vector<int>({4, 3, 1, 4, 2});
        auto nums = vector<int>({2, 5, 9, 6, 9, 3, 8, 9, 7, 1});

        auto result = this->findDuplicate(nums);
        cout << "287. Find the Duplicate Number : " << result << endl;
    }
};
