// https://leetcode.com/problems/number-complement/#/description
// 476. Number Complement
/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

*/
#import <iostream>

using namespace std;

class Solution2 {
public:
    int findComplement(int num) {
        int result = 0;
        int mask = 0x1;
        while (num > 0) {
            if (!(num & 0x1)) {
                result |= mask;
            }

            mask <<= 1;
            num >>= 1;
        }

        return result;
    }

    void test() {
        int x = 5;
        int result = this->findComplement(x);
        cout << "476. Number Complement : " << result << endl;
    }
};
