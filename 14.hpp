// https://leetcode.com/problems/arithmetic-slices/#/description
// 413. Arithmetic Slices
/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 */
#import <iostream>
#import <vector>

using namespace std;

class Solution14 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;

        auto countV = vector<int>();
        int curIncrease = 0;
        int curCount = 0;
        int lastNum;
        if (!A.empty()) {
            lastNum = A[0];
        }
        for_each(A.begin(), A.end(), [&](int num) {
            int increase = num - lastNum;
            if (increase == curIncrease) {
                curCount += 1;
            } else {
                if (curCount >= 3) {
                    countV.push_back(curCount);
                }

                curIncrease = increase;
                curCount = 2;
            }

            lastNum = num;
        });
        if (curCount >= 3) {
            countV.push_back(curCount);
        }

        for_each(countV.begin(), countV.end(), [&](int num) {
            int height = num - 3 + 1;
            int count = (height * (height + 1)) / 2;
            result += count;
        });


        return result;
    }

    void test() {
        auto input = vector<int>({1, 2, 3, 4});
        auto result = this->numberOfArithmeticSlices(input);
        cout << "413. Arithmetic Slices : " << result << endl;
    }
};
