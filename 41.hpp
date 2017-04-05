// https://leetcode.com/problems/top-k-frequent-elements/#/description
// 347. Top K Frequent Elements
/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
#import <iostream>
#import <unordered_map>
#import <vector>

using namespace std;

class Solution41 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto numCountMap = unordered_map<int, int>();
        auto maxCount = 0;
        for (auto num : nums) {
            int newCount = numCountMap[num] + 1;
            numCountMap[num] = newCount;
            if (newCount > maxCount) {
                maxCount = newCount;
            }
        }

        auto bucket = vector<vector<int>>(maxCount+1);
        for (auto mp : numCountMap) {
            bucket[mp.second].push_back(mp.first);
        }

        vector<int> result;
        for (int i = maxCount; i >= 0; --i) {
            auto numsV = bucket[i];
            for (auto num : numsV) {
                result.push_back(num);

                if (result.size() >= k) {
                    return result;
                }
            }
        }

        return result;
    }

    void test() {
        auto nums = vector<int>({1, 1, 1, 2, 2, 3});
        auto k = 2;
        auto result = this->topKFrequent(nums, k);
        cout << "347. Top K Frequent Elements : ";
        for (auto num : result) {
            cout << num << ",";
        }
        cout << endl;
    }
};
