// https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description
// 438. Find All Anagrams in a String
/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */
#import <iostream>
#import <map>

class Solution67 {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return vector<int>();
        }

        auto mask = unordered_map<char, int>(p.length());
        for (int i = 0; i < p.length(); ++i) {
            mask[p[i]] += 1;
        }

        auto result = vector<int>();
        auto check = unordered_map<char, int>(mask);
        auto checkBegin = -1;
        auto checkCount = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (check[s[j]] > 0) {
                if (-1 == checkBegin) {
                    checkBegin = j;
                }

                checkCount += 1;
                check[s[j]] -= 1;

                if (checkCount == p.length()) {
                    result.push_back(checkBegin);

                    if (j + 1 < s.length() && mask[s[j + 1]] > 0) {
                        check[s[checkBegin]] += 1;
                        checkBegin += 1;
                        checkCount -= 1;
                    } else {
                        checkBegin = -1;
                        check = unordered_map<char, int>(mask);
                        checkCount = 0;
                    }
                }
            } else {
                if (-1 != checkBegin) {
                    if (checkCount > 1) {
                        check[s[checkBegin]] += 1;
                        checkBegin += 1;
                        checkCount -= 1;
                    } else {
                        checkBegin = -1;
                        check = unordered_map<char, int>(mask);
                        checkCount = 0;
                    }

                    --j;
                }
            }
        }

        return result;
    }

    void test() {
        // [0, 6]
//        string s = "cbaebabacd";
//        string p = "abc";
        // [0, 1, 2]
//        string s = "abab";
//        string p = "ab";
        // [1, 2, 3, 5]
//        string s = "abacbabc";
//        string p = "abc";
        // 1, 3, 6, 7
//        string s = "acdcaeccde";
//        string p = "c";
        // 3, 4, 6
//        string s = "abaacbabc";
//        string p = "abc";
        // 0, 6
        string s = "cbaebabacd";
        string p = "abc";

        auto result = this->findAnagrams(s, p);
        cout << "438. Find All Anagrams in a String : ";
        for (auto item : result) {
            cout << item << ", ";
        }
        cout << endl;
    }
};
