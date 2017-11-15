// https://leetcode.com/problems/power-of-three/description/
// 326. Power of Three
/*
Given an integer, write a function to determine if it is a power of three.
 */
#import <iostream>

class Solution98 {
public:
    bool isPowerOfThree(int n) {
        if (0 == n) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }

    void test() {

    }
};
