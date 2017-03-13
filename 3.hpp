// https://leetcode.com/problems/keyboard-row/#/description
// 500. Keyboard Row
/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
 */
#import <iostream>
#import <string>
#import <vector>
#import <algorithm>

using namespace std;

class Solution3 {
private:
    vector<string> keyboards = vector<string>({
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm",
    });

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for_each(words.begin(), words.end(), [&](string str) {
            string lowerStr = string(str);
            transform(str.begin(), str.end(), lowerStr.begin(), ::tolower);

            for_each(this->keyboards.begin(), this->keyboards.end(), [&](string keyboardStr) {
                bool isInRow = true;
                for_each(lowerStr.begin(), lowerStr.end(), [&](char c) {
                    if (keyboardStr.find(c) == string::npos) {
                        isInRow = false;
                        return;
                    }
                });
                if (isInRow) {
                    result.push_back(str);
                    return;
                }
            });
        });

        return result;
    }

    void test() {
        auto input = vector<string>({"Hello", "Alaska", "Dad", "Peace"});
        auto output = this->findWords(input);
    }
};
