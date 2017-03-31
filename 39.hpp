// https://leetcode.com/problems/relative-ranks/#/description
// 506. Relative Ranks
/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
 */
#import <iostream>
#import <unordered_map>

using namespace std;

class Solution39 {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto rankIndex = vector<int>(nums.begin(), nums.end());

        sort(rankIndex.begin(), rankIndex.end(), [&](int obj1, int obj2) {
            return obj1 > obj2;
        });

        auto scoreRankMap = unordered_map<int, int>();
        for (int i = 0; i < rankIndex.size(); ++i) {
            scoreRankMap[rankIndex[i]] = i;
        }

        auto result = vector<string>(nums.size());
        for (int j = 0; j < nums.size(); ++j) {
            int num = nums[j];
            int rank = scoreRankMap[num];
            if (0 == rank) {
                result[j] = "Gold Medal";
            } else if (1 == rank) {
                result[j] = "Silver Medal";
            } else if (2 == rank) {
                result[j] = "Bronze Medal";
            } else {
                ostringstream oss;
                oss << rank + 1;
                result[j] = oss.str();
            }
        }

        return result;
    }

    void test() {
        vector<int> input = {1, 5, 3, 4, 2};
        auto result = this->findRelativeRanks(input);
        cout << "506. Relative Ranks ";
        for (auto str : result) {
            cout << str << ",";
        }
        cout << endl;
    }
};
