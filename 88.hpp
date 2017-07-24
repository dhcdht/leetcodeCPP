// https://leetcode.com/problems/student-attendance-record-i/#/description
// 551. Student Attendance Record I
/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
 */
#import <iostream>
#import <string>

class Solution88 {
public:
    bool checkRecord(string s) {
        if (s.find("LLL") != string::npos) {
            return false;
        }

        auto aCount = 0;
        for (auto c : s) {
            if (c == 'A') {
                aCount += 1;
                if (aCount >= 2) {
                    return false;
                }
            }
        }

        return true;
    }

    void test() {

    }
};
