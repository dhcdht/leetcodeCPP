// https://leetcode.com/problems/excel-sheet-column-number/#/description
// 171. Excel Sheet Column Number
/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
Credits:
Special thanks to @ts for adding this problem and creating all test cases.


 */
#import <iostream>

using namespace std;

class Solution55 {
public:
    int titleToNumber(string s) {
        int result = 0;

        int power = 1;
        for (int i = s.size()-1; i >= 0; --i) {
            int index = s[i] - 'A';
            result += power * (index + 1);
            power *= 26;
        }

        return result;
    }

    void test() {
        // 27
//        auto input = string("AA");
        // 53
//        auto input = string("BA");
        // 703
        auto input = string("AAA");
        auto result = this->titleToNumber(input);
        cout << "171. Excel Sheet Column Number : " << result << endl;
    }
};
