// https://leetcode.com/problems/add-digits/#/description
// 258. Add Digits
/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
 */
#import <iostream>

using namespace std;

class Solution31 {
public:
    int addDigits(int num) {
        if (0 == num) {
            return 0;
        }

        return num % 9 ?: 9;
    }

    void test() {
//        auto input = 38;
//        auto input = 9;
        auto input = 18;
        auto result = this->addDigits(input);
        cout << "258. Add Digits : " << result << endl;
    }
};
