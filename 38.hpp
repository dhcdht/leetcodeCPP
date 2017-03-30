// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/#/description
// 167. Two Sum II - Input array is sorted
/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution38 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        int left = numbers[leftIndex];
        int right = numbers[rightIndex];
        int sum = left + right;
        while (sum != target) {
            if (sum < target) {
                ++leftIndex;
            } else {
                --rightIndex;
            }

            if (leftIndex == rightIndex) {
                return vector<int>();
            }

            left = numbers[leftIndex];
            right = numbers[rightIndex];
            sum = left + right;
        }

        return vector<int>({leftIndex + 1, rightIndex + 1});
    }

    void test() {
        vector<int> numbers = {2, 7, 11, 15};
        int target = 9;
        auto result = this->twoSum(numbers, target);
        cout << "167. Two Sum II - Input array is sorted ";
        for (auto num : result) {
            cout << num << ",";
        }
        cout << endl;
    }
};
