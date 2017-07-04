// https://leetcode.com/problems/evaluate-reverse-polish-notation/#/description
// 150. Evaluate Reverse Polish Notation
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
#import <iostream>

class Solution75 {
public:
    int evalRPN(vector<string> &tokens) {
        auto nums = stack<int>();

        auto num1 = 0;
        auto num2 = 0;
        for (auto tok : tokens) {
            if (tok.compare("+") == 0) {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                nums.push(num2 + num1);
            } else if (tok.compare("-") == 0) {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                nums.push(num2 - num1);
            } else if (tok.compare("*") == 0) {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                nums.push(num2 * num1);
            } else if (tok.compare("/") == 0) {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                nums.push(num2 / num1);
            } else {
                nums.push(atoi(tok.c_str()));
            }
        }

        return nums.top();
    }

    void test() {
        // 6
        auto tokens = vector<string>({"4", "13", "5", "/", "+"});

        auto result = this->evalRPN(tokens);
        cout << "150. Evaluate Reverse Polish Notation : " << result << endl;
    }
};
