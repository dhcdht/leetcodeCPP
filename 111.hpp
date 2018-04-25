// https://leetcode.com/problems/find-k-closest-elements/description/
// 658. Find K Closest Elements
/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
 */
#import <iostream>
#import "helper.hpp"
#import <tuple>

class Solution111 {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        vector<int> result;
        if (arr.empty()) {
            return result;
        }

        int lastMaxDiff = INT_MAX;
        int leftIndex = 0;
        int rightIndex = std::min((int)(k - 1), (int)(arr.size() - 1));
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] -= x;
            if (i > rightIndex) {
                if (abs(arr[i]) < abs(arr[leftIndex])) {
                    rightIndex = i;
                    if (rightIndex - leftIndex >= k) {
                        leftIndex = rightIndex - (k - 1);
                    }
                }
            }
        }

        for (int i = leftIndex; i <= rightIndex; ++i) {
            result.push_back(arr[i] + x);
        }

        return result;
    }

    void test() {
        typedef tuple<vector<int>, int, int> Inputs;
        typedef vector<int> Outputs;
        vector<pair<Inputs, Outputs>> tests = {
                {{{1, 2, 3, 4, 5},                4, 3},  {1, 2, 3, 4}},
                {{{1, 2, 3, 4, 5},                4, -1}, {1, 2, 3, 4}},
                {{{0, 0, 1, 2, 3, 3, 4, 7, 7, 8}, 3, 5},  {3, 3, 4}},
                {{{0, 0, 0, 1, 3, 5, 6, 7, 8, 8}, 2, 2},  {1, 3}},
        };
        runUnitTest("111 : 658. Find K Closest Elements", tests, [&](Inputs input) {
            return this->findClosestElements(std::get<0>(input), std::get<1>(input), std::get<2>(input));
        });
    }
};
