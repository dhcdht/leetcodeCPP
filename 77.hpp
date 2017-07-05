// https://leetcode.com/problems/can-place-flowers/#/description
// 605. Can Place Flowers
/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.

 */
#import <iostream>

class Solution77 {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        auto placeCount = 0;
        auto zeroCounter = 1;
        for (auto item : flowerbed) {
            if (item == 0) {
                zeroCounter += 1;
                if (zeroCounter == 3) {
                    placeCount += 1;
                    zeroCounter = 1;
                }
            } else {
                zeroCounter = 0;
            }
        }
        if (zeroCounter == 2) {
            placeCount += 1;
        }
        if (zeroCounter == 1 && flowerbed.size() == 1) {
            placeCount += 1;
        }

        return placeCount >= n;
    }

    void test() {

    }
};
