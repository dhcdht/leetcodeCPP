// https://leetcode.com/problems/first-unique-character-in-a-string/#/description
// 387. First Unique Character in a String
/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
 */
#import <iostream>
#import <string>
#import <unordered_map>

using namespace std;

class Solution54 {
public:
    int firstUniqChar(string s) {
        auto indexCountMap = unordered_map<char, int>();
        for (auto c : s) {
            indexCountMap[c] += 1;
        }

        int result = -1;
        for (int i = 0; i < s.size(); ++i) {
            int count = indexCountMap[s[i]];
            if (count == 1) {
                result = i;
                break;
            }
        }

        return result;
    }

    void test() {
        // 0
//        auto input = string("leetcode");
        // 2
        auto input = string("loveleetcode");
        auto result = this->firstUniqChar(input);
        cout << "387. First Unique Character in a String : " << result << endl;
    }
};
