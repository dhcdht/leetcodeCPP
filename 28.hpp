// https://leetcode.com/problems/sum-of-two-integers/#/description
// 371. Sum of Two Integers
/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
 */
#import <iostream>

using namespace std;

class Solution28 {
public:
    int getSum(int a, int b) {
        int result = 0;

        int mask = 0x1;
        bool carryBit = false;
        while (mask) {
            int maskA = a & mask;
            int maskB = b & mask;

            if (maskA != 0 && maskB != 0) {
                if (carryBit) {
                    result |= mask;
                }
                carryBit = true;
            } else if (0 == maskA && 0 == maskB) {
                if (carryBit) {
                    result |= mask;
                }
                carryBit = false;
            } else {
                if (!carryBit) {
                    result |= mask;
                }
            }

            mask <<= 1;
        }

        return result;
    }

    void test() {
//        int a = 1;
//        int b = 2;
        int a = -12;
        int b = -8;
        int result = this->getSum(a, b);
        cout << "371. Sum of Two Integers : " << result << endl;
    }
};
