// https://leetcode.com/problems/palindromic-substrings/description/
// 647. Palindromic Substrings
/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
 */
#import <iostream>
#import "helper.hpp"
#import <string>
#import <unordered_map>
#import <list>

class Solution118 {
public:
    int countSubstrings(string s) {
        int count = s.length();
        for (int i = 0; i < s.length(); ++i) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }

                count += 1;
                left--;
                right++;
            }
        }

        for (int i = 0; i < s.length(); ++i) {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }

                count += 1;
                left--;
                right++;
            }
        }

        return count;
    }

    void test() {
        typedef string Input;
        typedef int Output;
        vector<pair<Input, Output>> tests = {
                {"abc", 3},
                {"aaa", 6},
        };
        runUnitTest("118 : 647. Palindromic Substrings", tests, [&](Input input) {
            return this->countSubstrings(input);
        });
    }
};
