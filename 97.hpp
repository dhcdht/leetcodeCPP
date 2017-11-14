// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
// 557. Reverse Words in a String III
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */
#import <iostream>
#import <vector>
#import <string>

class Solution97 {
public:
    string reverseWords(string s) {
        auto sSplits = this->split(s);

        string ret = string();
        for (int i = 0; i < sSplits.size(); ++i) {
            string str = sSplits[i];

            string revStr = this->reverse(str);
            ret.append(revStr);
        }

        return ret;
    }

    vector<string> split(string s) {
        auto ret = vector<string>();
        unsigned pos = 0;
        for (unsigned int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (pos < i) {
                    ret.push_back(s.substr(pos, i - pos));
                }
                ret.push_back(" ");
                pos = i + 1;
            }
        }
        if (pos < s.length()) {
            ret.push_back(s.substr(pos, s.length() - pos));
        }

        return ret;
    }

    string reverse(string s) {
        string ret = string();
        for (int i = s.length() - 1; i >= 0; --i) {
            ret.push_back(s[i]);
        }

        return ret;
    }

    void test() {
        string input = "Let's take LeetCode contest";
        string output = this->reverseWords(input);
        cout << "557. Reverse Words in a String III : " << output << std::endl;
    }
};
