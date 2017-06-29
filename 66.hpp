// https://leetcode.com/problems/longest-palindromic-substring/#/description
// 5. Longest Palindromic Substring
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
 */
#import <iostream>

class Solution66 {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        auto minLeft = 0;
        auto maxRight = 0;
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[i - 1] == s[i + 1]) {
                auto left = i - 1;
                auto right = i + 1;
                do {
                    left -= 1;
                    right += 1;
                    if (left < 0) {
                        break;
                    }
                    if (right >= s.length()) {
                        break;
                    }
                } while (s[left] == s[right]);
                left += 1;
                right -= 1;

                if (right - left > maxRight - minLeft) {
                    minLeft = left;
                    maxRight = right;
                }
            }
        }

        for (int j = 1; j < s.length(); ++j) {
            if (s[j - 1] == s[j]) {
                auto left = j - 1;
                auto right = j;
                do {
                    left -= 1;
                    right += 1;
                    if (left < 0) {
                        break;
                    }
                    if (right >= s.length()) {
                        break;
                    }
                } while (s[left] == s[right]);
                left += 1;
                right -= 1;

                if (right - left > maxRight - minLeft) {
                    minLeft = left;
                    maxRight = right;
                }
            }
        }

        auto result = s.substr(minLeft, maxRight - minLeft + 1);

        return result;
    }

    void test() {
        // bab || aba
//        string input = "babad";
        // bb
//        string input = "cbbd";
        // ""
//        string input = "";
        // a
        string input = "a";
        auto result = this->longestPalindrome(input);
        cout << "5. Longest Palindromic Substring : " << result << endl;
    }
};
