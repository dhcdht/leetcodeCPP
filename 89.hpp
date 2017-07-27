// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/#/description
// 363. Max Sum of Rectangle No Larger Than K
/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
 */
#import <iostream>

class Solution89 {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }

        auto rowCount = matrix.size();
        auto colCount = matrix[0].size();

        auto result = INT32_MIN;
        auto curRowMax = INT32_MIN;

        for (int l = 0; l < colCount; ++l) {
            vector<int> sums(rowCount, 0);
            for (int r = l; r < colCount; ++r) {
                for (int i = 0; i < rowCount; ++i) {
                    sums[i] += matrix[i][r];
                }

                curRowMax = this->maxSumSubarray(sums, k);
                result = max(result, curRowMax);
            }
        }

        return result;
    }

//    int maxSumSubarray(vector<int> &array, int k, int left, int right, int curSum) {
//        auto rightMax = INT32_MIN;
//        if (right < array.size() - 1) {
//            rightMax = maxSumSubarray(array, k, left, right + 1, curSum + array[right + 1]);
//        }
//
//        auto leftMax = INT32_MIN;
//        if (left < right) {
//            leftMax = maxSumSubarray(array, k, left + 1, right, curSum - array[left]);
//        }
//
//        if (curSum > k) {
//            curSum = INT32_MIN;
//        }
//        if (rightMax <= k && rightMax > curSum) {
//            curSum = rightMax;
//        }
//        if (leftMax <= k && leftMax > curSum) {
//            curSum = leftMax;
//        }
//
//        return curSum;
//    }

    int maxSumSubarray(vector<int> &array, int k) {
        // Find the max subarray no more than K
        set<int> accuSet;
        accuSet.insert(0);
        int curSum = 0, curMax = INT_MIN;
        for (int sum : array) {
            curSum += sum;
            set<int>::iterator it = accuSet.lower_bound(curSum - k);
            if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
            accuSet.insert(curSum);
        }

        return curMax;
    }

    void test() {
        // -1
//        vector<vector<int>> matrix = {{2, 2, -1}};
//        int k = 0;
        // 8
        vector<vector<int>> matrix = {{5,  -4, -3, 4},
                                      {-3, -4, 4,  5},
                                      {5,  1,  5,  -4}};
        int k = 8;

        auto result = this->maxSumSubmatrix(matrix, k);
        cout << "363. Max Sum of Rectangle No Larger Than K : " << result << endl;
    }
};
