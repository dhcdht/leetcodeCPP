// https://leetcode.com/problems/poor-pigs/description/
// 458. Poor Pigs
/*
There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
 */
#import <iostream>

class Solution113 {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie;
        int attempts = times + 1;
        int result = (int) ceil(log(buckets) / log(attempts));

        return result;
    }

    void test() {

    }
};
