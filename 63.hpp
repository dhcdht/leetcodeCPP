// https://leetcode.com/problems/majority-element/#/description
// 169. Majority Element
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 */
#import <iostream>
#import <unordered_map>

// beats 61.43%
class Solution63 {
public:
    int majorityElement(vector<int>& nums) {
        // 记录数字和其出现次数
        auto countMap = unordered_map<int, int>();

        // 计数
        for (auto num : nums) {
            countMap[num] += 1;
        }

        // 出现最多的数字
        int maxNum = 0;
        // 出现最多的数字出现的次数
        int maxNumCount = 0;
        // 遍历一次计数 map，找出出现最多的
        for (auto map : countMap) {
            if (map.second > maxNumCount) {
                maxNum = map.first;
                maxNumCount = map.second;
            }
        }

        return maxNum;
    }

    void test() {

    }
};
