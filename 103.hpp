// https://leetcode.com/problems/longest-valid-parentheses/description/
// 32. Longest Valid Parentheses
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#import <iostream>
#import <stack>
#import <map>
#import <string>

class Solution103 {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                if (left + right > maxlength) {
                    maxlength = left + right;
                }
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                if (left + right > maxlength) {
                    maxlength = left + right;
                }
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }

    
    int longestValidParentheses2(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int top = st.top();
                    st.pop();
                    s[top] = 'x';
                    s[i] = 'x';
                }
            }
        }

        int maxLength = 0;
        int curLength = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'x') {
                curLength += 1;
                if (curLength > maxLength) {
                    maxLength = curLength;
                }
            } else {
                curLength = 0;
            }
        }

        return maxLength;
    }

    void test() {
        vector<pair<string, int>> tests = {
                {"()",                                                                                2},
                {"(()",                                                                               2},
                {")()())",                                                                            4},
                {"()(()",                                                                             2},
                {"()(())",                                                                            6},
                {
                 ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())"
                 "((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())", 132
                },
        };
        cout << "32. Longest Valid Parentheses : " << endl;
        for (auto item : tests) {
            string key = item.first;
            int value = item.second;
            int result = this->longestValidParentheses(key);

            string sign = result == value ? "✅" : "❌";
            cout << "\t";
            cout << sign;
            cout << " " << key << " , " << value;
            cout << " : " << result;
            cout << endl;
        }
    }
};
