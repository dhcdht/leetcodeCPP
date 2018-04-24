// https://leetcode.com/problems/non-overlapping-intervals/description/
// 435. Non-overlapping Intervals
/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 */
#import <iostream>
#import "helper.hpp"
#import "106.hpp"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution110 {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end(), [](const Interval &obj1, const Interval &obj2) {
            return obj1.start < obj2.start;
        });

        int removeCount = 0;
        int cur = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= intervals[cur].end) {
                cur = i;
            } else {
                removeCount += 1;
                if (intervals[i].end < intervals[cur].end) {
                    cur = i;
                }
            }
        }

        return removeCount;
    }

    void test() {
        vector<pair<vector<Interval>, int >> tests = {
                {{{1, 2},   {2,  3},  {3, 4},  {1, 3}},  1},
                {{{1, 2},   {1,  2},  {1, 2}},           2},
                {{{1, 2},   {2,  3}},                    0},
                {{{1, 100}, {11, 22}, {1, 11}, {2, 12}}, 2},
        };
        runUnitTest("110 : 435. Non-overlapping Intervals", tests, [&](auto input) {
            return this->eraseOverlapIntervals(input);
        });
    }
};
