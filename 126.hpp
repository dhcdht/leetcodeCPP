// https://leetcode.com/problems/couples-holding-hands/description/
// 765. Couples Holding Hands
/*
N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.
 */
#import <iostream>
#import "helper.hpp"

class Solution126 {
public:
    int minSwapsCouples(vector<int> &row) {
        map<int, int> indexMap;
        for (int i = 0; i < row.size(); ++i) {
            indexMap[row[i]] = i;
        }

        int result = 0;
        for (int i = 0; i < row.size() / 2; ++i) {
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;
            int leftNum = row[leftIndex];
            int rightNum = row[rightIndex];

            int leftCupNum = this->cupNum(leftNum);
            if (leftCupNum == rightNum) {
                continue;
            }

            int leftCupNumIndex = indexMap[leftCupNum];
            int leftCupNumCupIndex = this->cupIndex(leftCupNumIndex);
            if (row[leftCupNumCupIndex] == this->cupNum(rightNum)) {
                row[rightIndex] = leftCupNum;
                row[leftCupNumIndex] = rightNum;
                indexMap[rightNum] = leftCupNumIndex;
                result += 1;

                continue;
            }

            row[rightIndex] = leftCupNum;
            row[leftCupNumIndex] = rightNum;
            indexMap[rightNum] = leftCupNumIndex;
            result += 1;
        }

        return result;
    }

    int cupNum(int num) {
        if (num % 2 == 1) {
            return num - 1;
        } else {
            return num + 1;
        }
    }

    int cupIndex(int index) {
        return this->cupNum(index);
    }

    void test() {
        typedef vector<int> Input;
        vector<pair<Input, int>> tests = {
                {{0,  2, 1, 3},                          1},
                {{3,  2, 0, 1},                          0},
                {{0,  2, 4, 6, 7, 1, 3, 5},              3},
                {{10, 7, 4, 2, 3, 0, 9, 11, 1, 5, 6, 8}, 4},
        };
        runUnitTest("126 : 765. Couples Holding Hands", tests, [&](Input input) {
            return this->minSwapsCouples(input);
        });
    }
};

