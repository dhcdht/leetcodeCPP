// https://leetcode.com/problems/most-common-word/description/
// 819. Most Common Word
/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
 */
#import <iostream>
#import "helper.hpp"
#import <map>

class Solution112 {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        map<string, int> wordCount;
        for (int i = 0; i < banned.size(); ++i) {
            std::transform(banned[i].begin(), banned[i].end(), banned[i].begin(), ::tolower);
            wordCount[banned[i]] = -1;
        }

        string mostCommonWord;
        string curWord;
        for (int i = 0; i < paragraph.size(); ++i) {
            char c = paragraph[i];
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                curWord.append(1, tolower(c));
            } else if (!curWord.empty()) {
                if (wordCount[curWord] == -1) {
                    curWord = "";
                    continue;
                }
                wordCount[curWord] += 1;

                if (mostCommonWord.empty()) {
                    mostCommonWord = curWord;
                } else if (wordCount[mostCommonWord] < wordCount[curWord]) {
                    mostCommonWord = curWord;
                }

                curWord = "";
            }
        }
        if (wordCount[curWord] != -1) {
            wordCount[curWord] += 1;

            if (mostCommonWord.empty()) {
                mostCommonWord = curWord;
            } else if (wordCount[mostCommonWord] < wordCount[curWord]) {
                mostCommonWord = curWord;
            }

            curWord = "";
        }

        return mostCommonWord;
    }

    void test() {
        typedef pair<string, vector<string>> Inputs;
        typedef string Outputs;
        vector<pair<Inputs, Outputs>> tests = {
                {{"Bob hit a ball, the hit BALL flew far after it was hit.", {"hit"}},        "ball"},
                {{"Bob",                                                     {}},             "bob"},
                {{"Bob. hIt, baLl",                                          {"bob", "hit"}}, "ball"},
        };
        runUnitTest("112 : 819. Most Common Word", tests, [&](Inputs input) {
            return this->mostCommonWord(input.first, input.second);
        });
    }
};
