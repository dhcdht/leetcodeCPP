// https://leetcode.com/problems/daily-temperatures/description/
// 739. Daily Temperatures
/*
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */
#import <iostream>
#import "helper.hpp"
#import <vector>
#import <stack>

class Solution122 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> nextIndexs;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!nextIndexs.empty()) {
                int topIndex = nextIndexs.top();
                if (temperatures[i] >= temperatures[topIndex]) {
                    nextIndexs.pop();
                } else {
                    break;
                }
            }
            if (nextIndexs.empty()) {
                result[i] = 0;
            } else {
                result[i] = nextIndexs.top() - i;
            }
            nextIndexs.push(i);
        }

        return result;
    }

    void test() {
        typedef vector<int> Input;
        typedef vector<int> Output;
        vector <pair<Input, Output>> tests = {
                {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        };
        runUnitTest("122 : 739. Daily Temperatures", tests, [&](Input input) {
            return this->dailyTemperatures(input);
        });
    }
};
