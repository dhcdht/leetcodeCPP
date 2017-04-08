// https://leetcode.com/problems/ransom-note/#/description
// 383. Ransom Note
/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
 */
#import <iostream>
#import <string>
#import <vector>

using namespace std;

class Solution46 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        auto letters = vector<int>(26, 0);
        for (auto c : magazine) {
            letters[c - 'a'] += 1;
        }

        for (auto c : ransomNote) {
            if (letters[c - 'a'] <= 0) {
                return false;
            }

            letters[c - 'a'] -= 1;
        }

        return true;
    }

    void test() {

    }
};
