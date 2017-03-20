// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/#/description
// 448. Find All Numbers Disappeared in an Array
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */
#import <iostream>

using namespace std;

class Solution17 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        auto result = vector<int>();

        int numHasNotAppearFlag = -1;
        int numHasAppearFlag = -2;
        for (int i = 0; i < nums.size(); ++i) {
            int curIndex = i;
            while (nums[curIndex] > 0) {
                int nextIndex = nums[curIndex];
                nums[curIndex] = numHasNotAppearFlag;
                curIndex = nextIndex - 1;
            }
            if (nums[curIndex] == numHasNotAppearFlag) {
                nums[curIndex] = numHasAppearFlag;
            }
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == numHasNotAppearFlag) {
                result.push_back(j+1);
            }
        }

        return result;
    }

    void test() {
        auto input = vector<int>({4,3,2,7,8,2,3,1});
        auto output = this->findDisappearedNumbers(input);
        cout << "448. Find All Numbers Disappeared in an Array : ";
        for_each(output.begin(), output.end(), [&](int num) {
            cout << num << ", ";
        });
        cout << endl;
    }
};
