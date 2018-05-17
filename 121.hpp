// https://leetcode.com/problems/positions-of-large-groups/description/
// 830. Positions of Large Groups
/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.



Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]


Note:  1 <= S.length <= 1000
 */
#import <iostream>
#import "helper.hpp"

class Solution121 {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int left = 0;
        int right = 0;
        char lastChar = ' ';
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != lastChar) {
                if (right - left + 1 >= 3) {
                    result.push_back({left, right});
                }

                left = i;
                right = i;
                lastChar = S[i];
            }

            right = i;
        }
        if (right - left + 1 >= 3) {
            result.push_back({left, right});
        }

        return result;
    }

    void test() {
        typedef vector<vector<int>> Output;
        vector<pair<string, Output>> tests = {
                {"abbxxxxzzy",        {{3, 6}}},
                {"abc",               {}},
                {"abcdddeeeeaabbbcd", {{3, 5}, {6, 9}, {12, 14}}}
        };
        runUnitTest("121 : 830. Positions of Large Groups", tests, [&](string input) {
            return this->largeGroupPositions(input);
        });
    }
};
