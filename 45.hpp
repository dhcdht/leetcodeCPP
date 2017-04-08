// https://leetcode.com/problems/longest-uncommon-subsequence-i/#/description
// 521. Longest Uncommon Subsequence I
/*
Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc"
Output: 3
Explanation: The longest uncommon subsequence is "aba" (or "cdc"),
because "aba" is a subsequence of "aba",
but not a subsequence of any other strings in the group of two strings.
Note:

Both strings' lengths will not exceed 100.
Only letters from a ~ z will appear in input strings.
 */
#import <iostream>
#import <string>

using namespace std;

class Solution45 {
public:
    int findLUSlength(string a, string b) {
        int aLength = a.size();
        int bLength = b.size();
        if (aLength != bLength) {
            return aLength > bLength ? aLength : bLength;
        }

        for (int i = 0; i < aLength; ++i) {
            if (a[i] != b[i]) {
                return aLength;
            }
        }

        return -1;
    }

    void test() {
        // 3
//        auto a = string("aba");
//        auto b = string("cdc");
        // 17
//        auto a = string("aefawfawfawfaw");
//        auto b = string("aefawfeawfwafwaef");
        // 30
        auto a = string("horbxeemlgqpqbujbdagizcfairalg");
        auto b = string("iwvtgyojrfhyzgyzeikqagpfjoaeen");
        auto result = this->findLUSlength(a, b);
        cout << "521. Longest Uncommon Subsequence I : " << result << endl;
    }
};
