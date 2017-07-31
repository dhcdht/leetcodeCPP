// https://leetcode.com/problems/next-greater-element-iii/description/
// 556. Next Greater Element III
/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
 */
#import <iostream>

class Solution92 {
public:
    int nextGreaterElement(int n) {
        auto nums = vector<int>();
        auto num = n;
        while (num > 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        if (nums.size() <= 1) {
            return -1;
        }

        auto downIndex = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                downIndex = i;
                break;
            }
        }
        if (0 == downIndex) {
            return -1;
        }

        auto smallIndex = -1;
        for (int i = 0; i < downIndex; ++i) {
            if (nums[i] > nums[downIndex]) {
                if (-1 == smallIndex) {
                    smallIndex = i;
                } else if (nums[i] == nums[smallIndex]) {
                    smallIndex = i;
                } else {
                    break;
                }
            }
        }
        swap(nums[downIndex], nums[smallIndex]);

        sort(nums.begin(), nums.begin() + downIndex, [](int o1, int o2) {
            return o1 > o2;
        });

        auto power = 1;
        auto result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += nums[i] * power;
            power *= 10;
        }

        return result > n ? result : -1;
    }

    void test() {
        // -1
//        auto n = 21;
        // 21
//        auto n = 12;
        // 1243
//        auto n = 1234;
        // 12223233
//        auto n = 12222333;
        // 13222344
//        auto n = 12443322;
        // -1
        auto n = 1999999999;

        auto result = this->nextGreaterElement(n);
        cout << "556. Next Greater Element III : " << result << endl;
    }
};
