// https://leetcode.com/problems/detect-capital/#/description
// 520. Detect Capital
/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 */
#import <iostream>
#import <string>

using namespace std;

class Solution16 {
public:
    bool detectCapitalUse(string word) {
        bool isBeginWithUpcase = (word[0] >= 'A' && word[0] <= 'Z');
        bool isAllUpcase = false;
        if (word.length() > 1) {
            isAllUpcase = (word[1] >= 'A' && word[1] <= 'Z');
        }
        for (int i = 1; i < word.length(); ++i) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (!isBeginWithUpcase) {
                    return false;
                } else {
                    if (!isAllUpcase) {
                        return false;
                    }
                }
            } else {
                if (isAllUpcase) {
                    return false;
                }
            }
        }

        return true;
    }

    void test() {
//        string input = "USA";
//        string input = "FlaG";
        string input = "test";
        bool result = this->detectCapitalUse(input);
        cout << "520. Detect Capital : " << result << endl;
    }
};
