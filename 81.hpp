// https://leetcode.com/problems/integer-to-roman/#/description
// 12. Integer to Roman
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
 */
#import <iostream>

class Solution81 {
public:
    string intToRoman(int num) {
        // 1, 5, 10, 50, 100, 500, 1000
        auto baseNumStrings = vector<string>({"I", "V", "X", "L", "C", "D", "M"});

        auto result = string("");

        auto number = num;
        auto power = 1000;
        auto index = baseNumStrings.size() - 1;
        for (int i = 0; i < 4; ++i) {
            auto n = number / power;
            if (n == 9) {
                result.append(baseNumStrings[index] + baseNumStrings[index + 2]);
            } else if (n >= 5) {
                result.append(baseNumStrings[index + 1]);
                for (int j = 0; j < n - 5; ++j) {
                    result.append(baseNumStrings[index]);
                }
            } else if (n == 4) {
                result.append(baseNumStrings[index]);
                result.append(baseNumStrings[index + 1]);
            } else if (n >= 1) {
                for (int j = 0; j < n; ++j) {
                    result.append(baseNumStrings[index]);
                }
            }

            index -= 2;
            number %= power;
            power /= 10;
        }

        return result;
    }

    void test() {
        auto num = 101;

        auto result = this->intToRoman(num);
        cout << "12. Integer to Roman : " << result << endl;
    }
};
