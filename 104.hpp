// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
// 717. 1-bit and 2-bit Characters
/*
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input:
bits = [1, 0, 0]
Output: True
Explanation:
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input:
bits = [1, 1, 1, 0]
Output: False
Explanation:
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
 */
#import <iostream>
#import "helper.hpp"

class Solution104 {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        bool prevIsOne = false;
        for (int i = 0; i < bits.size() - 1; ++i) {
            if (prevIsOne) {
                if (bits[i] == 1 || bits[i] == 0) {
                    prevIsOne = false;
                }
            } else {
                if (bits[i] == 1) {
                    prevIsOne = true;
                }
            }
        }
        if (prevIsOne) {
            return false;
        } else {
            return true;
        }
    }

    void test() {
        vector < pair < vector < int > , bool >> tests = {
                {{1, 0, 0},    true},
                {{1, 1, 1, 0}, false},
        };
        runUnitTest("104 : 717. 1-bit and 2-bit Characters", tests, [&](auto input) {
            return this->isOneBitCharacter(input);
        });
    }
};
