// https://leetcode.com/problems/merge-intervals/description/
// 56. Merge Intervals
/*
Given a collection of intervals, merge all overlapping intervals.

Example:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 */
#import <iostream>
#import <vector>

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool operator==(const Interval &lhs, const Interval &rhs) {
    return ((lhs.start == rhs.start) && (lhs.end == rhs.end));
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution106 {
public:
    vector <Interval> merge(vector <Interval> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end(), [](const Interval &obj1, const Interval &obj2) {
            return obj1.start < obj2.start;
        });

        vector <Interval> results;
        int curStart = intervals[0].start;
        int curEnd = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].end <= curEnd) {
                continue;
            } else if (intervals[i].start <= curEnd) {
                curEnd = intervals[i].end;
            } else {
                results.push_back(Interval(curStart, curEnd));
                curStart = intervals[i].start;
                curEnd = intervals[i].end;
            }
        }
        if (results.empty() || results.back().start != curStart || results.back().end != curEnd) {
            results.push_back(Interval(curStart, curEnd));
        }

        return results;
    }

    void test() {
        vector < pair < vector < Interval > , vector < Interval >> > tests = {
                {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
                {{{1, 4}, {4, 5}},                    {{1, 5}}},
        };
        runUnitTest("106 : 56. Merge Intervals", tests, [&](auto input) {
            return this->merge(input);
        });
    };
};
