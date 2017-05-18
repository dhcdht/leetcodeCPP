// https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
// 17. Letter Combinations of a Phone Number
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
#import <iostream>
#import <unordered_map>
#import <string>

class Solution61 {
private:
    unordered_map<char, string> m_digitMap;

public:
    Solution61() {
        m_digitMap['2'] = "abc";
        m_digitMap['3'] = "def";
        m_digitMap['4'] = "ghi";
        m_digitMap['5'] = "jkl";
        m_digitMap['6'] = "mno";
        m_digitMap['7'] = "pqrs";
        m_digitMap['8'] = "tuv";
        m_digitMap['9'] = "wxyz";
        m_digitMap['0'] = " ";
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return vector<string>();
        }

        char firstChar = digits[0];
        string firstWord = m_digitMap[firstChar];

        vector<string> result;
        for (auto c : firstWord) {
            if (digits.size() > 1) {
                string subDigits = digits.substr(1);
                vector<string> subWords = this->letterCombinations(subDigits);
                for (auto word : subWords) {
                    string str = c + word;
                    result.push_back(str);
                }
            } else {
                string str(1, c);
                result.push_back(str);
            }
        }

        return result;
    }

    void test() {
        string input = "23";
        auto output = this->letterCombinations(input);
        cout << "17. Letter Combinations of a Phone Number : ";
        cout << "[";
        for (auto str : output) {
            cout << str << ", ";
        }
        cout << "]" << endl;
    }
};
