// https://leetcode.com/problems/optimal-division/description/
// 553. Optimal Division
/*
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
since they don't influence the operation priority. So you should return "1000/(100/10/2)".

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
 */
#import <iostream>
#import "helper.hpp"

class Solution117 {
public:
    string optimalDivision(vector<int> &nums) {
        if (nums.size() < 3) {
            return this->divisionSequeue(nums, 0, nums.size());
        }

        string out = std::to_string(nums[0]);
        out.append("/(");
        string divisionSequeue = this->divisionSequeue(nums, 1, nums.size());
        out.append(divisionSequeue);
        out.append(")");

        return out;
    }

    string divisionSequeue(vector<int> &nums, int beginIndex, int endIndex) {
        string out = std::to_string(nums[beginIndex]);
        for (int i = beginIndex + 1; i < endIndex; ++i) {
            out.append("/");
            out.append(std::to_string(nums[i]));
        }

        return out;
    }

    void test() {
        typedef vector<int> Input;
        typedef string Output;
        vector<pair<Input, Output>> tests = {
                {{1000, 100},           "1000/100"},
                {{1000, 100, 10, 2},    "1000/(100/10/2)"},
                {{2,    3,   4},        "2/(3/4)"},
                {{6,    2,   3,  4, 5}, "6/(2/3/4/5)"},
        };
        runUnitTest("117 : 553. Optimal Division", tests, [&](Input input) {
            return this->optimalDivision(input);
        });
    }
};
