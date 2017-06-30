// https://leetcode.com/problems/permutation-in-string/#/description
// 567. Permutation in String
/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
 */
#import <iostream>
#import <string>

class Solution70 {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty()) {
            return true;
        }
        if (s1.length() > s2.length()) {
            return false;
        }

        auto charMask = vector<int>(26, 0);
        for (int i = 0; i < s1.length(); ++i) {
            charMask[s1[i] - 'a'] += 1;
            charMask[s2[i] - 'a'] -= 1;
        }
        if (this->isAllZero(charMask)) {
            return true;
        }

        for (int i = s1.length(); i < s2.length(); ++i) {
            charMask[s2[i] - 'a'] -= 1;
            charMask[s2[i - s1.length()] - 'a'] += 1;
            if (this->isAllZero(charMask)) {
                return true;
            }
        }

        return false;
    }

    bool isAllZero(vector<int> &charMask) {
        for (auto item : charMask) {
            if (item != 0) {
                return false;
            }
        }

        return true;
    }

    void test() {
        string s1 = "osmzg";
        string s2 = "diyhaywtgpzosgmuxvidndouo";

        auto result = this->checkInclusion(s1, s2);
    }
};
