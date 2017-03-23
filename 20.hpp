// https://leetcode.com/problems/find-all-duplicates-in-an-array/#/description
// 442. Find All Duplicates in an Array
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
 */
#import <iostream>

using namespace std;

class Solution20 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        auto result = vector<int>();

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != j + 1) {
                result.push_back(nums[j]);
            }
        }

        return result;
    }

    void test() {
        auto input = vector<int>({4,3,2,7,8,2,3,1});
        auto output = this->findDuplicates(input);
        cout << "442. Find All Duplicates in an Array : ";
        for_each(output.begin(), output.end(), [=](int num) {
            cout << num << ", ";
        });
        cout << endl;
    }
};
