// https://leetcode.com/problems/sort-characters-by-frequency/#/description
// 451. Sort Characters By Frequency
/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */
#import <iostream>
#import <unordered_map>
#import <string>

using namespace std;

class Solution32 {
public:
    string frequencySort(string s) {
        auto charCountMap = unordered_map<char, int>();
        for (auto c : s) {
            charCountMap[c] += 1;
        }

        auto separateStrings = vector<string>(s.size(), "");
        for (auto it : charCountMap) {
            char c = it.first;
            int charCount = it.second;

            separateStrings[charCount-1].append(charCount, c);
        }

        string result;
        for (int i = separateStrings.size() - 1; i >= 0; --i) {
            string str = separateStrings[i];
            if (!str.empty()) {
                result.append(str);
            }
        }

        return result;
    }

    void test() {
        auto input = string("tree");
//        auto input = string("tee");
        auto result = this->frequencySort(input);
        cout << "451. Sort Characters By Frequency : " << result << endl;
    }
};
