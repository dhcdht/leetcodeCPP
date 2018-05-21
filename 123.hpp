// https://leetcode.com/problems/repeated-string-match/description/
// 686. Repeated String Match
/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
 */
#import <iostream>
#import "helper.hpp"
#import <string>
#import <vector>

class Solution123 {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 1;
        string t = A;
        while (A.size() < B.size()) {
            A += t;
            i++;
        }
        if (strstr(A.c_str(), B.c_str())) {
            return i;
        }
        A += t;
        if (strstr(A.c_str(), B.c_str())) {
            return i + 1;
        }

        return -1;
    }

    void test() {
        typedef pair <string, string> Input;
        typedef int Output;
        vector <std::pair<Input, Output>> tests = {
                {{"abcd", "cdabcdab"}, 3},
        };
        runUnitTest("123 : 686. Repeated String Match", tests, [&](Input input) {
            return this->repeatedStringMatch(input.first, input.second);
        });
    }
};
