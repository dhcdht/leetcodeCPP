// https://leetcode.com/problems/next-greater-element-ii/#/description
// 503. Next Greater Element II
/*
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.
 */
#import <iostream>
#import <vector>
#import <stack>

using namespace std;

class Solution43 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        auto n = nums.size();
        auto result = vector<int>(n, -1);

        auto lastIndexs = stack<int>();
        for (int i = 0; i < n * 2; ++i) {
            int curNum = nums[i % n];

            while (!lastIndexs.empty()) {
                int lastIndex = lastIndexs.top();
                if (nums[lastIndex] < curNum) {
                    result[lastIndex] = curNum;
                    lastIndexs.pop();
                } else {
                    break;
                }
            }

            if (i < n) {
                lastIndexs.push(i);
            }
        }

        return result;
    }

    void test() {
//        auto input = vector<int>({1, 2, 1});
//        auto input = vector<int>({5, 4, 3, 2, 1});
//        auto input = vector<int>({1, 5, 3, 6, 8});
        auto input = vector<int>({100,1,11,1,120,111,123,1,-1,-100});
        auto result = this->nextGreaterElements(input);
        cout << "503. Next Greater Element II : ";
        for (auto num : result) {
            cout << num << ", ";
        }
        cout << endl;
    }
};
