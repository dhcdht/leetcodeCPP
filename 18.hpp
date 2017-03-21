// https://leetcode.com/problems/beautiful-arrangement/#/description
// 526. Beautiful Arrangement
/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation:

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
 */
#import <iostream>

using namespace std;

class Solution18 {
public:
    int countArrangement(int N) {
        int result = 0;

        auto nums = vector<int>();
        for (int i = 0; i < N; ++i) {
            nums.push_back(i+1);
        }

        result = this->counts(N, nums);

        return result;
    }

    int counts(int n, vector<int> nums) {
        if (n <= 0) {
            return 1;
        }

        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % n == 0
                || n % nums[i] == 0) {
                swap(nums[i], nums[n - 1]);
                result += this->counts(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }

        return result;
    }

    void test() {
        int input = 2;
        int result = this->countArrangement(2);
        cout << "526. Beautiful Arrangement : " << result << endl;
    }
};
