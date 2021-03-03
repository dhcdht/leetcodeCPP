// https://leetcode.com/problems/basic-calculator-ii/
// 227. Basic Calculator II
/*
Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.



Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5


Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

 */
#import <iostream>
#import "helper.hpp"
#import <string>

class Solution135 {
public:
    int calculate(string s) {
        std::stack<int> nums;
        std::stack<char> opts;

        int curNum = -1;
        for (int i = 0; i < s.length(); ++i) {
            char ic = s[i];

            if ('0' <= ic && ic <= '9') {
                if (curNum == -1) {
                    curNum = ic - '0';
                } else {
                    curNum *= 10;
                    curNum += ic - '0';
                }
            } else {
                if (curNum != -1) {
                    nums.push(curNum);
                    curNum = -1;
                }

                if (ic == '+' || ic == '-' || ic == '*' || ic == '/') {
                    while (!opts.empty() && (opts.top() == '*' || opts.top() == '/')) {
                        int rightNum = nums.top();
                        nums.pop();
                        int leftNum = nums.top();
                        nums.pop();
                        char op = opts.top();
                        opts.pop();

                        if (op == '*') {
                            nums.push(leftNum * rightNum);
                        } else {
                            nums.push(leftNum / rightNum);
                        }
                    }
                    if (ic == '+' || ic == '-') {
                        while (!opts.empty() && (opts.top() == '+' || opts.top() == '-')) {
                            int rightNum = nums.top();
                            nums.pop();
                            int leftNum = nums.top();
                            nums.pop();
                            char op = opts.top();
                            opts.pop();

                            if (op == '+') {
                                nums.push(leftNum + rightNum);
                            } else {
                                nums.push(leftNum - rightNum);
                            }
                        }
                        opts.push(ic);
                    } else if (ic == '*' || ic == '/') {
                        opts.push(ic);
                    }
                }
            }
        }
        if (curNum != -1) {
            nums.push(curNum);
            curNum = -1;
        }

        while (!opts.empty() && (opts.top() == '*' || opts.top() == '/' || opts.top() == '+' || opts.top() == '-')) {
            int rightNum = nums.top();
            nums.pop();
            int leftNum = nums.top();
            nums.pop();
            char op = opts.top();
            opts.pop();

            if (op == '*') {
                nums.push(leftNum * rightNum);
            } else if (op == '/') {
                nums.push(leftNum / rightNum);
            } else if (op == '+') {
                nums.push(leftNum + rightNum);
            } else if (op == '-') {
                nums.push(leftNum - rightNum);
            }
        }

        return nums.top();
    }

    void test()
    {
        struct Input {
            std::string s;
        };
        vector<pair<Input, int>> tests = {
                {{"3+2*2"}, 7},
                {{" 3/2 "}, 1},
                {{" 3+5 / 2 "}, 5},
                {{"1-1+1"}, 1},
        };
        runUnitTest("135 : 227. Basic Calculator II", tests, [&](Input input) {
            return this->calculate(input.s);
        });
    }
};
