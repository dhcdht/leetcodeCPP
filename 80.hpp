// https://leetcode.com/problems/nth-digit/#/description
// 400. Nth Digit
/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */
#import <iostream>

class Solution80 {
public:
    int findNthDigit(int n) {
        // 10 以内的直接返回
        if (n < 10) {
            return n;
        }

        // 要找的数字所在的数是个几位数
        long digitCount = 2;
        // n 位数的初始数是多少
        long baseNumber = 10;
        // 要找的数字是 digitCount 位数，那么 digitCount 位数的最小序号是 baseTh
        long baseTh = 10;
        while (baseTh + baseNumber * 9 * digitCount < n) {
            baseTh += baseNumber * 9 * digitCount;
            digitCount += 1;
            baseNumber *= 10;
        }

        // 要找的数字跟 baseTh 比较是第几个数字，0开始
        auto offsetTh = n - baseTh;
        // 要找的数字所在的数的偏移量
        auto offsetNum = offsetTh / digitCount;
        // 要找的数字所在的数
        auto number = baseNumber + offsetNum;
        // 要找的数字是这个数的第一个数字，0开始
        auto numberOffset = offsetTh - (offsetNum * digitCount);

        auto result = 0;
        for (int i = 0; i < digitCount - numberOffset; ++i) {
            result = number % 10;
            number /= 10;
        }

        return result;
    }

    void test() {
        // 0
//        auto n = 11;
        // 1
//        auto n = 10;
        // 7
//        auto n = 10000;
        // 1
        auto n = 1000000000;

        auto result = this->findNthDigit(n);
        cout << "400. Nth Digit : " << result << endl;
    }
};
