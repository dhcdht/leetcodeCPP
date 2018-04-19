// https://leetcode.com/problems/max-chunks-to-make-sorted/description/
// 769. Max Chunks To Make Sorted
/*
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
 */
#import <iostream>
#import "helper.hpp"

class Solution108 {
public:
    int maxChunksToSorted(vector<int> &arr) {
        if (arr.size() <= 1) {
            return arr.size();
        }

        int chunkEndIndex = 0;
        int maxChunk = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > arr[chunkEndIndex]) {
                chunkEndIndex = i;
            } else if (i >= arr[chunkEndIndex]) {
                maxChunk += 1;
                chunkEndIndex = i + 1;
            }
        }

        return maxChunk;
    }

    void test() {
        vector<pair<vector<int>, int>> tests = {
                {{4, 3, 2, 1, 0}, 1},
                {{1, 0, 2, 3, 4}, 4},
                {{1, 2, 0, 3},    2},
        };
        runUnitTest("108 : 769. Max Chunks To Make Sorted", tests, [&](auto input) {
            return this->maxChunksToSorted(input);
        });
    }
};
