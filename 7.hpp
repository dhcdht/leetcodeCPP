// https://leetcode.com/problems/reverse-string/#/description
// 344. Reverse String
/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */
#import <iostream>
#import <algorithm>

using namespace std;

class Solution7 {
public:
    string reverseString(string s) {
        string result(s.size(), ' ');
        reverse_copy(s.begin(), s.end(), result.begin());

        return result;
    }

    void test() {
        string input("hello");
        string output = this->reverseString(input);
        cout << "344. Reverse String : " << output << endl;
    }
};
