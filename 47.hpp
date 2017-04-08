// https://leetcode.com/problems/intersection-of-two-arrays/#/description
// 349. Intersection of Two Arrays
/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
 */
#import <iostream>
#import <unordered_set>

using namespace std;

class Solution47 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        auto nums1Set = unordered_set<int>();
        for (auto num : nums1) {
            nums1Set.insert(num);
        }

        auto instersection = unordered_set<int>();
        for (auto num : nums2) {
            auto it = nums1Set.find(num);
            if (it != nums1Set.end()) {
                instersection.insert(num);
            }
        }

        auto result = vector<int>();
        for (auto num : instersection) {
            result.push_back(num);
        }

        return result;
    }

    void test() {
        auto nums1 = vector<int>({1});
        auto nums2 = vector<int>({1, 1});
        auto result = this->intersection(nums1, nums2);
    }
};
