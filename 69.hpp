// https://leetcode.com/problems/search-for-a-range/#/description
// 34. Search for a Range
/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */
#import <iostream>

class Solution69 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        auto result = vector<int>(2, -1);

        auto left = 0;
        auto right = (int) (nums.size() - 1);
        auto middle = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                if (right == middle) {
                    break;
                }

                right = middle;
            } else {
                if (middle == 0) {
                    break;
                } else {
                    if (nums[middle - 1] < target) {
                        break;
                    } else {
                        right = middle;
                    }
                }
            }
        }
        if (nums[middle] == target) {
            result[0] = middle;
        }

        left = 0;
        right = (int) (nums.size() - 1);
        middle = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                if (right == middle) {
                    break;
                }

                right = middle;
            } else {
                if (middle == nums.size() - 1) {
                    break;
                } else {
                    if (nums[middle + 1] > target) {
                        break;
                    } else {
                        left = middle + 1;
                    }
                }
            }
        }
        if (nums[middle] == target) {
            result[1] = middle;
        }

        return result;
    }

    void test() {

    }
};
