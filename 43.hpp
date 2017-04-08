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
#import <list>

using namespace std;

class Solution43 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        auto n = nums.size();
        if (n <= 1) {
            return vector<int>(n, -1);
        }

        auto result = vector<int>(n, INT_MIN);

        auto notFoundGreaterIndexs = list<int>();
        int lastNum = nums[n - 1];
        int maxNum = lastNum;
        notFoundGreaterIndexs.push_back(n - 1);
        for (int i = n-2; i >= 0; --i) {
            int curNum = nums[i];
            if (curNum < lastNum) {
                result[i] = lastNum;
                lastNum = curNum;
            } else if (curNum == lastNum) {
                int nextIndex = (i + 1) % n;
                if (result[nextIndex] != INT_MIN) {
                    result[i] = result[nextIndex];
                } else {
                    notFoundGreaterIndexs.push_back(i);
                }
            } else {
                lastNum = curNum;
                notFoundGreaterIndexs.push_back(i);
                if (lastNum > maxNum) {
                    maxNum = lastNum;
                }
            }
        }

        while (!notFoundGreaterIndexs.empty()) {
            int baseIndex = notFoundGreaterIndexs.back();
            int baseNum = nums[baseIndex];

            if (baseNum == maxNum) {
                result[baseIndex] = -1;
                notFoundGreaterIndexs.pop_back();
                continue;
            }

            for (int i = 1; i < n; ++i) {
                int curIndex = (baseIndex + i) % n;
                int curNum = nums[curIndex];
                int curGreater = result[curIndex];

                if (curNum > baseNum) {
                    result[baseIndex] = curNum;
                    notFoundGreaterIndexs.pop_back();
                    break;
                } else if (curGreater > baseNum) {
                    result[baseIndex] = curGreater;
                    notFoundGreaterIndexs.pop_back();
                    break;
                }
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
