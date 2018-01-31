// https://leetcode.com/problems/permutations/description/
// 46. Permutations
/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
#import <iostream>

class Solution100 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() <= 1) {
            return {nums};
        }

        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            auto subNums = nums;
            subNums.erase(subNums.begin() + i);

            auto subPremute = this->permute(subNums);
            for (int j = 0; j < subPremute.size(); ++j) {
                auto ele = subPremute[j];
                ele.insert(ele.begin(), nums[i]);
                subPremute[j] = ele;
            }

            ret.insert(ret.end(), subPremute.begin(), subPremute.end());
        }

        return ret;
    }

    void test() {
        vector<int> nums = {1, 2, 3};
        auto result = this->permute(nums);
    }
};
